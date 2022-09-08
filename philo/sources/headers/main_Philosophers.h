/* This file was automatically generated.  Do not edit! */
#undef INTERFACE
void		clean_exit(t_philo *philos, pthread_t *threads, int len,
				t_g_params *params);
void		check_death(t_philo *philo, unsigned long start);
t_philo		*initiate_philosophers(t_g_params *params, pthread_t *threads);
t_g_params	initiate_parameters(int argc, char **argv);
int			set_global_mutexes(t_g_params *params);
int			check_params(t_g_params *p);
int			routine_think(t_philo *philo, unsigned long start);
int			routine_sleep(t_philo *philo, unsigned long start);
int			routine_eat(t_philo *philo, unsigned long start, int *finished,
				int i);
int			routine_take_fork(t_philo *philo, int fork, unsigned long start);
void		*routine(void *bridge);
