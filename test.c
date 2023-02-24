
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

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
	pthread_t   th[5];
	int i = 0;
	pthread_mutex_init(&mut, NULL);
	while (i < 5)
	{
		pthread_create(&th[i], NULL, &routine, NULL);
		pthread_join(th[i], NULL);
		i++;
	}
	pthread_mutex_destroy(&mut);
	printf("nbr of mails = %u\n", mails);
	return (0);
}


