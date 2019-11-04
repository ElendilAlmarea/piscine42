/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 21:06:50 by yvanat            #+#    #+#             */
/*   Updated: 2019/07/18 00:50:24 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_disp.h"

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		write(2, "File name missing.\n", 19);
	}
	else if (argc > 2)
	{
		write(2, "Too many arguments.\n", 20);
	}
	else if (ft_display(*(argv + 1)))
	{
		write(2, "Cannot read file.\n", 18);
	}
	return (0);
}
