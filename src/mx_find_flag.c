#include "../inc/uls.h"

int mx_find_flag(int argc, char **flags, char flag) {
  int flag_f = 0;
  DIR *dp;

  for (int i = 1; i < argc; i++) {
    dp = opendir(flags[i]);
    if (dp != NULL){
      closedir(dp);
      break;
    }
    if (mx_strcmp("--",flags[i]) == 0) {
      break;
    }
    if (flags[i][0] == '-') {
      for (int j = 1; flags[i][j] != '\0'; j++) {
        if (flag == flags[i][j]) {
          flag_f = 1;
          break;
        }
      }
    }
  }
  return flag_f;
}
