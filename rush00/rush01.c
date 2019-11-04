/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 11:28:17 by lucocozz          #+#    #+#             */
/*   Updated: 2019/07/06 11:59:49 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_putchar(char c);

static void	ft_print(int x, int y, int max_x, int max_y)
{
	if (x == 0 && y == 0)
		ft_putchar('/');
	else if (x == max_x && y == 0)
		ft_putchar('\\');
	else if (x == 0 && y == max_y)
		ft_putchar('\\');
	else if (x == max_x && y == max_y)
		ft_putchar('/');
	else if (y == 0)
		ft_putchar('*');
	else if (x == 0)
		ft_putchar('*');
	else if (x == max_x)
		ft_putchar('*');
	else if (y == max_y)
		ft_putchar('*');
	else
		ft_putchar(' ');
}

void		rush(unsigned int max_x, unsigned int max_y)
{
	int x;
	int y;

	x = 0;
	y = 0;
	max_x--;
	max_y--;
	while (y <= (int)max_y)
	{
		ft_print(x, y, max_x, max_y);
		if (x == (int)max_x)
		{
			ft_putchar('\n');
			x = 0;
			y++;
		}
		else
			x++;
	}
}
