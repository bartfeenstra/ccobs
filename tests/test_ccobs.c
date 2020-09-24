#include "../src/ccobs.c"
#include <criterion/criterion.h>
#include <criterion/parameterized.h>

struct stuffing_parameter {
    unsigned char unstuffed[999];
    size_t unstuffed_length;
    unsigned char stuffed[999];
    size_t stuffed_length;
};

static struct stuffing_parameter stuffing_parameters[] = {
        {{0}, 1, {1, 1, 0}, 3},
        {{0, 0}, 2, {1, 1, 1, 0}, 4},
        {{1, 2, 0, 3}, 4, {3, 1, 2, 2, 3, 0}, 6},
};

ParameterizedTestParameters(ccobs, stuff) {
    return cr_make_param_array(struct stuffing_parameter, stuffing_parameters, sizeof (stuffing_parameters) / sizeof (struct stuffing_parameter));
}

ParameterizedTest(struct stuffing_parameter *parameter, ccobs, stuff) {
    unsigned char stuffed_actual[999] = "";
    size_t stuffed_length_actual = 0;
    bool result = stuff(parameter->unstuffed, parameter->unstuffed_length, stuffed_actual, &stuffed_length_actual);
    cr_assert_eq(true, result);
    cr_assert_eq(parameter->stuffed_length, stuffed_length_actual, "%d is not equal to expected %d.", stuffed_length_actual, parameter->stuffed_length);
    cr_assert_eq(parameter->stuffed, stuffed_actual, "%.*X is not equal to expected %.*X.", stuffed_length_actual, *stuffed_actual, parameter->stuffed_length, *parameter->stuffed);
}

ParameterizedTestParameters(ccobs, unstuff) {
    return cr_make_param_array(struct stuffing_parameter, stuffing_parameters, sizeof (stuffing_parameters) / sizeof (struct stuffing_parameter));
}

ParameterizedTest(struct stuffing_parameter *parameter, ccobs, unstuff) {
    // @todo Finish this.
}
