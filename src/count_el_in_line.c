#include "../inc/uls.h"

int count_el_in_line(int count, int e_line) {
    if (count > e_line) {
        while (count % e_line != 0 && count % e_line != e_line - 1) {
            if(count % e_line != 0 || count % e_line != e_line - 1) {
                break;
            }
            e_line--;
        }
    }
    return e_line;
}
