/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_conv_ll_xx.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 13:11:03 by averheij       #+#    #+#                */
/*   Updated: 2019/11/22 10:56:36 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_pre_hex_lower(t_conv *conv, va_list a_list, int *n)
{
	if (conv->size == 'L')
		ft_print_ll_hex_lower(conv, a_list, n);
	else if (conv->size == 'l')
		ft_print_l_hex_lower(conv, a_list, n);
	else
		ft_print_hex_lower(conv, a_list, n);
}

void	ft_prep_ll_hex(t_conv *conv, unsigned long long *i)
{
	conv->length = ft_puthex_ll_size(*i);
	if (conv->precision != -2)
		conv->padzero = 0;
	if (*i == 0)
		conv->hash = 0;
	if (conv->precision == -2 ||
		(conv->precision < conv->length && *i != 0))
		conv->precision = conv->length;
}

void	ft_print_ll_hex_lower(t_conv *conv, va_list a_list, int *n)
{
	unsigned long long	i;

	i = va_arg(a_list, unsigned long long);
	ft_prep_ll_hex(conv, &i);
	if (conv->hash && i != 0 && (conv->leftj || conv->padzero))
		ft_putnstr_n_fd("0x", 1, 2, n);
	if (conv->leftj)
	{
		ft_pad_width(conv->precision, conv->length, '0', n);
		if (conv->precision)
			ft_puthex_ll_lower_n_fd(i, n);
	}
	if (conv->padzero && !conv->leftj)
		ft_pad_width(conv->width, conv->precision + (conv->hash * 2), '0', n);
	else
		ft_pad_width(conv->width, conv->precision + (conv->hash * 2), ' ', n);
	if (!conv->leftj)
	{
		if (conv->hash && i != 0 && !conv->padzero)
			ft_putnstr_n_fd("0x", 1, 2, n);
		ft_pad_width(conv->precision, conv->length, '0', n);
		if (conv->precision)
			ft_puthex_ll_lower_n_fd(i, n);
	}
}

void	ft_pre_hex_upper(t_conv *conv, va_list a_list, int *n)
{
	if (conv->size == 'L')
		ft_print_ll_hex_upper(conv, a_list, n);
	else if (conv->size == 'l')
		ft_print_l_hex_upper(conv, a_list, n);
	else
		ft_print_hex_upper(conv, a_list, n);
}

void	ft_print_ll_hex_upper(t_conv *conv, va_list a_list, int *n)
{
	unsigned long long	i;

	i = va_arg(a_list, unsigned long long);
	ft_prep_ll_hex(conv, &i);
	if (conv->hash && i != 0 && (conv->leftj || conv->padzero))
		ft_putnstr_n_fd("0X", 1, 2, n);
	if (conv->leftj)
	{
		ft_pad_width(conv->precision, conv->length, '0', n);
		if (conv->precision)
			ft_puthex_ll_upper_n_fd(i, n);
	}
	if (conv->padzero && !conv->leftj)
		ft_pad_width(conv->width, conv->precision + (conv->hash * 2), '0', n);
	else
		ft_pad_width(conv->width, conv->precision + (conv->hash * 2), ' ', n);
	if (!conv->leftj)
	{
		if (conv->hash && i != 0 && !conv->padzero)
			ft_putnstr_n_fd("0X", 1, 2, n);
		ft_pad_width(conv->precision, conv->length, '0', n);
		if (conv->precision)
			ft_puthex_ll_upper_n_fd(i, n);
	}
}
