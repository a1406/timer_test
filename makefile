all: test test2

test: skynet_timer.c test.c
	gcc -g -O0 $^ -o $@

test2: my_timer.c test2.c
	gcc -g -O0 $^ -o $@


clean:
	rm -f *.o test test2

