/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 01:22:42 by dajimene          #+#    #+#             */
/*   Updated: 2023/12/28 13:27:47 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*ft_strnstr(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*s2 == '\0' || s1 == s2)
		return (NULL);
	while (s1[i] != '\0')
	{
		j = 0;
		while (s1[i + j] != '\0' && s2[j] == s1[i + j]
			&& s2[j] != '\0')
		{
			if (s2[j + 1] == '\0' && s1[i + j + 1] == '\0')
				return ((char *)s1 + i);
			j++;
		}
		i++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(src);
	i = 0;
	if (!dest || !src)
		return (0);
	if (!size)
		return (src_len);
	while (src[i] != '\0' && i + 1 < size)
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (src_len);
}

char	*ft_strdup(const char *s)
{
	char	*copy;
	char	*src;
	int		i;

	i = 0;
	src = (char *)s;
	copy = (char *)malloc(ft_strlen(src) + 1);
	if (!copy)
		return (NULL);
	while (src[i] != '\0')
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	strlen;
	char	*dest;
	char	*str;

	if (*s == '\0')
		return (ft_strdup(""));
	if ((size_t)start > ft_strlen(s))
		return (ft_strdup(""));
	strlen = ft_strlen(s);
	str = (char *)s + start;
	if (len > strlen && start == 0)
		len = strlen + 1;
	else if (len > strlen && start != 0)
		len = (strlen - start) + 1;
	else
		len++;
	dest = malloc(sizeof(char) * len);
	if (!dest)
		return (NULL);
	else
		ft_strlcpy(dest, str, len);
	return (dest);
}
