/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 08:25:27 by abquaoub          #+#    #+#             */
/*   Updated: 2024/05/04 17:33:53 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (0);
	new_node->content = ft_strtrim(content, " ");
	new_node->next = NULL;
	new_node->new_list = NULL;
	new_node->x = 0;
	new_node->flag2 = 0;
	new_node->in = 0;
	new_node->out = 1;
	return (new_node);
}
