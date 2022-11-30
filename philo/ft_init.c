/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtorun <mtorun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 02:35:32 by mtorun            #+#    #+#             */
/*   Updated: 2022/11/19 23:08:19 by mtorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	init_mutex(t_ins *ins)
{
	size_t	i;

	if (pthread_mutex_init(&ins->write_mutex, NULL))
		return (1);
	if (pthread_mutex_init(&ins->die_mutex, NULL))
		return (1);
	if (pthread_mutex_init(&ins->meals_mutex, NULL))
		return (1);
	ins->frk_mutex = malloc(sizeof(pthread_mutex_t) * ins->amount);
	if (!ins->frk_mutex)
		return (1);
	i = -1;
	while (++i < ins->amount)
		if (pthread_mutex_init(&ins->frk_mutex[i], NULL))
			return (1);
	return (0);
}

static void	init_philo(t_ins *ins)
{
	size_t	i;

	i = -1;
	while (++i < ins->amount)
	{
		ins->philo[i].who = i + 1;
		ins->philo[i].l_fork = i;
		ins->philo[i].r_fork = (i + 1) % ins->amount;
		ins->philo[i].eating = 0;
		ins->philo[i].last_meal = 0;
		ins->philo[i].f_time = get_time();
		ins->philo[i].ins = ins;
		ins->philo[i].meals = 0;
		ins->death = 0;
	}
}

int	init_arg(t_ins *ins, int ac, char **av)
{
	if (ac < 5 || ac > 6)
		return (1);
	ins->amount = ft_atoi(av[1]);
	ins->tt_die = ft_atoi(av[2]);
	ins->tt_eat = ft_atoi(av[3]);
	ins->tt_sleep = ft_atoi(av[4]);
	if (ac == 6)
		ins->meals = ft_atoi(av[5]);
	else
		ins->meals = -1;
	if (!ins->amount || !ins->meals || !ins->tt_die || !ins->tt_eat \
	|| !ins->tt_sleep)
		return (1);
	if (ins->amount < 1)
		return (1);
	ins->philo = malloc(sizeof(t_philo) * ins->amount);
	if (!ins->philo)
		return (1);
	init_philo(ins);
	if (init_mutex(ins))
		return (1);
	return (0);
}
