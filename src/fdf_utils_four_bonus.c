/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils_four_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohilali <mohilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:41:21 by mohilali          #+#    #+#             */
/*   Updated: 2024/01/24 10:23:44 by mohilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

char	*ft_strdup(const char *s1)
{
	char			*dest;
	unsigned int	i;

	if (!s1)
		return (NULL);
	dest = (char *)malloc(ft_strlen(s1) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char				*res;
	unsigned int		i;
	unsigned int		j;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	i = 0;
	j = 0;
	res = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (s1[j])
		res[i++] = s1[j++];
	j = 0;
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n-- && !s2 && !s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	char	*s;
	int		sign;
	long	nbr;

	sign = 1;
	s = (char *) str;
	while (*s == ' ' || *s == '\n' || *s == '\v' || *s == '\f'
		|| *s == '\t' || *s == '\r')
		s++;
	if (*s == '+')
		s++;
	else if (*s == '-')
	{
		sign = -1;
		s++;
	}
	nbr = 0;
	while (*s >= '0' && *s <= '9')
	{
		nbr = nbr * 10 + (*s - '0');
		s++;
	}
	return (nbr * sign);
}
