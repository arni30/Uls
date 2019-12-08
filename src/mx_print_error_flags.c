#include "../inc/uls.h"

void mx_print_error_flag(int index, int index2,char **flags) {
    mx_print_error(MX_ERROR_FLAG);
    mx_printchar(flags[index][index2]);
    mx_printchar('\n');
    mx_print_error(MX_ERROR_USAGE);
    exit(1);
}
