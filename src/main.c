#include "../inc/uls.h"
void mx_sort_ascii(int count, char **arr) {
  for (int i = 0; i < count - 1; i++) {
    for (int j = i + 1; j < count; j++) {
      if (mx_strcmp_ls(arr[i], arr[j]) > 0){
        mx_swaps_arr(arr, i, j);
      }
    }
  }
}
static char** mx_copy_argv(char **argv, int argc) {
  char **arr = malloc(sizeof(char*) * CHAR_MAX/8);

  for (int i = 0, j = 0; i < argc; i++, j++){
    arr[j] = mx_strdup(argv[i]);
  }

  return arr;
}

int main(int argc, char **argv) {
  t_array *dir = malloc(sizeof(t_array));
  t_var *variables = malloc(sizeof(t_var));
  int flag = 0;
  int g_fl = 0;
  int count = 0;
  char **position = malloc(sizeof(char*) * CHAR_MAX/8);
  DIR *dp;


  mx_error_flag(argc,argv);
  for (int i = 1; i < argc ; i++) {
    dp = opendir(argv[i]);
    if (dp != NULL) {
      position[count] = mx_strdup(argv[i]);
      count++;
      flag = 1;
      closedir(dp);
    }
  }
  position = mx_realloc(position, count * sizeof(char**));
  if (flag == 0) {
    position[0] = mx_strdup(".");
    count = 1;
  }
  if (mx_find_flag(argc, argv, 'f') == 0) {
    mx_sort_ascii(count, position);
  }
  if (mx_find_flag(argc, argv, 'G') == 1) {
    g_fl = 1;
  }
  for (int i = 0,flag = 0; i < count; i++) {
    //t_var *variables = malloc(sizeof(t_var));
    //t_array *dir = malloc(sizeof(t_array));
    variables->argc1 = argc;
    variables->args = mx_copy_argv(argv, argc);
    //flag = 0;
    if(count > 1) {
      mx_printstr(position[i]);
      mx_printstr(":\n");
    }
    mx_ls_dir(position[i], dir, flag, argv);
    if (mx_find_flag(argc, argv, 'A') == 1) {
      flag = 1;
      mx_free_dir(dir);
      mx_ls_dir(position[i], dir, flag, argv);
    }
    if (mx_find_flag(argc, argv, 'a') == 1
        || mx_find_flag(argc, argv, 'f') == 1) {
      flag = -1;
      mx_free_dir(dir);
      mx_ls_dir(position[i], dir, flag, argv);//передавать значение а не флаг
    }
    if (mx_find_flag(argc, argv, 'l') == 1)
      mx_ls_flag_l(dir, g_fl, variables, position[i]);
    else
      mx_output(dir, variables);
    if(count > 1 && i + 1 != count) {
      mx_printstr("\n");
    }
    mx_free_void_arr((void**)variables->args, variables->argc1);
    //free(variables);
    mx_free_dir(dir);
    //free(dir);
    //dir = NULL;
  }
  free(variables);
  free(dir);
  mx_free_void_arr((void**)position, count);
  //system("leaks -q a.out");
  return 0;
}
