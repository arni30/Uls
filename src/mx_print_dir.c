#include "../inc/uls.h"

void mx_print_dir(const char *s, char *delim){
    int count = 0;

    while (delim[count] == ' ') {
        count++;
    }
    write(1, s, mx_strlen(s));
    if (count == 16){
        write(1, delim, 16 - mx_strlen(s));
    }
    else {
        write(1, delim, mx_strlen(delim));
    }
}
