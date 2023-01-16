/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 22:15:56 by akazarya          #+#    #+#             */
/*   Updated: 2022/06/13 22:17:52 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	exit_prog(t_data *data)
{
	int		ret;

	data->id = -1;
	while (++(data->id) < data->num_phi)
	{
		waitpid(-1, &ret, 0);
		if (ret != 0)
		{
			data->id = -1;
			while (++(data->id) < data->num_phi)
				kill(data->pid[data->id], 15);
			break ;
		}
	}
	free(data->pid);
	sem_close(data->sem);
	sem_close(data->sem_print);
	sem_close(data->sem_died);
	sem_unlink("/sem");
	sem_unlink("/sem_print");
	sem_unlink("/sem_died");
}

void	get_sem(t_data *data)
{
	sem_unlink("/sem");
	sem_unlink("/sem_print");
	sem_unlink("/sem_died");
	data->sem = sem_open("/sem", O_CREAT, 0644, data->num_phi);
	data->sem_print = sem_open("/sem_print", O_CREAT, 0644, 1);
	data->sem_died = sem_open("/sem_died", O_CREAT, 0644, 1);
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
	data->id = -1;
	get_sem(data);
	if (data->num_phi < 0 || data->time_die <= 0 || data->time_eat <= 0
		|| data->time_sleep < 0 || data->times_eat == -1
		|| data->times_eat == 0)
		return (1);
	data->pid = malloc(sizeof(int) * data->num_phi);
	if (!data->pid)
		return (1);
	return (0);
}

int	main(int argv, char **argc)
{
	t_data		data[1];

	if ((argv != 5 && argv != 6) || get_argc(data, argc))
		return (write_error("Invalid arguments\n"));
	while (++(data->id) < data->num_phi)
	{
		data->pid[data->id] = fork();
		if (data->pid[data->id] == -1)
			return (write_error("Error while creating forks\n"));
		if (data->pid[data->id] == 0)
			phillasophers(data);
	}
	exit_prog(data);
	return (0);
}
