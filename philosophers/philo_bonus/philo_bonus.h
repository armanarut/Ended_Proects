/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 01:32:59 by akazarya          #+#    #+#             */
/*   Updated: 2022/06/17 22:06:09 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>

typedef struct s_data
{
	int		num_phi;
	int		time_die;
	int		time_eat;
	int		time_sleep;
	int		times_eat;
	long	tim;
	int		id;
	sem_t	*sem;
	sem_t	*sem_print;
	sem_t	*sem_died;
	int		status;
	int		died;
	long	now;
	long	temp[2];
	int		*pid;
}			t_data;

void	phillasophers(t_data *data);

//utils
int		ft_atoi(const char *str);
int		write_error(char *str);
long	get_time(void);

#endif
