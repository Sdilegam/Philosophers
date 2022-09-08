/* This file was automatically generated.  Do not edit! */
#undef INTERFACE
int routine_think(t_philo *philo,unsigned long start);
int routine_sleep(t_philo *philo,unsigned long start);
void wait_mili(struct timeval start,long double duration);
int routine_eat(t_philo *philo,unsigned long start,int *finished,int i);
unsigned long convert_time(struct timeval time);
int routine_take_fork(t_philo *philo,int fork,unsigned long start);
void lock_fork(t_philo *philo,int fork);
