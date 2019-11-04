/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 23:39:52 by yvanat            #+#    #+#             */
/*   Updated: 2019/07/21 18:28:02 by enduperv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_dict	t_dict;
struct			s_dict
{
	char	*one[20];
	char	*ten[10];
	char	*other[5];
};
void			ft_putstr(char *str);
void			ft_putstr_err(char *str);
void			ft_putchar(char c);
int				ft_strlen(char *str);
char			*ft_strndup(char *str, unsigned int size);
char			*ft_strdup(char *str);
char			**ft_split(char *str, char delimiter, int *size);
char			*ft_trim(char *str);
int				is_valid(int argc, char **argv);
int				ft_read(char *path);
int				dic_valid(char *buffer, int i, int check);
int				checker(char *buffer, int i, int check);
int				write_plist(char *parsed_list, int j, char *b, int check);
int				parser(char *buffer, int size_read, char *parsed_list);
int				parsed(char *buffer, int size_read);
long			ft_atoi(char *str);
int				is_valid_int(char *nb);
int				is_valid_dictionary(char *buff);
void			parse_dictionary(char *buff, t_dict *dict);
int				is_number_char(char c);
void			convert_to_words(unsigned long n, t_dict *dict);
void			num_to_words(int n, char *suffix, t_dict *dict);
void			print_suffix(int n, char *suffix);
int				run_convert(int dictionary, unsigned long nbr);
void			free_array(char **array, unsigned int size);
int				ft_frequence(char *str, char c);
#endif
