/* This file was automatically generated.  Do not edit! */
#undef INTERFACE
int ft_atoi(const char *str);
unsigned long convert_time(struct timeval time);
t_params initiate_parameters(int argc,char **argv);
void join_threads(pthread_t *threads,int n_philos);
void *routine(void *bridge);
void create_threads(pthread_t *threads,t_philo *philosopher,int n_philos);
int set_global_mutexes(t_params *params);
int check_params(t_params *p);
