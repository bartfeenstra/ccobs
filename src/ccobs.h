#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

bool stuff(const char *unstuffed, const size_t unstuffed_length, char *stuffed, size_t *stuffed_length);

bool unstuff(const char *stuffed, const size_t stuffed_length, char *unstuffed, size_t *unstuffed_length);
