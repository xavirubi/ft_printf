/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 23:02:24 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/10/18 18:38:43 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_printf_str(char *str)
{
	int		i;
	ssize_t	n_wr;
	ssize_t	temp_n;

	i = -1;
	n_wr = 0;
	if (!str)
		str = (char *)"(null)";
	while (str[++i])
	{
		temp_n = write(STDOUT_FILENO, &str[i], 1);
		if (temp_n < 0)
			return (temp_n);
		n_wr += temp_n;
	}
	return (n_wr);
}
