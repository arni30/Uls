#include "../inc/uls.h"

void mx_ls_flag_l(t_array *dir) {
<<<<<<< HEAD
    acl_t acl = NULL;
    // ssize_t r = 0;
    // char *linkname = malloc((dir->st[1]->st_size + 1));
    char *acl_text = NULL;
    //ssize_t *len = NULL;

=======
>>>>>>> 4074124836b000b0b4f4b055b7feb041e9d9acc2
    for (int i = 0; i < mx_count_arr_el(dir->names); i++) {
        mx_printstr("USER ID [");
        mx_printint(i);
        mx_printstr("]: ");
        mx_printstr(mx_uid_to_name(dir->st[i]->st_uid));
        mx_printstr("       ");

        mx_printstr("GROUP ID [");
        mx_printint(i);
        mx_printstr("]: ");
        mx_printint(dir->st[i]->st_gid);
        mx_printstr("       ");

        mx_printstr("LINKS [");
        mx_printint(i);
        mx_printstr("]: ");
        mx_printint(dir->st[i]->st_nlink);
        mx_printstr("       ");

        mx_printstr("LICENSE [");
        mx_printint(i);
<<<<<<< HEAD
        mx_printstr("]: ");
        //acl = malloc(sizeof(acl_t));
        acl = acl_get_file(dir->names[i], ACL_TYPE_ACCESS);
        if (acl == NULL)
	{
		perror ("acl_get_file()");
		exit(1);
	}
        acl_text = acl_to_text (acl, NULL);
        if (acl_text == NULL)
	{
		perror ("acl_to_text()");
		exit(1);
	}
        printf("%s", acl_text);
        //mx_printstr(acl_to_text (type, NULL));
        acl_free(acl_text);
=======
        mx_printstr("]: ");      
        int mode = dir->st[i]->st_mode;
        char *str = mx_strnew(10 * sizeof(char)); 
        mx_strcpy(str,"----------");
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
        mx_printstr(str);
>>>>>>> 4074124836b000b0b4f4b055b7feb041e9d9acc2
        mx_printstr("       ");
        free(str);

        mx_printstr("\n");
    }
}

