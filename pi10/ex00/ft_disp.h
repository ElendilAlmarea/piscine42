/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disp.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 00:16:25 by yvanat            #+#    #+#             */
/*   Updated: 2019/07/18 00:22:54 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DISP_H
# define FT_DISP_H

# include <unistd.h>
# include <fcntl.h>

int	ft_write(char *buffer, int size, int len);
int	ft_display(char *path);

#endif
