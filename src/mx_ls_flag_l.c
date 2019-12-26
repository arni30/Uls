#include "../inc/uls.h"

void mx_ls_flag_l(t_array *dir, int flag, char **argv) {
    mx_print_total(dir);
    for (int i = 0; i < mx_count_arr_el(dir->names); i++) {
        mx_print_mode(dir, i);
        mx_print_link_uid_gid_size(dir, i);
        mx_print_time_name(dir, i, flag, argv);
    }
}
