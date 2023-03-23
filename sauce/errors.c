#include "philo.h"

int	error_handling(int argc, char **argv, t_main *main)
{
	
	if (init_input_struct(argc, argv, main) == 0)
	{
		printf("%s\n", NUM_ARGS);
		return (0);
	}
	else
	{
		print_args_errors(main, argc);
		if (!main->input.num_philo || !main->input.time_to_die
			|| !main->input.time_to_eat || !main->input.time_to_sleep
			|| (argc == 6 && !main->input.num_of_times_eat))
			return (0);
	}
	return (1);
}

int	init_input_struct(int argc, char **argv, t_main *main)
{
	if (argc == 5 || argc == 6)
	{
		main->input.num_philo = ft_atoi(argv[1]);
		main->input.time_to_die = ft_atoi(argv[2]);
		main->input.time_to_eat = ft_atoi(argv[3]);
		main->input.time_to_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			main->input.num_of_times_eat = ft_atoi(argv[5]);
		else
			main->input.num_of_times_eat = -1;
		return (1);
	}
	return (0);
}

void	print_args_errors(t_main *main, int argc)
{
	if (!main->input.num_philo)
		printf("%s\n", ARG);
	if (!main->input.time_to_die)
		printf("%s\n", ARG);
	if (!main->input.time_to_eat)
		printf("%s\n", ARG);
	if (!main->input.time_to_sleep)
		printf("%s\n", ARG);
	if (argc == 6 && !main->input.num_of_times_eat)
		printf("%s\n", ARG);
}

int	ft_atoi(char *str)
{
	int			i;
	long int	n;

	i = 0;
	n = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + str[i] - '0';
		i++;
	}
	if (n < 0 || ((str[i] < '0' || str[i] > '9') && str[i] != '\0')
		|| n > INT_MAX)
		return (0);
	return (n);
}

void	philo_free(t_main *main)
{
	free(main->philo);
	free(main->forks);
}
