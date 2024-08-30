# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dyao <dyao@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/13 18:21:33 by dyao              #+#    #+#              #
#    Updated: 2024/08/13 20:11:52 by dyao             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS        =   ./src/ft_change_3d_to_2d.c \
				./src/ft_check_pixel.c \
				./src/ft_draw_line.c \
				./src/ft_free_list.c \
				./src/ft_move.c \
				./src/ft_put_pixel.c \
				./src/ft_quit.c \
				./src/ft_read_and_fill_p2.c \
				./src/ft_read_and_fill.c \
				./src/ft_set_mlx.c \
				./src/ft_zoom_turn.c \
				./get_next_line/get_next_line.c \
				./get_next_line/get_next_line_utils.c \
				./src/main.c

LIBFTDIR	= 	libft/

LIBFTOBJS	= 	libft.a

OBJS		= 	$(SRCS:.c=.o)

CC			= 	cc

RM			= 	rm -f

CCFLAGS		= 	-Wall -Werror -Wextra -I.

FLAGSFORMLX =	-L./minilibx-linux -lmlx -lX11 -lXext -lm

NAME		= 	fdf.a

all:			libft_build $(NAME)

$(NAME):		$(OBJS)
				$(CC) $(CCFLAGS) $(SRCS) $(LIBFTDIR)$(LIBFTOBJS) $(FLAGSFORMLX) -o fdf
				cp $(LIBFTDIR)$(LIBFTOBJS) $(NAME)
				ar rcs $(NAME) $(OBJS)

libft_build:
				$(MAKE) -C $(LIBFTDIR)

clean:
				$(RM) $(OBJS)
				$(RM) fdf
				cd $(LIBFTDIR) && $(MAKE) clean

fclean:			clean
				$(RM) $(NAME)
				cd $(LIBFTDIR) && $(MAKE) fclean

re:				fclean all

.PHONY:			all clean fclean re $(LIBFTDIR)