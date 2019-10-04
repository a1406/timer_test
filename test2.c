#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "./my_timer.h"

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
	my_timer_init();
	for (uint32_t i = 0; i < 3; ++i)
	{
		uint32_t start = 1 << (i * 10);
		uint32_t end = 1 << (i * 10 + 12);
		check_index = start;
		for (uint64_t j = start; j <= end; ++j)
		{
			my_timeout(j, on_timer, (void *)j, sizeof(uint64_t));
		}
		test_updatetime(0xffffffff);
		printf("test pass %d\n", i + 1);
	}


	return 0;
}

