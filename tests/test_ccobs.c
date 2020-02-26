#include "../src/ccobs.c"
#include <stdbool.h>
#include <stdio.h>
#include "unity.h"

void test_stuff_single_byte() {
    char unstuffed[1] = {0};
    size_t unstuffed_length = 1;
    char stuffed_expected[3] = {1, 1, 0};
    char stuffed_actual[999] = "";
    size_t stuffed_actual_length = 0;

//    @todo
//    @todo Print bytes as hex (https://stackoverflow.com/questions/6357031/how-do-you-convert-a-byte-array-to-a-hexadecimal-string-in-c)
//    @todo
    printf("\nSTUFFED BEFORE TEST: \n%s", stuffed_actual);
    bool result = stuff(unstuffed, unstuffed_length, stuffed_actual, &stuffed_actual_length);
    TEST_ASSERT_EQUAL_BOOL(true, result)
    printf("\nSTUFFED AFTER TEST: \n%s", stuffed_actual);
    printf("\n");
    // if (stuffed_expected != stuffed_actual) {
    //     printf("Stuffing a single byte failed.");
    //     return 1;
    // }
}

int main() {
    test_stuff_single_byte();

    return 0;
}