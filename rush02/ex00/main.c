/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enduperv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 17:42:56 by enduperv          #+#    #+#             */
/*   Updated: 2019/07/21 23:35:58 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*get_input(int argc, char **argv)
{
	if (argc == 2)
		return (argv[1]);
	if (argc == 3)
		return (argv[2]);
	return (NULL);
}

int		get_dictionary_fd(int argc, char **argv)
{
	char	*dictionary_name;

	dictionary_name = "numbers.dict";
	if (argc == 3)
		dictionary_name = argv[1];
	return (open(dictionary_name, O_RDONLY));
}

int		main(int argc, char **argv)
{
	long			nb;
	int				dictionary;
	char			*input;

	input = get_input(argc, argv);
	dictionary = get_dictionary_fd(argc, argv);
	if (!input || dictionary < 0 || !is_valid_int(input))
	{
		ft_putstr_err("Error\n");
		close(dictionary);
		return (0);
	}
	nb = ft_atoi(input);
	if (!run_convert(dictionary, nb))
		ft_putstr_err("Dict Error\n");
	close(dictionary);
	return (0);
}
