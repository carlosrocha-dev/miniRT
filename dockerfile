# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/22 21:28:13 by caalbert          #+#    #+#              #
#    Updated: 2023/10/22 21:38:25 by caalbert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM arm64v8/ubuntu:latest

WORKDIR /project

COPY . .

RUN apt-get update  \
    && apt-get install -y \
    python3 python3-pip \
    valgrind gdb \
    gcc make xorg libxext-dev libbsd-dev

RUN pip3 install norminette

RUN apt-get install -y libx11-dev libxext-dev
RUN git clone https://github.com/42Paris/minilibx-linux.git
RUN cd minilibx-linux && make
RUN cp minilibx-linux/libmlx.a /usr/local/lib/
RUN cp minilibx-linux/mlx.h /usr/local/include/
RUN cp minilibx-linux/libmlx_Linux.a /usr/local/lib/
