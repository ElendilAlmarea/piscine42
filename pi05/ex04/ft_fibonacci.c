/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:43:27 by yvanat            #+#    #+#             */
/*   Updated: 2019/07/08 16:26:48 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	int fib;

	fib = 1;
	if (index < 0)
		return (-1);
	else if (index == 0)
		return (0);
	else if (index > 1)
		fib = (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
	return (fib);
}
