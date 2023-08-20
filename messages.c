/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboubour <cboubour@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:27:07 by cboubour          #+#    #+#             */
/*   Updated: 2022/12/06 18:59:33 by cboubour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static char	*get_msg(int msg)
{
	if (msg == MSG_FORK)
		return ("has taken a fork 🍴");
	if (msg == MSG_EAT)
		return ("is eating 🍝");
	if (msg == MSG_SLEEP)
		return ("is sleeping 🌙");
	if (msg == MSG_THINK)
		return ("is thinking 💭");
	if (msg == MSG_DEAD)
		return ("died 💀");
	return ("Error");
}

void	print_msg(t_philo *philo, int msg)
{
	size_t	t;

	t = get_time() - philo->tab->init_time;
	pthread_mutex_lock(&philo->tab->print);
	if (!philo->tab->dead && !philo->tab->eaten_all)
	{
		printf("%ldms %d ", t, philo->id);
		printf("%s", get_msg(msg));
		if (msg == MSG_EAT)
			printf(" | %d", philo->eat_count);
		printf("\n");
	}
	pthread_mutex_unlock(&philo->tab->print);
}
