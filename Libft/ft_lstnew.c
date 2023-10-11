/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:02:38 by dajimene          #+#    #+#             */
/*   Updated: 2023/05/16 14:32:28 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *new_node;
	
	new_node = (t_list *)malloc(sizeof(t_list));
	if(!new_node)
		return (NULL);
	new_node->next = NULL;
	new_node->content = (void *)content;
	return (new_node);
}