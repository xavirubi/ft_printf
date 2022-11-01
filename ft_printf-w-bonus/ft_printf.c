/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 23:19:35 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/10/31 18:07:39 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_ftprintf	*ft_init_arg_data(t_ftprintf *arg_data)
{
	arg_data->sharp = 0;
	arg_data->zero = 0;
	arg_data->dash = 0;
	arg_data->space = 0;
	arg_data->sign = 0;
	arg_data->width = 0;
	arg_data->dot = 0;
	arg_data->asterisk = 0;
	arg_data->precision = 0;
	arg_data->percentage = 0;
	arg_data->n_printed = 0;

	return (arg_data);
}

static void	ft_reset_arg_data(t_ftprintf *arg_data)
{
	arg_data->sharp = 0;
	arg_data->zero = 0;
	arg_data->dash = 0;
	arg_data->space = 0;
	arg_data->sign = 0;
	arg_data->width = 0;
	arg_data->dot = 0;
	arg_data->asterisk = 0;
	arg_data->precision = 0;
	arg_data->percentage = 0;
}

//create macro for FLAGS
//use DEC where necessary
static int	ft_check_valid_format(const char *fmt, int i)
{
	if (ft_there_is_flag(fmt, i))
	{
		while (fmt[i++] && ft_strchr("# +-0", fmt[i]))
			continue;
	}
	if (ft_there_is_width(fmt, i))
	{
		while (fmt[i++] && ft_strchr("0123456789", fmt[i]))
			continue;
	}
	if (ft_there_is_precision(fmt, i))
		while (fmt[++i] && ft_strchr("0123456789", fmt[i]))
			continue;
	if (!ft_there_is_type(fmt, i))
		return (0);
	return (1);
}

static int	ft_check_arg(t_ftprintf *arg_data, const char *fmt, int i)
{
	if (!ft_check_valid_format(fmt, i))
		return (i - 1);
	i = ft_fetch_arg_data(arg_data, fmt, i);
	if (0 > ft_printf_arg(arg_data, fmt[i]))
		return (-1);
	ft_reset_arg_data(arg_data);
	return (i);
}

int	ft_printf(const char *fmt, ...)
{
	int		i;
	int		total_printed;
	int		temp_n;
	t_ftprintf	*arg_data;

	i = -1;
	total_printed = 0;
	temp_n = 0;
	arg_data = (t_ftprintf *)malloc(sizeof(t_ftprintf));
	if (!arg_data)
		return (-1);
	arg_data = ft_init_arg_data(arg_data);
	va_start(arg_data->args, fmt);
	while (fmt[++i])
	{
		if (fmt[i] == '%')
			i = ft_check_arg(arg_data, fmt, ++i);
		if (i < 0)
			return (i);
		temp_n = (int)write(STDOUT_FILENO, &fmt[i], 1);
		if (temp_n < 0)
			return (temp_n);
		total_printed += temp_n;
		
	}
	va_end(arg_data->args);
	total_printed += arg_data->n_printed;
	free(arg_data);
	return (total_printed);
}
