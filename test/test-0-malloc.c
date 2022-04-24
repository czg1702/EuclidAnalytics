#include <stdio.h>
#include <stdlib.h>

#define _1M (1024 * 1024)

// TODO stackOverFlow question
int main(int c, char *v[]) {

	size_t max_allocatable_mem;
	long i = 1;
	char *addr = NULL;

	while (1) {

		max_allocatable_mem = _1M * i;
		addr = malloc(max_allocatable_mem);

		if (addr) {
			printf("allocatable % 16ld M\n", i++);
			free(addr);
		} else {
			printf("can not be allocated % 16ld M\n", i--);
			break;
		}

	}

	printf("\nmax_allocatable_mem = %ld M\n\n", i);

	size_t small_mem_block = max_allocatable_mem / 10;

	for (i=0; i<20; i++) {
		addr = malloc(small_mem_block);
		if (addr) {
			printf("starting address < %p >  capacity < %lu bytes >\n", addr, small_mem_block);
		} else {
			break;
		}
	}

	return 0;
}
