#include <unistd.h>

static void ft_putchar(char c)
{
	write(1, &c, 1);
}

static int ft_contain(char c, const char *s, int i_max)
{
	int i = 0;

	while (s[i] && i < i_max)
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static void ft_union(const char *s1, const char *s2)
{
	int i = 0;
	
	while (s1[i])
	{
		if (!ft_contain(s1[i], s1, i))
			ft_putchar(s1[i]);
		i++;
	}
	i = 0;
	while (s2[i])
	{
		if (!ft_contain(s2[i], s2, i) && !ft_contain(s2[i], s1, 10000))
			ft_putchar(s2[i]);
		i++;
	}
}

int main(int ac, char **av)
{
	if (ac == 3)
		ft_union(av[1], av[2]);
	ft_putchar('\n');
	return (0);
}
