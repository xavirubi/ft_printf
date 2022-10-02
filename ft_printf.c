/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 23:19:35 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/10/02 23:37:01 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

#include "stdio.h"

#include "unistd.h"

/*int	ft_printf(const char *, ...)
{
*/

void	ft_printf_unsigned_int(unsigned int n);


int	main(void)
{
	unsigned int	ui;

	ui = 4294967295;

	printf("%u", ui);
	printf("\n");
	ft_printf_unsigned_int(ui);
	return (0);
}
