#include "../inc/uls.h"

void mx_error_dir(char **flags, int index){
    mx_print_error(MX_ULS);
    mx_print_error(flags[index]);
    mx_print_error(MX_ERROR_DIR);
}
