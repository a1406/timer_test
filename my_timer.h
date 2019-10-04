#ifndef SKYNET_TIMER_H
#define SKYNET_TIMER_H

#include <stdint.h>

typedef void (*callback_func)(void *data);
int skynet_timeout(int time, callback_func fun, void *data, int sz);
void skynet_updatetime(void);
uint32_t skynet_starttime(void);
uint64_t skynet_thread_time(void);	// for profile, in micro second

void skynet_timer_init(void);
void test_updatetime(uint32_t num);


#endif
