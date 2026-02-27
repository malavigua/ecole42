/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 09:40:39 by malmany           #+#    #+#             */
/*   Updated: 2026/02/22 09:41:42 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <sys/time.h>
# include <pthread.h>
# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

//struct
typedef enum e_state
{
	THINKING,
	EATING,
	SLEEPING
}	t_state;

typedef struct s_philosopher
{
	int				num;
	t_state			state;
	long			last_meal_time;
	int				nb_time_eaten;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	right_fork;
}	t_philosopher;

typedef struct s_table
{
	int				nb_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_times_philo_must_eat;
	pthread_mutex_t	*forks;
}	t_table;

//libft _func
int		ft_atoi(const char *nptr);

//
bool	ft_is_number_pos(char *c);
bool	ft_is_all_num(int nb_args, char **args);
#endif
