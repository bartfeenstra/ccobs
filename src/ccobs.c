#include "ccobs.h"
#include <stdbool.h>
#include <stdio.h>

bool stuff(const char *unstuffed, const size_t unstuffed_length, char *stuffed,
           size_t *stuffed_length)
{
    // Reset the output counter.
    *stuffed_length = 0;
    // Append a zero byte to the input.
    // unstuffed += 0;
    // The buffer, the size of a COBS block.
    size_t chunk[255];
    size_t chunk_length = 0;



    // @todo FROM WIKIPEDIA
    // @todo 1) append a zero byte (CAN WE DO THIS USING A POINTER? IT WOULD MODIFY THE ORIGINAL)
    // @todo 2) break bytes into groups of 254 non-zero bytes or 0-253 non-zero bytes followed by a zero byte
    // @todo 3) encode ach group by deleting trailing zero and prepending >>>number of non-zero bytes + 1<<<
    // @todo 
    // @todo 4) Append the chunk to the output. Use mempcpy(target, source, length)
    // @todo 
    // @todo 

    // Process each input byte.
    printf("\nSTUFFED AT STUFF START: \n%s", stuffed);
    for (size_t i = 0; i < unstuffed_length; i++) {
        chunk[chunk_length] = unstuffed[i];
        chunk_length++;
        printf("\nSTUFFED BEFORE %zu: \n%s", i, stuffed);
        (*stuffed_length)++;
        stuffed[i] = unstuffed[i];
        printf("\nSTUFFED AFTER %zu: \n%s", i, stuffed);
        // @todo If chunk length has run out (254) OR if nullbyte is encountered OR length has been reached, process the chunk.
    }
    printf("\nSTUFFED AT STUFF END: \n%s", stuffed);
    return false;
}

// bool unstuff(const uint8_t *stuffed, size_t stuffed_length, uint8_t
// *unstuffed, size_t unstuffed_length)
// {
//     return 0;
// }
