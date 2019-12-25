#include "../inc/uls.h"

int mx_winsize(void){
    struct winsize wins;
    int err = ioctl(1, TIOCGWINSZ, &wins); 

    if (err == -1) {
        exit(1);
    }
    return wins.ws_col;
}
