#include "../inc/uls.h"

void mx_ls_flag_l(t_array *dir, int flag, t_var *variable, char *position) {
  char flag_o = 0;

  if(mx_find_flag(variable->argc1, variable->args, 'o') == 1
     && mx_find_flag(variable->argc1, variable->args, 'g') == 0)
    flag_o = '0';
  else if(mx_find_flag(variable->argc1, variable->args, 'g') == 1
          && mx_find_flag(variable->argc1, variable->args, 'o') == 0)
    flag_o = 'g';
  else if (mx_find_flag(variable->argc1, variable->args, 'g') == 1
           && mx_find_flag(variable->argc1, variable->args, 'o') == 1)
    flag = 1;
  mx_print_total(dir);
  for (int i = 0; i < mx_count_arr_el(dir->names); i++) {
    mx_print_mode(dir, i, position);
    mx_print_link_uid_gid_size(dir, i, flag_o, flag);
    mx_print_time_name(dir, i, flag, variable);
  }
}
