#include "../inc/uls.h"

void mx_print_dir(const char *s, int delim) {// должна печатать либо пробелы по кол-ву либо если делим -1 => \n
    int len = mx_strlen(s);
    int count = 0;
    int a_el = 0;

    while (s[count]) {
        if(s[count] > 0) {
            a_el++;
        }
        count++;
    }
    len = (len - a_el)/2 + (len - a_el)%2;
    len += a_el;
    write(1, s, mx_strlen(s));
    if (delim != -1){
        for(int i = delim - len; i > 0; i--) {
            write(1, " ", 1);
        }
    }
    else {
        write(1, "\n", mx_strlen("\n"));
    }
}
