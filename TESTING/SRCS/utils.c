#include "../thread.h"

int	rand_int(int max)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	return (time.tv_usec % max + 1);
}
