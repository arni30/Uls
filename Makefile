NAME = uls
SRC = src/main.c src/mx_error_flag.c src/mx_print_error_flags.c src/mx_error_dir.c src/mx_ls_no_flags.c src/mx_print_dir.c src/mx_sort_dir.c src/mx_loop_print.c src/mx_find_flag.c src/mx_ls_flag_1.c src/mx_free_void_arr.c src/mx_ls_flag_a.c src/mx_ls_flag__A.c src/mx_ls_show_directory.c src/mx_winsize.c src/mx_print_error.c
SRCOB = main.o mx_error_flag.o mx_print_error_flags.o mx_error_dir.o mx_ls_no_flags.o mx_print_dir.o mx_sort_dir.o mx_loop_print.o mx_find_flag.o mx_ls_flag_1.o mx_free_void_arr.o mx_ls_flag_a.o mx_ls_flag__A.o mx_ls_show_directory.o mx_winsize.o mx_print_error.o
INC = inc/uls.h
OBJ = obj/main.o obj/mx_error_flag.o obj/mx_print_error_flags.o obj/mx_error_dir.o obj/mx_ls_no_flags.o obj/mx_print_dir.o obj/mx_sort_dir.o obj/mx_loop_print.o obj/mx_find_flag.o obj/mx_ls_flag_1.o obj/mx_free_void_arr.o obj/mx_ls_flag_a.o mx_ls_flag__A.o obj/mx_ls_show_directory.o obj/mx_winsize.o obj/mx_print_error.o
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