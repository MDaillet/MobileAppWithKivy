/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_treat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomaris <tkomaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 17:42:26 by tkomaris          #+#    #+#             */
/*   Updated: 2021/09/27 16:32:01 by mdaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

static int ft_ptr_put(char *pointer, t_flag flag)
{
    int char_count;

    char_count = 0;
    char_count += ft_cnstrn_and_prnt("0x", 2);

    if (flag.dot >= 0)
    {
        char_count += ft_width_treat(flag.dot, ft_strlen(pointer), 1);
        char_count += ft_cnstrn_and_prnt(pointer, flag.dot);
    }
    else
        char_count += ft_cnstrn_and_prnt(pointer, ft_strlen(pointer));

    return (char_count);
}


int ft_ptr_treat(unsigned long long pointed, t_flag flag)
{
    int char_count;
    char *pointer;

    char_count = 0;

    if ((pointed == 0) && (flag.dot <= 0)) // Have to print "(nil)" when the pointer is null
    {
        char_count += ft_cnstrn_and_prnt("(nil)", 5); // 
        return (char_count += ft_width_treat(flag.width, 5, 0));
    }

    pointer = ft_ull_conv(pointed, 16);
    pointer = ft_strlower(pointer);
    
    if ((size_t)flag.dot < ft_strlen(pointer))
        flag.dot = ft_strlen(pointer);
    
    if (flag.minus == 1)
        char_count += ft_ptr_put(pointer, flag);
    char_count += ft_width_treat(flag.width, ft_strlen(pointer) + 2, 0);
    if (flag.minus == 0)
        char_count += ft_ptr_put(pointer, flag);
    
    free(pointer);
    return (char_count);
}
