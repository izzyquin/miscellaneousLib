#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>


bool is_little_indian(){
	/*
		Little Endian
		Lowest memory address gets the least significant byte.

		Big Endian
		Lowest memory address gets the most significant byte.
	*/

	uint32_t x = 0x12345678;
	uint8_t *p = (uint8_t*)&x; 

	printf("%x %x %x %x\n", p[0], p[1], p[2], p[3]);

	return (p[0] == 0x78);
}


int main()
{
	bool lindian = is_little_indian();
	if (lindian) {
		printf("Little Indian\n");
	} else {
		printf("Big Indian\n");
	}
}