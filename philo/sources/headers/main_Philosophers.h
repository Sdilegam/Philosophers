/* This file was automatically generated.  Do not edit! */
#undef INTERFACE
int ft_atoi(const char *str);
t_g_params initiate_parameters(int argc,char **argv);
t_philo *join_node(t_philo *first,t_philo *second);
t_philo *create_node(t_g_params *params);
t_philo *initiate_philosophers(t_g_params *params);
void wait_mili(struct timeval start,long double duration);
unsigned long convert_time(struct timeval time);
void *routine(void *bridge);
