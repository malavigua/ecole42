/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 18:52:24 by malmany           #+#    #+#             */
/*   Updated: 2026/02/25 18:52:29 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	take_forks(t_philosopher	*p)
{
	if (!(p->num % 2 == 0))
	{
		pthread_mutex_lock (&p->left_fork);
		printf("%ld %d has taken the left fork\n", get_time_in_ms(), p->num);
		pthread_mutex_unlock (&p->left_fork);
		pthread_mutex_lock (&p->right_fork);
		printf("%ld %d has taken the right fork\n", get_time_in_ms(), p->num);
		pthread_mutex_unlock (&p->right_fork);
	}
	else
	{
		pthread_mutex_lock (&p->right_fork);
		printf("%ld %d has taken the right fork\n", get_time_in_ms(), p->num);
		pthread_mutex_unlock (&p->right_fork);
		pthread_mutex_lock (&p->left_fork);
		printf("%ld %d has taken the left fork\n", get_time_in_ms(), p->num);
		pthread_mutex_unlock (&p->left_fork);
	}
}

static void	philo_eat(t_philosopher	*p)
{
	if (p->state != THINKING && 
	(p->table->nb_times_philo_must_eat != -1 &&	p->nb_time_eaten != p->table->nb_times_philo_must_eat))
		return ;
	take_forks(p);
	printf("%ld %d is eating\n", get_time_in_ms(), p->num);
	p->state = EATING;
	usleep(p->table->time_to_eat * 1000);
	p->last_meal_time = get_time_in_ms();
	p->nb_time_eaten++;
}

static void philo_sleep(t_philosopher	*p)
{
	if (p->state != EATING)
		return ;
	printf("%ld %d is sleeping\n", get_time_in_ms(), p->num);
	p->state = SLEEPING;
	usleep(p->table->time_to_sleep * 1000);
}

static void philo_think(t_philosopher	*p)
{
	if (p->state != SLEEPING)
		return ;
	printf("%ld %d is thinking\n", get_time_in_ms(), p->num);
	p->state = THINKING;
}

void	*routine(void *philo)
{
	t_philosopher	*p;

	p = (t_philosopher *) philo;
	printf("test %d\n", p->num);
	if(p->table->nb_times_philo_must_eat != -1)
	{
		while(p->nb_time_eaten != p->table->nb_times_philo_must_eat 
			&& p->state != DEAD)
		{
			philo_eat(p);
			philo_sleep(p);
			philo_think(p);
		}
	}
	else
	{
		while(p->state != DEAD)
		{
			philo_eat(p);
			philo_sleep(p);
			philo_think(p);
		}
	}
	return (NULL);
}
