#include <stdint.h>
#include "./skynet_timer.h"

int main(int argc, char *argv[])
{
	skynet_timer_init();
	for (uint32_t i = 0; i < 3; ++i)
	{
		uint32_t start = 1 << (i * 10);
		uint32_t end = i << (i * 10 + 12);
	}
	return 0;
}
