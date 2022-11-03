/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:08:01 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/11/03 01:11:19 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_valid_width(t_ftprintf *arg_data, int n)
{
	int	n_len;
	int	precision;

	n_len = (int)ft_nbrlen(n);
	precision = arg_data->precision;


	if (n == 0 && arg_data->dot && precision == 0)
		n_len = 0;
	if ((arg_data->sign || n < 0) || (arg_data->space && n > -1))
	{
		precision++;
		//n_len++;
	}
	if ((arg_data->sign && n >= 0) || (arg_data->space && n > -1))
		n_len++;





	//if (n < 0 || arg_data->sign)
	//	precision++;
	if (arg_data->width > n_len && arg_data->width > precision)
		return (1);
	return (0);
}

static int	ft_padd_width(t_ftprintf *arg_data, int n)
{
	int	width;
	int n_len;
	int	precision;

	width = 0;
	precision = arg_data->precision;
	n_len = (int)ft_nbrlen(n);


	/*if (n < 0 || arg_data->sign || (arg_data->space && n > -1))
		width--;*/

	


	if (n == 0 && arg_data->dot && precision == 0)
		n_len = 0;
	if (n < 0 || arg_data->sign)
		precision++;
	if (n_len > precision)
		width += arg_data->width - n_len;
	else
		width += arg_data->width - precision;
	//printf("\npadd width returned: %i\n", width);
	return (width);
}

int	ft_printf_int(t_ftprintf *arg_data)
{
	int	n;
	//tener en cuenta el signo en width, width > precision+signo, e.g. precision + ft_is_signed(arg_data, n)
	//ft_expected_width vs
	//poner en las otras funciones
	//poner las condiciones de los if en orden de restrictivas
	ft_pull_precision_asterisk(arg_data);
	if (arg_data->zero && arg_data->dot)
		arg_data->zero = 0;
	n = va_arg(arg_data->args, int);
	if (!arg_data->dash && !arg_data->zero && ft_valid_width(arg_data, n))
		if (0 > ft_padding(arg_data, ft_padd_width(arg_data, n), ' '))
			return (-1);
	if (arg_data->sign && n > -1)
		if (0 > ft_write_str(arg_data, "+"))
			return (-1);
	if (!arg_data->sign && arg_data->space && n > -1)
		if (0 > ft_write_str(arg_data, " "))
			return (-1);
	if (n < 0)
		if (0 > ft_write_str(arg_data, "-"))
			return (-1);
	if (!arg_data->dash && arg_data->zero && ft_valid_width(arg_data, n))
		if (0 > ft_padding(arg_data, ft_padd_width(arg_data, n), '0'))
			return (-1);
	if (arg_data->precision > (int)ft_nbrlen(ft_absval(n)))
		if (0 > ft_check_precision(arg_data, ft_absval(n)))
			return (-1);
	if (n == 0 && arg_data->dot && arg_data->precision == 0)
	{
		if (0 > ft_write_str(arg_data, ""))
			return (-1);
	}
	else
	{
		if (0 > ft_write_int(arg_data, ft_absval(n)))
			return (-1);
	}
	if (ft_valid_width(arg_data, n) && arg_data->dash)
		if (0 > ft_padding(arg_data, ft_padd_width(arg_data, n), ' '))
			return (-1);
	return (0);
}
