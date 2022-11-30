/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtorun <mtorun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 02:35:46 by mtorun            #+#    #+#             */
/*   Updated: 2022/11/20 01:03:18 by mtorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	control_philo(t_ins *ins)
{
	if (ins->amount == 1)
	{
		printf("%zu\t%zu has taken a fork\n", get_time() - ins->philo->f_time, \
			ins->philo->who);
		ft_usleep(ins->tt_die, ins);
		printf("%zu\t%zu died", get_time() - ins->philo->f_time, \
			ins->philo->who);
		return (1);
	}
	return (0);
}

size_t	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (((tv.tv_sec * 1000) + (tv.tv_usec / 1000)));
}

void	ft_usleep(size_t ms, t_ins *ins)
{
	size_t	end;

	end = get_time() + ms;
	while (get_time() < end)
	{
		usleep(100);
		pthread_mutex_lock(&ins->die_mutex);
		if (ins->death)
		{
			pthread_mutex_unlock(&ins->die_mutex);
			break ;
		}
		pthread_mutex_unlock(&ins->die_mutex);
	}
}

int	ft_atoi(const char *str)
{
	int	res;

	res = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+')
		str++;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			res = res * 10 + *str++ - '0';
		else
			return (0);
	}
	if (res >= __INT_MAX__)
		return (0);
	return (res);
}

void	ft_clear(t_ins *ins)
{
	if (ins->philo)
		free(ins->philo);
	pthread_mutex_destroy(&ins->write_mutex);
	pthread_mutex_destroy(ins->frk_mutex);
	pthread_mutex_destroy(&ins->die_mutex);
}
