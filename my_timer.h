#ifndef MY_TIMER_H
#define MY_TIMER_H

#include <stdint.h>

typedef void (*callback_func)(void *data);
int my_timeout(int time, callback_func fun, void *data, int sz);
void my_updatetime(void);
uint32_t my_starttime(void);
uint64_t my_thread_time(void);	// for profile, in micro second

void my_timer_init(void);
void test_updatetime(uint32_t num);


#endif
