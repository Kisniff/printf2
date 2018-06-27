cmake_minimum_required(VERSION 3.9)
project(ft_printf C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS  "-Wall -Wextra -Werror")
add_executable(ft_printf main.c ft_printf.h path.c int.c string.c void.c flags.c length.c precision.c digits_precision.c pick_f_x.c pick_f_u_int.c pick_f_c.c to_base.c Checker/check.c Checker/path_check.c Checker/conversion_check.c)
target_link_libraries(ft_printf "~/dev/ft_printf/libft/libft.a")