#include "../inc/uls.h"
void mx_error_flag(int argc, char **flags){
  char *us_f = "ACFGafglos1";//"ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1";
  int flag = 0;
  int flag_stop = 0;
  char **error_flags = malloc(sizeof(char*) * CHAR_MAX/8);
  int count = 0;
  DIR *dp;
  for (int i = 1; i < argc; i++) {
    dp = opendir(flags[i]);
    if (dp != NULL || mx_strcmp("--",flags[i]) == 0){
      flag_stop = 1;
    }
    if ((flags[i][0] != '-' || flag_stop == 1) && dp == NULL) {
      error_flags[count] = mx_strdup(flags[i]);
      count++;
      //mx_error_dir(flags, i);
    }
    if (flags[i][0] == '-' && flag_stop == 0) {
      for (int j = 1; flags[i][j] != '\0'; j++) {
        flag = 0;
        for (int count = 0; us_f[count] != '\0'; count++) {
          if (us_f[count] == flags[i][j]) {
            flag = 1;
            break;
          }
        }
        if (flag == 0 && dp == NULL)
          mx_print_error_flag(i, j, flags);
      }
    }
    if (dp != NULL)
      closedir(dp);
  }
  if (mx_find_flag(argc, flags, 'f') == 0) {
    mx_sort_ascii(count, error_flags);
  }
  for (int j = 0; j != count; j++) {
    mx_error_dir(error_flags,j);
  }
  mx_free_void_arr((void**)error_flags, count);
}
