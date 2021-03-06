/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_conv_ll_diu.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 13:22:22 by averheij       #+#    #+#                */
/*   Updated: 2019/12/17 11:11:30 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_pre_int(t_conv *conv, va_list a_list, int *n)
{
	if (conv->size == 'L')
		ft_print_ll_int(conv, a_list, n);
	else if (conv->size == 'l')
		ft_print_l_int(conv, a_list, n);
	else
		ft_print_int(conv, a_list, n);
}

void	ft_prep_ll_int(t_conv *conv, long long *i)
{
	if (conv->size == 'l')
		*i = (long)*i;
	if (*i < 0)
	{
		conv->hassign = 1;
		conv->sign = '-';
	}
	conv->length = ft_putint_ll_size(*i);
	if (conv->precision != -2)
		conv->padzero = 0;
	if (conv->precision == -2 ||
		(conv->precision < conv->length && *i != 0))
		conv->precision = conv->length;
}

void	ft_print_ll_int(t_conv *conv, va_list a_list, int *n)
{
	long long	i;

	i = va_arg(a_list, long long);
	ft_prep_ll_int(conv, &i);
	if (conv->hassign && (conv->padzero || conv->leftj))
		ft_putchar_n_fd(conv->sign, 1, n);
	if (conv->leftj)
	{
		ft_pad_width(conv->precision, conv->length, '0', n);
		if (conv->precision)
			ft_putint_ll_n_fd(i, n);
	}
	if (conv->padzero && !conv->leftj)
		ft_pad_width(conv->width, conv->precision + conv->hassign, '0', n);
	else
		ft_pad_width(conv->width, conv->precision + conv->hassign, ' ', n);
	if (!conv->leftj)
	{
		if (conv->hassign && !conv->padzero)
			ft_putchar_n_fd(conv->sign, 1, n);
		ft_pad_width(conv->precision, conv->length, '0', n);
		if (conv->precision)
			ft_putint_ll_n_fd(i, n);
	}
}

void	ft_prep_ll_uint(t_conv *conv, unsigned long long *i)
{
	conv->length = ft_putuint_ll_size(*i);
	if (conv->precision != -2)
		conv->padzero = 0;
	if (conv->precision == -2 ||
		(conv->precision < conv->length && *i != 0))
		conv->precision = conv->length;
}

void	ft_print_ll_uint(t_conv *conv, va_list a_list, int *n)
{
	unsigned long long	i;

	i = va_arg(a_list, unsigned long long);
	ft_prep_ll_uint(conv, &i);
	if (conv->leftj)
	{
		ft_pad_width(conv->precision, conv->length, '0', n);
		if (conv->precision)
			ft_putuint_ll_n_fd(i, n);
	}
	if (conv->padzero && !conv->leftj)
		ft_pad_width(conv->width, conv->precision, '0', n);
	else
		ft_pad_width(conv->width, conv->precision, ' ', n);
	if (!conv->leftj)
	{
		ft_pad_width(conv->precision, conv->length, '0', n);
		if (conv->precision)
			ft_putuint_ll_n_fd(i, n);
	}
}
