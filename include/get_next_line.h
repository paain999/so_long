/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:13:13 by dajimene          #+#    #+#             */
/*   Updated: 2023/10/10 10:34:08 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE_H
#	define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#	define BUFFER_SIZE 100
# endif

# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>


char	*get_next_line(int fd);
char	*ft_strjoin_gnl(char *stash, char *buff);
int		ft_strlen_gnl(char *str);
//char	*ft_strdup_gnl(char *s);
char	*ft_strchr_gnl(char *str, int c);

#endif