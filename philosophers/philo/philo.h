/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 01:32:59 by akazarya          #+#    #+#             */
/*   Updated: 2022/06/10 01:35:16 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_philo
{
	pthread_t	tid;
	int			status;
	int			fork;
	int			times_eat;
}				t_philo;

typedef struct s_data
{
	int				num_phi;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				times_eat;
	int				id;
	int				end;
	long			now;
	pthread_mutex_t	mutex;
	pthread_mutex_t	mutex_print;
	pthread_mutex_t	mutex_check;
	int				start;
	t_philo			*philo;
}					t_data;

void	*phillasophers(void *data_in);
void	philo_say(long time, int id, t_data *data, char *str);

//utils
int		ft_atoi(const char *str);
int		write_error(char *str);
long	get_time(void);
long	td(t_data *data, long last);

#endif
