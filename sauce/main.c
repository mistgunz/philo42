/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnait-el <rnait-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 22:36:39 by rnait-el          #+#    #+#             */
/*   Updated: 2023/03/23 22:36:40 by rnait-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_main	main;

	if (error_handling(argc, argv, &main) == 0)
		return (1);
	if (create_philos(&main) == 0)
		return (1);
	if (create_forks(&main) == 0)
		return (1);
	if (main.input.num_philo == 1)
	{
		if (just_one_philo(&main) == 0)
			return (1);
		return (0);
	}
	if (create_threads(&main) == 0)
		return (1);
	if (destroy_threads(&main) == 0)
		return (1);
	philo_free(&main);
	return (0);
}

int	just_one_philo(t_main *main)
{
	if (pthread_mutex_init(&main->write, NULL) != 0)
		return (0);
	main->t0 = get_time();
	philo_print(main, 1, FORK);
	exec_action(main->input.time_to_die);
	philo_print(main, 1, DIED);
	philo_free(main);
	return (1);
}
