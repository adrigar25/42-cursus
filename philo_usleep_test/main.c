#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

#define TIME_US 2

typedef struct s_table
{
	int				sim_stop;
	pthread_mutex_t	sim_stop_lock;
}					t_table;

long	get_time(int unit)
{
	struct timeval	v;

	gettimeofday(&v, NULL);
	if (unit == TIME_US)
		return (v.tv_sec * 1000000L + v.tv_usec);
	return (v.tv_sec * 1000L + v.tv_usec / 1000L);
}

int	simulation_stopped(t_table *table)
{
	int	ret;

	ret = 0;
	if (!table)
		return (1);
	pthread_mutex_lock(&table->sim_stop_lock);
	if (table->sim_stop == 1)
		ret = 1;
	pthread_mutex_unlock(&table->sim_stop_lock);
	return (ret);
}

void	ft_usleep(long usec, t_table *table)
{
	long	start;

	start = get_time(TIME_US);
	while (get_time(TIME_US) - start < usec)
	{
		if (simulation_stopped(table))
			break ;
		usleep(1);
	}
}

int	main(void)
{
	t_table	table;
	long	durations[] = {1000L, 5000L, 10000L, 50000L, 100000L, 200000L,
			500000L, 1000000L};
	int		nd;
	int		iterations;
	long	req;
	long	t0;
	long	t1;
	long	elapsed;
	long	diff;
	double	pct;

	nd = sizeof(durations) / sizeof(durations[0]);
	int i, k;
	iterations = 5;
	table.sim_stop = 0;
	if (pthread_mutex_init(&table.sim_stop_lock, NULL) != 0)
	{
		perror("mutex_init");
		return (1);
	}
	printf("usleep test (ft_usleep)");
	printf(" - measuring requested vs actual sleep time\n");
	printf("iterations per duration: %d\n\n", iterations);
	for (i = 0; i < nd; i++)
	{
		req = durations[i];
		printf("Requested: %8ld us (%.3f ms)\n", req, req / 1000.0);
		for (k = 0; k < iterations; k++)
		{
			t0 = get_time(TIME_US);
			ft_usleep(req, &table);
			t1 = get_time(TIME_US);
			elapsed = t1 - t0;
			diff = elapsed - req;
			pct = (double)elapsed / (double)req * 100.0;
			printf("  iter %2d: elapsed %8ld us (%.3f ms),", k + 1, elapsed,
				elapsed / 1000.0);
			printf(" diff %+6ld us, %.2f%%\n", diff, pct);
		}
		printf("\n");
	}
	pthread_mutex_destroy(&table.sim_stop_lock);
	return (0);
}
