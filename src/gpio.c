/**
 * @file gpio.c
 * @author Ethan Hayon
 *
 * This file contains GPIO functions using high
 * performance mmap of /dev/mem
 */

#include "gpio.h"

static volatile uint32_t *map;
static char mapped = FALSE;

/**
 * map /dev/mem to memory
 * @returns whether or not the mapping of /dev/mem into memory was successful
 */
int init() {
	if(!mapped) {
		puts("Initializing...");
		int fd;
		fd = open("/dev/mem", O_RDWR);
		if(fd == -1) {
			perror("Unable to open /dev/mem");
			exit(EXIT_FAILURE);
		}
		map = (uint32_t*)mmap(NULL, MMAP_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, MMAP_OFFSET);
		if(map == MAP_FAILED) {
			close(fd);
			perror("Unable to map /dev/mem");
			exit(EXIT_FAILURE);
		}
		mapped = TRUE;
	}
	return mapped;
}

/**
 * Set a GPIO digital output * @param p Pin to write to
 * @param mode Position to set the pin, HIGH or LOW
 * @returns output was successfully written
 */
int digitalWrite(PIN p, uint8_t mode) {
	init();
	if(mode == HIGH)
		map[(p.gpio_bank-MMAP_OFFSET+0x13c)/4] |= 1<<p.bank_id;
	else
		map[(p.gpio_bank-MMAP_OFFSET+0x13c)/4] &= ~(1<<p.bank_id);
	
	return 1;
}

int digitalRead(PIN p, uint8_t mode) {
	return 1;
}