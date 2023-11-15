/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 01:22:26 by dajimene          #+#    #+#             */
/*   Updated: 2023/11/15 01:22:35 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	*ft_memset(void *src, int c, size_t len)
{
	size_t			count;
	unsigned char	*buff;

	count = 0;
	buff = (unsigned char *)src;
	while (count < len)
		buff[count++] = c;
	return (src = buff);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == (char)c)
		return ((char *)&str[i]);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		newlen;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
		s1 = ft_strdup("");
	if (*s1 == '\0' && *s2 == '\0')
		return (ft_strdup(""));
	newlen = ft_strlen(s1) + ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * newlen + 1);
	if (!result)
		return (NULL);
	while (i <= newlen && s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	while (i <= newlen && s2[j] != '\0')
		result[i++] = s2[j++];
	result[i] = '\0';
	free((char *)s1);
	return (result);
}
