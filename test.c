#include <stdint.h>
#include <stdio.h>
#include "./skynet_timer.h"

static void on_timer(void *data)
{
	uint64_t d = (uint64_t)data;
	printf("%s: d = %lu\n", __FUNCTION__, d);
}

int main(int argc, char *argv[])
{
	skynet_timer_init();
	/* uint32_t data = 100; */
	/* skynet_timeout(1, on_timer, &data, sizeof(uint32_t)); */
	/* for (uint32_t i = 0; i < 3; ++i) */
	/* { */
	/* 	uint32_t start = 1 << (i * 10); */
	/* 	uint32_t end = i << (i * 10 + 12); */
	/* 	for (uint32_t j = start; j <= end; ++j) */
	/* 	{ */
	/* 		skynet_timeout(j, on_timer, &j, sizeof(uint32_t)); */
	/* 	} */
	/* } */

	for (uint64_t j = 0; j <= 100000; ++j)
	{
		skynet_timeout(j, on_timer, (void *)j, sizeof(uint64_t));
	}


	test_updatetime(10);
	return 0;
}

