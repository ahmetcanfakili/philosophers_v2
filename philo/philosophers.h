/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtorun <mtorun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 02:35:52 by mtorun            #+#    #+#             */
/*   Updated: 2022/11/19 23:08:19 by mtorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_philo
{
	size_t			who;
	size_t			l_fork;
	size_t			r_fork;
	size_t			eating;
	int				meals;
	size_t			last_meal;
	struct s_ins	*ins;
	pthread_t		th;
	size_t			f_time;
}	t_philo;

typedef struct s_ins
{
	size_t			amount;
	size_t			tt_eat;
	size_t			tt_die;
	size_t			tt_sleep;
	int				meals;
	size_t			death;
	t_philo			*philo;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	*frk_mutex;
	pthread_mutex_t	die_mutex;
	pthread_mutex_t	meals_mutex;
}	t_ins;

int		init_arg(t_ins *ins, int ac, char **av);
int		ft_atoi(const char *str);

int		control_philo(t_ins *ins);
size_t	get_time(void);
void	ft_usleep(size_t ms, t_ins *ins);

void	*routine(void *v_philo);
int		start_threads(t_ins *ins);

int		check_death(t_philo *philo);

int		ft_take_forks(t_philo *philo);
int		ft_eating(t_philo *philo);
int		ft_sleeping(t_philo *philo);

void	ft_clear(t_ins *ins);

#endif //PHILOSOPHERS_H