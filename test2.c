#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "./skynet_timer.h"

static uint64_t check_index = 0;
static void on_timer(void *data)
{
	uint64_t d = (uint64_t)data;
	if (d != check_index)
	{
		printf("%s: err, d = %lu, check = %lu\n", __FUNCTION__, d, check_index);
		exit(0);
	}
	++check_index;
}

int main(int argc, char *argv[])
{
	skynet_timer_init();
	/* uint32_t data = 100; */
	/* skynet_timeout(1, on_timer, &data, sizeof(uint32_t)); */
	for (uint32_t i = 0; i < 3; ++i)
	{
		uint32_t start = 1 << (i * 10);
		uint32_t end = 1 << (i * 10 + 12);
		check_index = start;
		for (uint64_t j = start; j <= end; ++j)
		{
			skynet_timeout(j, on_timer, (void *)j, sizeof(uint64_t));
		}
		test_updatetime(0xffffffff);
		printf("test pass %d\n", i + 1);
	}

	/* for (uint64_t j = 0; j <= 0xffff; ++j) */
	/* { */
	/* 	skynet_timeout(j, on_timer, (void *)j, sizeof(uint64_t)); */
	/* } */


	/* for (uint64_t j = 0; j <= 100000; ++j) */
	/* { */
	/* 	skynet_timeout(j, on_timer, (void *)j, sizeof(uint64_t)); */
	/* } */


	return 0;
}

/* test pass 1 */
/* test pass 2 */
/* test pass 3 */
/* 166.634 secs */
