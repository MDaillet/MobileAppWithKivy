/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaillet <mdaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 11:32:48 by mdaillet          #+#    #+#             */
/*   Updated: 2021/03/15 19:27:51 by mdaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void ft_putchar(char c)
{
	write(1, &c, 1);
}

static int	ft_contain_until(char c, const char *s, int max_i)
{
	int i = 0;
	while (i < max_i && s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static void ft_inter(const char *s1, const char *s2)
{
	int i = 0;

	while (s1[i])
	{
		if (!ft_contain_until(s1[i], s1, i) && ft_contain_until(s1[i], s2, 10000))
			ft_putchar(s1[i]);
		i++;
	}
}

int main(int ac, char **av)
{
	if (ac == 3)
		ft_inter(av[1], av[2]);
	ft_putchar ('\n');
	return (0);
}
