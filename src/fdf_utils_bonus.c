/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohilali <mohilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:16:01 by mohilali          #+#    #+#             */
/*   Updated: 2024/01/24 10:23:36 by mohilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (NULL);
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(char *s, int c)
{
	unsigned int			i;
	unsigned char			x;

	if (!s)
		return (NULL);
	x = (unsigned char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == x)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == x)
		return ((char *) &s[i]);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (len);
	while (s[len])
		len++;
	return (len);
}

void	ft_free(char **arr)
{
	int	len;

	len = 0;
	if (!arr)
		return ;
	while (arr[len] != NULL)
	{
		free(arr[len]);
		len++;
	}
	free(arr);
	arr = NULL;
}
