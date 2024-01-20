/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils_one.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohilali <mohilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:14:56 by mohilali          #+#    #+#             */
/*   Updated: 2024/01/08 17:37:49 by mohilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	*get_theline(int fd, char *str, char *buffer)
{
	ssize_t	b_read;
	char	*tmp;

	b_read = 1;
	while (b_read > 0)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == -1)
			return (free(str), NULL);
		else if (b_read == 0)
			break ;
		buffer[b_read] = 0;
		if (!str)
		{
			str = ft_strdup("");
			if (!str)
				return (NULL);
		}
		tmp = str;
		str = ft_strjoin(tmp, buffer);
		free(tmp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (str);
}

static char	*ft_getrest(char *line)
{
	char	*left;
	ssize_t	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == 0 || line[1] == 0)
		return (NULL);
	left = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (!left || *left == 0)
	{
		free(left);
		left = NULL;
	}
	line[i + 1] = 0;
	return (left);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0
		|| BUFFER_SIZE >= 2147483647)
		return (free(str), str = NULL, NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1));
	if (!buffer)
	{
		buffer = NULL;
		return (NULL);
	}
	line = get_theline(fd, str, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	str = ft_getrest(line);
	return (line);
}
