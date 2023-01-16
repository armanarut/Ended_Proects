/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 01:32:00 by akazarya          #+#    #+#             */
/*   Updated: 2022/06/15 23:56:57 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	end_prog(t_data *data)
{
	free(data->philo);
	pthread_mutex_destroy(&data[0].mutex);
	pthread_mutex_destroy(&data[0].mutex_check);
	pthread_mutex_destroy(&data[0].mutex_print);
}

void	philo_say(long time, int id, t_data *data, char *str)
{
	pthread_mutex_lock(&data->mutex_print);
	if (data->end)
		printf("%-5ld %i %s\n", time, id + 1, str);
	pthread_mutex_unlock(&data->mutex_print);
}

int	get_argc(t_data *data, char **argc)
{
	data->num_phi = ft_atoi(argc[1]);
	data->time_die = ft_atoi(argc[2]);
	data->time_eat = ft_atoi(argc[3]);
	data->time_sleep = ft_atoi(argc[4]);
	if (argc[5])
		data->times_eat = ft_atoi(argc[5]);
	else
		data->times_eat = -2;
	pthread_mutex_init(&data[0].mutex, NULL);
	pthread_mutex_init(&data[0].mutex_check, NULL);
	pthread_mutex_init(&data[0].mutex_print, NULL);
	data->end = 1;
	data->id = -1;
	data->start = 1;
	if (data->num_phi < 0 || data->time_die <= 0 || data->time_eat <= 0
		|| data->time_sleep < 0 || data->times_eat == -1
		|| data->times_eat == 0)
		return (1);
	data->philo = malloc(sizeof(t_philo) * data->num_phi);
	if (!data->philo)
		return (1);
	return (0);
}

int	main(int argv, char **argc)
{
	t_data	data[1];

	if ((argv != 5 && argv != 6) || get_argc(data, argc))
		return (write_error("Invalid arguments\n"));
	while (++(data->id) < data->num_phi)
	{
		if (pthread_create(&data->philo[data->id].tid, NULL,
				phillasophers, (void*)data) < 0)
			return (write_error("Error while creating threads\n"));
		usleep(10000);
	}
	data->now = get_time();
	data->start = 0;
	data->id = -1;
	while (++(data->id) < data->num_phi)
		pthread_join(data->philo[data->id].tid, NULL);
	end_prog(data);
	return (0);
}
