
#include "philo.h"

unsigned int mails = 0;
pthread_mutex_t	mut;

void *routine()
{
	unsigned int i = 0;
	while (i++ < 10000000)
	{
		// pthread_mutex_lock(&mut);
		mails++;
		// pthread_mutex_unlock(&mut);
	}
	return (NULL);
}

int main()
{
	printf("%sThis is red text\n",AC_RED);
}


