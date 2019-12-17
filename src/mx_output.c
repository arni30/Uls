#include "../inc/uls.h"

void mx_output(char **arr){
    if(isatty(1) == 0){
        mx_loop_print(arr, "\n");
    }
    else {
        mx_loop_print(arr, "                ");
    }
    mx_printchar('\n');
}
