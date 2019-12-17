#include "../inc/uls.h"

int mx_winsize(void){
    struct winsize wins;
    int err = ioctl(1, TIOCGWINSZ, &wins); 

    if (err == -1) {
        exit(1);
    }
<<<<<<< HEAD
    printf("cols=%d rows=%d\n", wins.ws_col, wins.ws_row); 
=======
    //printf("cols=%d rows=%d\n", wins.ws_col, wins.ws_row); 
>>>>>>> 096bc3070d76f26a3dd2f84a93abf526e4cad386
    return wins.ws_col;
}
