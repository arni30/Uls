#include "../inc/uls.h"

void mx_print_dir(const char *s){
    write(1, s, mx_strlen(s));
    write(1, "                ", 16 - mx_strlen(s));
}
