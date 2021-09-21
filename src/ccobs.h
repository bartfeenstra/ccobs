#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

bool stuff(const unsigned char *unstuffed, const size_t unstuffed_length, unsigned char *stuffed, size_t *stuffed_length);

bool unstuff(const unsigned char *stuffed, const size_t stuffed_length, unsigned char *unstuffed, size_t *unstuffed_length);
