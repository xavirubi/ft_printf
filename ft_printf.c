/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 23:19:35 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/10/03 19:58:39 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	ft_printf(const char *str, ...)
{
	%#p

int	main(void)
{
	char	a;
	char	*ptr;

	a = 'h';
	ptr = &a;

	printf("%p", ptr);
	printf("\n");
	ft_printf_void_ptr_hex(ptr);
	return (0);
}
