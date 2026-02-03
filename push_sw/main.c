/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <aunoguei@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 16:06:31 by aunoguei          #+#    #+#             */
/*   Updated: 2026/02/03 16:47:11 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		if (is_input_valid(argv))
			push_swap();
		else
			ft_printf("Error\n");
	}
	return (0);
}
