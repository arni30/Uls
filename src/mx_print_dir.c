#include "../inc/uls.h"

<<<<<<< HEAD
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
=======
void mx_print_dir(const char *s, int delim) {// должна печатать либо пробелы по кол-ву либо если делим -1 => \n
    write(1, s, mx_strlen(s));
    if (delim != -1){
        for(int i = delim - mx_strlen(s); i > 0; i--) {
            write(1, " ", 1);
        }
    }
    else {
        write(1, "\n", mx_strlen("\n"));
>>>>>>> 096bc3070d76f26a3dd2f84a93abf526e4cad386
    }
}
