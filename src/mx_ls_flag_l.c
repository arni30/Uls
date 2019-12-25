#include "../inc/uls.h"

void mx_ls_flag_l(t_array *dir) {
    size_t size = 1024;
    char name[size];
    size_t size1 = 0;
    acl_t acl;


    for (int i = 0; i < mx_count_arr_el(dir->names); i++) {
        mx_printstr("NAME: ");
        mx_printstr(dir->names[i]);
        write(1, "                  ", 18 - mx_strlen(dir->names[i]));


        mx_printstr("USER ID: ");
        mx_printstr(mx_uid_to_name(dir->st[i]->st_uid));
        write(1, "                ", 16 - mx_strlen(mx_uid_to_name(dir->st[i]->st_uid)));

        mx_printstr("GROUP ID: ");
        mx_printint(dir->st[i]->st_gid);
        write(1, "                ", 12);

        int counter = 0; 
        int pussy = dir->st[i]->st_size;
        while (pussy > 0) {
        counter++;
        pussy /= 10;
        }

        mx_printstr("SIZE: ");
        mx_printint(dir->st[i]->st_size);
        write(1, "                ", 16 - counter);

        mx_printstr("TIME: ");

        struct timespec *a = malloc(sizeof(struct timespec));

        a->tv_sec = dir->st[i]->st_mtimespec.tv_sec;
        mx_printstr(ctime(&a->tv_sec));
        write(1, "                ", 16 - counter);

        counter = 0; 
        pussy = dir->st[i]->st_nlink;
        while (pussy > 0) {
        counter++;
        pussy /= 10;
        }

        mx_printstr("LINK: ");
        mx_printint(dir->st[i]->st_nlink);
        write(1, "                ", 16 - counter);

        mx_printstr("LICENSE: ");
        size1 = 0;
        size1 = listxattr(dir->names[i], name,  size ,XATTR_SHOWCOMPRESSION);
        acl = acl_get_file(dir->names[i], ACL_TYPE_EXTENDED);
        if (size1 < 0){
            exit(1);
        }
        int mode = dir->st[i]->st_mode;
        char *str = mx_strnew(10 * sizeof(char)); 
        mx_strcpy(str,"---------- ");
        if((S_IFMT & mode) == S_IFDIR)str[0]='d';
        if((S_IFMT & mode) == S_IFCHR)str[0]='c';
        if((S_IFMT & mode) == S_IFBLK)str[0]='b';
        if(mode & S_IRUSR)str[1]='r';
        if(mode & S_IWUSR)str[2]='w';
        if(mode & S_IXUSR)str[3]='x';
        if(mode & S_IRGRP)str[4]='r';
        if(mode & S_IWGRP)str[5]='w';
        if(mode & S_IXGRP)str[6]='x';
        if(mode & S_IROTH)str[7]='r';
        if(mode & S_IWOTH)str[8]='w';
        if(mode & S_IXOTH)str[9]='x';
        if(size1 != 0) str[10] = '@';
        if(acl != NULL) str[10] = '+';
        mx_printstr(str);
        //write(1, "                ", 16 - mx_strlen(str));


        acl_free(acl);
        free(str);

        mx_printstr("\n");
    }
    mx_printstr("\n");
}
