#define PATHFINDER_H
#ifdef PATHFINDER_H

#define MX_ERROR_FLAG "uls: illegal option -- "
#define MX_ERROR_USAGE "usage: uls [-ACFGRafglos1] [file ...]\n"
#define MX_ERROR_DIR ": No such file or directory\n"
#define MX_ULS "uls: " 

#define MX_FILE "\033[0m"           //Regular file
#define MX_EXEC "\033[31m"           //Directory
#define MX_DIR "\033[34m"
#define MX_LINK "\033[35m"
#define MX_FIFO "\033[33m"
#define MX_SOCKET "\033[32m"
#define MX_STICKY "\033[42;30m"
#include "../libmx/inc/libmx.h"
#include <sys/types.h>
#include <dirent.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <limits.h>
#include <pwd.h>
#include <grp.h>
#include <sys/xattr.h>
#include <sys/acl.h>

typedef struct s_array {
    char **names;
    unsigned char *type;
    struct stat **st;
} t_array;

typedef struct s_var {
    int delim;
    char **args;
    int argc1;
} t_var;

void mx_sort_ascii(int count, char **arr);
int mx_print_flag_F(t_var *variable, t_array *dir, int i);
void mx_if_sock_blk_fifo(t_array *dir, int i, t_var *variable, int num);
void mx_print_total(t_array *dir, int num);
void mx_print_symlink(t_array *dir, char *buf, int i);
void mx_print_time_name(t_array *dir, int i, int flag_G, t_var *variable, int num);//
void mx_print_link_uid_gid_size(t_array *dir, int i, int num_of_files, t_var *variable);//
int mx_acl_attr_if(int mode, char *str, char *curentFile);
void mx_license_if(int mode, char *str);
void mx_print_mode(t_array *dir, int i, char *position, int num_of_files);//
char *mx_uid_to_name(t_array *dir, int n);
void mx_ls_flag_l(t_array *dir, int flag_G, t_var *variable, char *position, int num_of_files, int flag_files);
void mx_output_loop(t_array *dir, t_var *variable, int win_width,
        void mx_print_output(int i, t_array *dir, t_var *variable, int num), int num_of_files);
void mx_free_dir(t_array *dir, int num_of_files);
void mx_ls_dir(char *current_position, t_array *dir, t_var *variable, int flag_files);
void mx_free_void_arr(void **arr, int lines);
int mx_find_flag(int argc, char **flags, char flag);
void mx_output(t_array *dir, t_var *variable, int num_of_files, int flag_files);
void mx_print_dir(int i, t_array *dir, t_var *variable, int num);
void mx_print_error(char *str);
void mx_print_error_flag(int index1, int index2, char **flags);
int mx_error_flag(int argc, char **flags);
void mx_error_dir(char **flags, int index);
void mx_sort_dir(int count, t_array *dir);
int mx_winsize(void);
int mx_count_delim(t_array *dir, t_var *variable, int num_of_files);
void mx_malloc_dir(t_array *dir);
void mx_fill_dir(t_array *dir, struct dirent *ep, int count, char *pathName);
int count_el_in_line(int count, int e_line);
void mx_color_print(int i, t_array *dir, t_var *variable, int num);
int mx_strcmp_ls(const char *s1_, const char *s2_);
int mx_count_max_sym(t_array *dir, char link_or_size, int num_of_files);

int mx_file_exist(char *file);
void mx_flag_R(int num_of_files, t_array *dir, t_var *variable, char *current_position);
void mx_realloc_dir(t_array *dir, int count);
char **mx_input_files(t_var *variable, int *num_files);
char *mx_path(char *pathName, char *file, int flag);
void mx_fill_file_dir(char *file, t_array *dir, int count);
int mx_flag_check(char *flag_, int flag_stop);
char **mx_error_check_loop(int argc, char **flags, int *flag_stop, int *count);
char *mx_gid_to_name(t_array *dir, int n);
//int mb_strlen(char *source);
//int mx_mb_loop(unsigned char n, char *source, char *m);
//int mx_switch_len(int n, int *i, char *source);
//int mx_strlen1(char *s);
// -l -a -A -G -1 -f -F -C -f -u -c -R -o
#endif

//make flag -d
