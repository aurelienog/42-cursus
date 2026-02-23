# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_plant_age.py                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aunoguei <aunoguei@student.42urduliz.      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/23 15:01:22 by aunoguei          #+#    #+#              #
#    Updated: 2026/02/23 15:03:40 by aunoguei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

def ft_plant_age():
    age = input("Enter plant age in days: ")
    if (int(age) > 60):
        print("Plant is ready to harvest!")
    else:
        print("Plant needs more time to grow.")
