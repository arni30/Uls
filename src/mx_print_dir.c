#include "../inc/uls.h"

void mx_print_dir(const char *s, int delim) {// должна печатать либо пробелы по кол-ву либо если делим -1 => \n
    write(1, s, mx_strlen(s));
    if (delim != -1){
        for(int i = delim - mx_strlen(s); i > 0; i--) {
            write(1, " ", 1);
        }
    }
    else {
        write(1, "\n", mx_strlen("\n"));
    }
}
