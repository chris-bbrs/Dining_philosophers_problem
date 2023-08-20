/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboubour <cboubour@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:27:15 by cboubour          #+#    #+#             */
/*   Updated: 2023/01/21 23:38:26 by cboubour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				id;
	int				eat_count;
	size_t			last_eat;
	pthread_mutex_t	fork;
	struct s_philo	*r_philo;
	struct s_philo	*l_philo;
	struct s_table	*tab;
}	t_philo;

typedef struct s_table
{
	int				die_timer;
	int				eat_time;
	int				sleep_time;
	int				eat_max;
	int				philos_num;
	int				eaten_all;
	int				dead;
	size_t			init_time;
	t_philo			*philos;
	pthread_mutex_t	print;
	pthread_mutex_t	check;
}	t_table;

enum e_msg
{
	MSG_FORK = 0,
	MSG_EAT,
	MSG_SLEEP,
	MSG_THINK,
	MSG_DEAD
};

int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
int		ft_putnbr_fd(int n, int fd);
int		handle_args(int argc, char *argv[], t_table *tab);
void	print_msg(t_philo *philo, int msg);
void	*actions(void *arg);
void	check_dead(t_table *tab);
void	exit_philo(t_table *tab, pthread_t *thread_id);
size_t	get_time(void);
void	ft_wait(t_table *tab, size_t t_slp);

#endif
