#include "../inc/uls.h"

int mx_winsize(void) {
    struct winsize wins;
    int err = ioctl(0, TIOCGWINSZ, &wins); 

    if (err == -1)
        return 0;
    return wins.ws_col;
}
