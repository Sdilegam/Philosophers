/* This file was automatically generated.  Do not edit! */
#undef INTERFACE
void check_death(t_philo *philo,unsigned long start,pthread_t *threads);
int ft_atoi(const char *str);
unsigned long convert_time(struct timeval time);
t_g_params initiate_parameters(int argc,char **argv);
t_philo *join_node(t_philo *first,t_philo *second);
t_philo *create_node(t_g_params *params);
t_philo *initiate_philosophers(t_g_params *params);
void routine_think(t_philo *philo,unsigned long start);
void routine_sleep(t_philo *philo,unsigned long start);
void routine_eat(t_philo *philo,unsigned long start,int *finished,int i);
void routine_take_fork(t_philo *philo,int fork,unsigned long start);
void *routine(void *bridge);
