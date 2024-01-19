/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohilali <mohilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:17:15 by mohilali          #+#    #+#             */
/*   Updated: 2024/01/10 17:01:57 by mohilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

static int value_in_base(char c, const char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			break;
		i++;
	}
	if (base[i] != '\0')
		return(i);
	else
		return (-1);
}

static int check_base(const char *s)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (s[0] == '\0' || s[1] == '\0')
		return (1);
	while (s[i])
	{
		if (s[i] == '-' || s[i] == '+')
			return (1);
		if (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
			return (1);
		j = i + 1;
		while (s[j])
		{
			if (s[j] == s[i])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

unsigned int atoi_base(const char *s, const char *base)
{
	int nbr;
	int i;
	char *str = "0x\0";

	i = 0;
	nbr = 0;
	if (!check_base(base))
	{
		while (s[i] == ' ' && (s[i] >= 9 && s[i] <= 13))
			i++;
		if (!ft_strncmp(s, str, 2) && !ft_strncmp(base, "0123456789ABCDEF", 16))
			i += 2;
		while (s[i] != '\0')
		{
			if (value_in_base(ft_toupper(s[i]), base) >= 0)
				nbr = nbr * ft_strlen(base) + value_in_base(ft_toupper(s[i]), base);
			else
				break;
			i++;
		}
	}
	return (nbr);
}