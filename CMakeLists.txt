cmake_minimum_required(VERSION 3.9)
project(ft_printf C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS  "-Wall -Wextra -Werror")
add_executable(ft_printf
        main.c
        ft_printf.h
        path.c
        int.c
        string.c
        flags.c
        length.c
        exceptions_func.c
        precision.c
        digits_precision.c
        digits_precision.c
        pick_f_base.c
        pick_f_bigs.c
        pick_f_u_int.c
        pick_f_c.c
        pick_f_d.c
        pick_f_p.c
        pick_f_percent.c
        pick_f_s.c
        pick_f_w.c
        to_base.c
        toolbox.c
        Checker/check.c
        Checker/path_check.c
        Checker/conversion_check.c)
target_link_libraries(ft_printf "~/dev/ft_printf/libft/libft.a")