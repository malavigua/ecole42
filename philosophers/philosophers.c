/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 10:50:30 by malmany           #+#    #+#             */
/*   Updated: 2026/02/22 10:50:33 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

t_table	*create_table(int argc, char **argv)
{
	t_table	*table;
	int		i;

	i = 0;
	table = malloc(sizeof(t_table));
	if (!table)
		return (printf("malloc error table\n"), NULL);
	table->nb_of_philosophers = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		table->nb_times_philo_must_eat = ft_atoi(argv[5]);
	else
		table->nb_times_philo_must_eat = -1;
	table->forks = malloc(table->nb_of_philosophers * sizeof(pthread_mutex_t));
	if (!table->forks)
		return (free(table), printf("malloc error forks\n"), NULL);
	while (i < table->nb_of_philosophers)
	{	
		pthread_mutex_init(&table->forks[i], NULL);
		i++;
	}
	return (table);
}

long	get_time_in_ms(void)
{
	struct timeval	tv;
	gettimeofday(&tv, NULL);
	return(tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

t_philosopher	*create_philosopher(int num, t_table *t)
{
	t_philosopher	*philo;
	struct timeval	tv;

	philo = malloc(sizeof(t_philosopher));
	if (!philo)
		return (NULL);
	philo->num = num;
	philo->state = THINKING;
	philo->nb_time_eaten = 0;
	gettimeofday(&tv, NULL);
	philo->last_meal_time = get_time_in_ms();
	philo->left_fork = t->forks[num - 1];
	if (num == 1)
		philo->right_fork = t->forks[t->nb_of_philosophers -1];
	else
		philo->right_fork = t->forks[num - 2];
	philo->table = t;
	return (philo);
}

void	clear_philos(t_philosopher **philos)
{
	int	j;

	j = 0;
	while (philos[j])
	{
		free(philos[j]);
		j++;
	}
	free(philos);
}

bool	check_arg_and_create_table(int argc, char **argv, t_table **table)
{
	if (argc < 5 || argc > 6)
		return (printf("Wrong number of arguments\n"), false);
	if (!ft_is_all_num(argc - 1, argv + 1))
		return (printf("Wrong type of arguments\n"), false);
	*table = create_table(argc, argv);
	if (!*table)
		return (false);
	return (true);
}

void	clear_all(t_table *table, pthread_t *thread_philos,
			t_philosopher **philos)
{
	free(table->forks);
	free(table);
	clear_philos(philos);
	free(thread_philos);
}

int	main(int argc, char **argv)
{
	t_table			*table;
	int				i;
	pthread_t		*thread_philos;
	t_philosopher	**philos;
	int				ret;

	i = 0;
	if (!check_arg_and_create_table(argc, argv, &table))
		return (1);
	if (table->nb_of_philosophers == 0 || table->nb_times_philo_must_eat == 0)
		return (free(table->forks), free(table), 0);
	if (table -> nb_of_philosophers == 1)
		return (usleep(table->time_to_die * 1000), free(table->forks),
			free(table), 0);
	thread_philos = malloc(table->nb_of_philosophers * sizeof(t_philosopher));
	if (!thread_philos)
		return (free(table->forks), free(table), 1);
	philos = malloc(table->nb_of_philosophers * sizeof(t_philosopher));
	if (!philos)
		return (free(table->forks), free(table), free(thread_philos), 1);
	while (i < table->nb_of_philosophers)
	{
		philos[i] = create_philosopher(i + 1, table);
		ret = pthread_create (&thread_philos[i], NULL, routine,
				(void *) philos[i]);
		if (!philos[i] || ret != 0)
			return (clear_philos(philos), free(thread_philos),
				printf("Error creation philo\n"), 1);
		i++;
	}
	i = 0;
	while (i < table->nb_of_philosophers)
	{
		pthread_join(thread_philos[i], NULL);
		i++;
	}
	return (clear_all(table, thread_philos, philos), 0);
}
