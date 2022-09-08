/* This file was automatically generated.  Do not edit! */
#undef INTERFACE
void clean_exit(t_philo *philos,pthread_t *threads,int len,t_params *params);
void join_threads(pthread_t *threads,int n_philos);
void check_death(t_philo *philo,unsigned long start);
void create_threads(pthread_t *threads,t_philo *philosopher,int n_philos);
t_philo *initiate_philosophers(t_params *params,pthread_t *threads);
int check_params(t_params *p);
t_params initiate_parameters(int argc,char **argv);
int routine_think(t_philo *philo,unsigned long start);
int routine_sleep(t_philo *philo,unsigned long start);
int routine_eat(t_philo *philo,unsigned long start,int *finished,int i);
int routine_take_fork(t_philo *philo,int fork,unsigned long start);
void *routine(void *bridge);
