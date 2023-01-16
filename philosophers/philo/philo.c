/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 01:31:51 by akazarya          #+#    #+#             */
/*   Updated: 2022/06/16 00:09:18 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_fork(t_data *data, int id)
{
	pthread_mutex_lock(&data->mutex);
	if (id + 1 < data->num_phi)
	{
		data->philo[id].fork ^= 1;
		data->philo[id + 1].fork ^= 1;
	}
	else
	{
		data->philo[id].fork ^= 1;
		data->philo[0].fork ^= 1;
	}
	pthread_mutex_unlock(&data->mutex);
	return (1);
}

int	check_forks(t_data *data, int id)
{
	pthread_mutex_lock(&data->mutex_check);
	if (id + 1 < data->num_phi)
	{
		if (data->philo[id].fork && data->philo[id + 1].fork)
		{
			get_fork(data, id);
			pthread_mutex_unlock(&data->mutex_check);
			return (1);
		}
	}
	else if (id)
	{
		if (data->philo[id].fork && data->philo[0].fork)
		{
			get_fork(data, id);
			pthread_mutex_unlock(&data->mutex_check);
			return (1);
		}
	}
	pthread_mutex_unlock(&data->mutex_check);
	return (0);
}

void	philo_eat(t_data *data, int id, long *temp)
{
	temp[1] = td(data, 0);
	data->philo[id].status = 1;
	philo_say(temp[1], id, data, "has taken a fork");
	philo_say(temp[1], id, data, "has taken a fork");
	philo_say(temp[1], id, data, "is eating");
}

void	philo_make(t_data *data, int id, long *temp)
{
	if (td(data, temp[1]) >= data->time_die)
	{
		pthread_mutex_lock(&data->mutex);
		philo_say(td(data, 0), id, data, "died");
		data->end = 0;
		pthread_mutex_unlock(&data->mutex);
	}
	else if ((data->philo[id].status == 0 || data->philo[id].status == 3)
		&& check_forks(data, id))
		philo_eat(data, id, temp);
	else if (data->philo[id].status == 2
		&& td(data, temp[0]) >= data->time_sleep)
	{
		philo_say(td(data, 0), id, data, "is thinking");
		data->philo[id].status = 3;
	}
	else if (data->philo[id].status == 1 && td(data, temp[1]) >= data->time_eat)
	{
		get_fork(data, id);
		if (data->philo[id].times_eat != -2 && !(--data->philo[id].times_eat))
			return ;
		temp[0] = td(data, 0);
		philo_say(temp[0], id, data, "is sleeping");
		data->philo[id].status = 2;
	}
}

void	*phillasophers(void *data_in)
{
	t_data	*data;
	int		id;
	long	temp[2];

	data = data_in;
	id = data->id;
	data->philo[id].fork = 1;
	data->philo[id].status = 0;
	data->philo[id].times_eat = data->times_eat;
	while (data->start)
		;
	temp[0] = td(data, 0);
	temp[1] = td(data, 0);
	usleep(id * 150);
	while (data->end && data->philo[id].times_eat)
		philo_make(data, id, temp);
	return (0);
}
