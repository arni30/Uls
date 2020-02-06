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
  char **arr = (char**) malloc(sizeof(char*) * argc);

  for (int i = 0; i < argc; i++){
      arr[i] = mx_strdup(argv[i]);
  }

  return arr;
}

int main(int argc, char **argv) {
  t_array *dir = (t_array*) malloc(sizeof(t_array));
  t_var *variables = (t_var*) malloc(sizeof(t_var));
  int count = 0;
  char **position = (char**) malloc(sizeof(char*));
  DIR *dp;
  int flag_files = mx_error_flag(argc,argv);
  int flag_stop = 0;

  //
  if (flag_files == 1) {
      position[count] = mx_strdup(".");
      count = 1;
  }
  for (int i = 1; i < argc ; i++) {
      dp = opendir(argv[i]);
      if (mx_strcmp("--",argv[i]) == 0)
          flag_stop = 1;
      if (dp != NULL && (argv[i][0] != '-' || flag_stop == 1)) {
          position = (char**) mx_realloc(position, (count + 1) * sizeof(char*));
          position[count] = mx_strdup(argv[i]);
          count++;
          flag_stop = 1;
      }
      if (dp != NULL)
          closedir(dp);
  }
  if (count == 0 && flag_files == 0) {
      position[0] = mx_strdup(".");
      count = 1;
  }
  if (mx_find_flag(argc, argv, 'f') == 0) {
      mx_sort_ascii(count, position);
  }
  for (int i = 0; i < count; i++) {
      variables->argc1 = argc;
      variables->args = mx_copy_argv(argv, argc);
      if(mx_strcmp(position[i], ".") != 0 && count > 1) {
          mx_printstr(position[i]);
          mx_printstr(":\n");
      }
      mx_ls_dir(position[i], dir, variables, flag_files);
      flag_files = 0;
      if(count > 1 && i + 1 != count) {
          mx_printstr("\n");
      }
      mx_free_void_arr((void**)variables->args, variables->argc1);
  }
  free(variables);
  free(dir);
  mx_free_void_arr((void**)position, count);
  //system("leaks -q a.out");
  return 0;
}
