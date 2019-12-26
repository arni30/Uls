NAME = uls
SRC = src/main.c src/mx_error_flag.c src/mx_print_error_flags.c src/mx_error_dir.c src/mx_print_dir.c src/mx_sort_dir.c src/mx_output.c src/mx_find_flag.c src/mx_free_void_arr.c src/mx_ls_dir.c src/mx_winsize.c src/mx_print_error.c src/mx_free_dir.c src/mx_output_loop.c src/mx_ls_flag_l.c src/mx_uid_to_name.c src/mx_count_delim.c src/mx_malloc_dir.c src/mx_fill_dir.c src/count_el_in_line.c src/mx_color_print.c src/mx_strcmp_ls.c src/mx_print_mode.c src/mx_license_if.c src/mx_acl_attr_if.c src/mx_print_link_uid_gid_size.c src/mx_print_time_name.c src/mx_if_sock_blk_fifo.c src/mx_print_total.c src/mx_print_flag_F.c
SRCOB = main.o mx_error_flag.o mx_print_error_flags.o mx_error_dir.o mx_print_dir.o mx_sort_dir.o mx_output.o mx_find_flag.o mx_free_void_arr.o mx_ls_dir.o mx_winsize.o mx_print_error.o mx_free_dir.o mx_output_loop.o mx_ls_flag_l.o mx_uid_to_name.o mx_count_delim.o mx_malloc_dir.o mx_fill_dir.o count_el_in_line.o mx_color_print.o mx_strcmp_ls.o mx_print_mode.o mx_license_if.o mx_acl_attr_if.o mx_print_link_uid_gid_size.o mx_print_time_name.o mx_if_sock_blk_fifo.o mx_print_total.o mx_print_flag_F.o
INC = inc/uls.h
OBJ = obj/main.o obj/mx_error_flag.o obj/mx_print_error_flags.o obj/mx_error_dir.o obj/mx_print_dir.o obj/mx_sort_dir.o obj/mx_output.o obj/mx_find_flag.o obj/mx_free_void_arr.o mx_ls_dir.o obj/mx_winsize.o obj/mx_print_error.o obj/mx_free_dir.o obj/mx_output_loop.o obj/mx_ls_flag_l.o obj/mx_uid_to_name.o obj/mx_count_delim.o obj/mx_malloc_dir.o obj/mx_fill_dir.o obj/count_el_in_line.o obj/mx_color_print.o obj/mx_strcmp_ls.o obj/mx_print_mode.o obj/mx_license_if.o obj/mx_acl_attr_if.o obj/mx_print_link_uid_gid_size.o obj/mx_print_time_name.o obj/mx_if_sock_blk_fifo.o obj/mx_print_total.o obj/mx_print_flag_F.o
DIR = obj/
LIBMX = libmx
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

all: install clean

install:
	@make -C $(LIBMX)
	@mkdir obj
	@clang $(CFLAGS) -c $(SRC)
	@cp $(SRCOB) $(DIR)
	@clang $(CFLAGS) -o $(NAME) $(OBJ) -L./libmx -lmx

uninstall: clean
	@rm -rf $(NAME)
	@make uninstall -C $(LIBMX)

clean:	
	@rm -rf $(SRCOB)
	@rm -rf $(DIR)

reinstall: uninstall all
	@rm -rf $(SRCOB)
	@rm -rf $(DIR)