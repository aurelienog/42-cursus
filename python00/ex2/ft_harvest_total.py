# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_harvest_total.py                                :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aunoguei <aunoguei@student.42urduliz.      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/23 14:55:42 by aunoguei          #+#    #+#              #
#    Updated: 2026/02/23 15:00:13 by aunoguei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

def ft_harvest_total():
    day1 = input("Day 1 harvest: ")
    day2 = input("Day 2 harvest: ")
    day3 = input("Day 3 harvest: ")
    total = int(day1) + int(day2) + int(day3)
    print('Total harvest:', total)
