/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_treat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomaris <tkomaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 19:47:35 by tkomaris          #+#    #+#             */
/*   Updated: 2021/09/27 16:14:23 by mdaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

static int ft_int_put(char *int_to_char, int saved_int, t_flag flag)
{
    int char_count;

    char_count = 0;
    if (saved_int < 0 && flag.dot >= 0 && saved_int != -2147483648)
		ft_putchar('-');
    if (flag.dot >= 0)
        char_count += ft_width_treat(flag.dot - 1, ft_strlen(int_to_char) - 1, 1);
    char_count += ft_cnstrn_and_prnt(int_to_char, ft_strlen(int_to_char));
    return (char_count);
}

static int ft_int_adj(char *int_to_char, int saved_int, t_flag flag)
{
    int char_count;

    char_count = 0;
    if (flag.minus == 1)
        char_count += ft_int_put(int_to_char, saved_int, flag);
    if ((flag.dot >= 0) && ((size_t)flag.dot < ft_strlen(int_to_char)))
        flag.dot = ft_strlen(int_to_char);
    if (flag.dot >= 0)
    {
        flag.width -= flag.dot;
        char_count += ft_width_treat(flag.width, 0, 0);
    }
    else
        char_count += ft_width_treat(flag.width, ft_strlen(int_to_char), flag.zero);
    if (flag.minus == 0)
        char_count += ft_int_put(int_to_char, saved_int, flag);
     return (char_count);
}

int ft_int_treat(int args, t_flag flag)
{
    int i;
    int saved_int;
    char *int_to_char;
	
	i = 0;
	if (flag.dot == 0 && args == 0)
	{
		i = i + ft_width_treat(flag.width, 0, 0);
		return (i);
	}
	saved_int = args;
	if (args != -2147483648 && args < 0 && (flag.dot >= 0 || flag.zero == 1))
    {
        if (flag.zero == 1 && flag.dot == -1)
            ft_cnstrn_and_prnt("-", 1);
        args *= -1;
        flag.zero = 1;
        flag.width--;
        i++;
    }
    int_to_char = ft_itoa(args);
    i += ft_int_adj(int_to_char, saved_int, flag);
    free(int_to_char);
    return (i);
}
