/* This file was automatically generated.  Do not edit! */
#undef INTERFACE
int				set_global_mutexes(t_g_params *params);
t_philo			*join_node(t_philo *first, t_philo *second);
t_philo			*create_node(t_g_params *params);
t_philo			*initiate_philosophers(t_g_params *params, pthread_t *threads);
void			clean_all(t_philo *philos, pthread_t *threads, int len,
					t_g_params *params);
int				allocate_init_mutexes(t_philo *ph, t_philo *cursor,
					pthread_t *th, int i);
int				ft_atoi(const char *str);
unsigned long	convert_time(struct timeval time);
t_g_params		initiate_parameters(int argc, char **argv);
