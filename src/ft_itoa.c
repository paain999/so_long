/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 01:16:05 by dajimene          #+#    #+#             */
/*   Updated: 2023/11/15 10:32:08 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static	int	lenght(long int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n >= 1)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static	char	*cast(long int nbr, int len, char *str, int isneg)
{
	if (nbr != 0)
		str = malloc(len + 1 * sizeof(char));
	else
		return (ft_strdup("0"));
	if (!str)
		return (NULL);
	if (nbr < 0)
	{
		isneg++;
		nbr = -nbr;
	}
	while (--len)
	{
		str[len] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (isneg)
		str[0] = '-';
	else
		str[0] = nbr % 10 + '0';
	return (str);
}

char	*ft_itoa(int n)
{
	int			len;
	int			isneg;
	char		*str;
	long int	nbr;

	nbr = n;
	isneg = 0;
	len = lenght(nbr);
	str = NULL;
	str = cast(nbr, len, str, isneg);
	if (!str)
		return (0);
	return (str);
}
