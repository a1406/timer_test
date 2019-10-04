all: test

test: skynet_timer.c test.c
	gcc -g -O0 $^ -o $@

clean:
	rm -f *.o test

