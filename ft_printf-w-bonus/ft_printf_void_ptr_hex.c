/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_void_ptr_hex.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:09:50 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/11/03 15:24:11 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*static int	ft_printf_void_ptr_hex_null(t_ftprintf *arg_data)
{
	char	*ptr;
	int		ptr_len;

	ptr = "(nil)";
	ptr_len = (int)ft_strlen(ptr);
	if (arg_data->width > ptr_len && !arg_data->dash)
		if (0 > ft_padding(arg_data, arg_data->width - ptr_len, ' '))
			return (-1);
	if (0 > ft_write_str(arg_data, ptr))
		return (-1);
	if (arg_data->width > ptr_len && arg_data->dash)
		if (0 > ft_padding(arg_data, arg_data->width - ptr_len, ' '))
			return (-1);
	return (0);
}*/

int	ft_printf_void_ptr_hex(t_ftprintf *arg_data)
{
	void	*ptr;
	int		ptr_len;

	ptr = va_arg(arg_data->args, void *);
	/*if (!ptr)
	{
		if (0 > ft_printf_void_ptr_hex_null(arg_data))
			return (-1);
	}
	else
	{*/
	ptr_len = (int)ft_unsignedlen_base((size_t)ptr, HEX_LC) + 2;
	//printf("\nptr_len: %i\n", ptr_len);
	if (arg_data->width > ptr_len && !arg_data->dash)
		if (0 > ft_padding(arg_data, arg_data->width - ptr_len, ' '))
			return (-1);
	if (0 > ft_write_void_ptr_hex(arg_data, ptr))
		return (-1);
	if (arg_data->width > ptr_len && arg_data->dash)
		if (0 > ft_padding(arg_data, arg_data->width - ptr_len, ' '))
			return (-1);
//	}
	return (0);
}
