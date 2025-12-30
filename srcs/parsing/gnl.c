/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 01:09:01 by qupollet          #+#    #+#             */
/*   Updated: 2025/09/25 20:30:16 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static char	*ft_read_from_file(int fd, char *stash, char *buf)
{
	char	*tmp;
	int		nb_char;

	nb_char = 1;
	while (!ft_strchr(stash, '\n') && nb_char > 0)
	{
		nb_char = read(fd, buf, BUFFER_SIZE);
		if (nb_char == -1)
		{
			free(stash);
			return (NULL);
		}
		buf[nb_char] = 0;
		tmp = ft_strjoin(stash, buf);
		free(stash);
		if (!tmp)
			return (NULL);
		stash = tmp;
	}
	return (stash);
}

static char	*ft_get_line(char *stash)
{
	size_t		idx;
	size_t		size;
	char		*fstring;

	idx = 0;
	while (stash[idx] && stash[idx] != '\n')
		idx++;
	if (stash[idx] == '\n')
		idx++;
	size = idx;
	fstring = malloc(sizeof(char) * (size + 1));
	if (!fstring)
		return (NULL);
	idx = 0;
	while (idx < size)
	{
		fstring[idx] = stash[idx];
		idx++;
	}
	fstring[idx] = 0;
	return (fstring);
}

static char	*ft_remove_before_nl(char **stash)
{
	size_t		idx;
	size_t		size;
	char		*tmp;

	if (!stash || !*stash)
		return (NULL);
	idx = 0;
	size = ft_strlen(*stash);
	while ((*stash)[idx] != '\n' && (*stash)[idx] != 0)
		idx++;
	if ((*stash)[idx] == '\n')
		idx++;
	tmp = ft_substr(*stash, idx, size - idx);
	if (!tmp)
	{
		free(*stash);
		*stash = NULL;
		return (NULL);
	}
	free(*stash);
	*stash = tmp;
	return (*stash);
}

static int	ft_init(char **stash, char **buf)
{
	if (!*stash)
	{
		*stash = ft_strdup("");
		if (!*stash)
			return (-1);
	}
	*buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!*buf)
	{
		free(*stash);
		*stash = NULL;
		return (-1);
	}
	return (0);
}

char	*gnl(int fd)
{
	char			*buf;
	static char		*stash;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(stash), stash = NULL, NULL);
	if (ft_init(&stash, &buf) == -1)
		return (NULL);
	stash = ft_read_from_file(fd, stash, buf);
	free(buf);
	if (!stash)
		return (NULL);
	line = ft_get_line(stash);
	if (!line || line[0] == '\0')
	{
		free(line);
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = ft_remove_before_nl(&stash);
	if (!stash)
		return (free(line), NULL);
	return (line);
}
