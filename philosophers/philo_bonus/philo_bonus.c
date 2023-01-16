/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 01:31:51 by akazarya          #+#    #+#             */
/*   Updated: 2022/06/17 22:06:18 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philo_say(long time, t_data *data, char *str)
{
	sem_wait(data->sem_print);
	if (!data->died)
		printf("%-5ld %i %s\n", time, data->id + 1, str);
	sem_post(data->sem_print);
}

void	*check_die(void *data1)
{
	t_data	*data;

	data = data1;
	while (1)
	{
		if (get_time() - data->now - data->temp[1] >= data->time_die)
		{
			sem_wait(data->sem_died);
			philo_say(get_time() - data->now, data, "died");
			data->died = 1;
			exit(1);
		}
		usleep(100);
	}
	return (0);
}

void	philo_eat(t_data *data)
{
	sem_wait(data->sem);
	philo_say(get_time() - data->now, data, "has taken a fork");
	sem_wait(data->sem);
	philo_say(get_time() - data->now, data, "has taken a fork");
	data->temp[1] = get_time() - data->now;
	philo_say(get_time() - data->now, data, "is eating");
	data->status = 1;
}

void	*philo_make(t_data *data)
{
	if (data->status == 0 || data->status == 3)
		philo_eat(data);
	else if (data->status == 0 || (data->status == 2
			&& get_time() - data->now - data->temp[0] >= data->time_sleep))
	{
		philo_say(get_time() - data->now, data, "is thinking");
		data->status = 3;
	}
	else if (data->status == 1
		&& get_time() - data->now - data->temp[1] >= data->time_eat)
	{
		data->temp[0] = get_time() - data->now;
		sem_post(data->sem);
		sem_post(data->sem);
		if (data->times_eat != -2 && !(--data->times_eat))
			exit(0);
		philo_say(get_time() - data->now, data, "is sleeping");
		data->status = 2;
	}
	return (0);
}

void	phillasophers(t_data *data)
{
	pthread_t	tid;

	data->status = 0;
	data->died = 0;
	data->now = get_time();
	data->temp[0] = get_time() - data->now;
	data->temp[1] = get_time() - data->now;
	if (data->id % 2 == 0)
		usleep(15000);
	pthread_create(&tid, NULL, check_die, (void *)data);
	while (!data->died)
		philo_make(data);
	exit(1);
}
