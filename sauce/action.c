#include "philo.h"

int	philo_eat(t_main *main, int i)
{
	if (pthread_mutex_lock(&main->forks[main->philo[i].fork.left]) != 0)
		return (0);
	if (philo_print(main, main->philo[i].id, FORK) == 0)
		return (0);
	if (pthread_mutex_lock(&main->forks[main->philo[i].fork.right]) != 0)
		return (0);
	if (philo_print(main, main->philo[i].id, FORK) == 0)
		return (0);
	if (philo_print(main, main->philo[i].id, EAT) == 0)
		return (0);
	main->philo[i].time_to_die = get_time();
	exec_action(main->input.time_to_eat);
	drop_forks(main, i);
	return (1);
}

int	philo_sleep(t_main *main, int i)
{
	if (philo_print(main, main->philo[i].id, SLEEP) == 0)
		return (0);
	exec_action(main->input.time_to_sleep);
	return (1);
}

int	philo_think(t_main *main, int i)
{
	if (philo_print(main, main->philo[i].id, THINK) == 0)
		return (0);
	return (1);
}

int	philo_is_dead(t_main *main, int *i)
{
	int	time;

	if (*i == main->input.num_philo)
		*i = 0;
	time = delta_time(main->philo[*i].time_to_die);
	if (time > main->input.time_to_die)
	{
		philo_print(main, main->philo[*i].id, DIED);
		main->philo_dead = 1;
		return (1);
	}
	i++;
	return (0);
}

int	drop_forks(t_main *main, int i)
{
	if (pthread_mutex_unlock(&main->forks[main->philo[i].fork.left]))
		return (0);
	if (pthread_mutex_unlock(&main->forks[main->philo[i].fork.right]))
		return (0);
	main->philo[i].num_of_times_ate++;
	return (1);
}