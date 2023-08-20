/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboubour <cboubour@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:27:01 by cboubour          #+#    #+#             */
/*   Updated: 2022/12/05 22:20:55 by cboubour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	arg_invalid(void)
{
	printf("Usage: ./philo <number of philosophers> <time to die> "
		"<time to eat> <time to sleep> [times they can eat]\n");
	return (1);
}

static void	main_thread(t_table *tab, pthread_t *tid)
{
	check_dead(tab);
	exit_philo(tab, tid);
}

int	main(int argc, char **argv)
{
	int			i;
	t_table		tab;
	pthread_t	*thread_id;

	if ((argc < 5 || argc > 6) || handle_args(argc, argv, &tab))
		return (arg_invalid());
	thread_id = (pthread_t *)malloc(tab.philos_num * sizeof(pthread_t));
	tab.init_time = get_time();
	i = -1;
	while (++i < tab.philos_num)
	{
		if (pthread_create(&thread_id[i], NULL, &actions, &tab.philos[i]))
		{
			free(tab.philos);
			free(thread_id);
			return (1);
		}
		pthread_mutex_lock(&tab.check);
		tab.philos[i].last_eat = tab.init_time;
		pthread_mutex_unlock(&tab.check);
	}
	main_thread(&tab, thread_id);
	return (EXIT_SUCCESS);
}
