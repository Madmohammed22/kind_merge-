/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 12:20:44 by mmad              #+#    #+#             */
/*   Updated: 2024/05/06 21:28:34 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_cd(t_list *head)
{
	char *path = (char *)malloc(sizeof(char) * 100);
	if (!path)
		return ;
	t_list *temp = head;
	path = getcwd(path, 1024);
	if (ft_lstsize(temp) == 2)
	{  
		char *new_dir = ft_strdup((char *)temp->next->content);
		if (strcmp((char *)temp->next->content, "..") != 0 && chdir(new_dir) != 0 )
		{
            perror(ft_strjoin("minishell: cd: " , (char *)temp->next->content));
		    return ;
		}
		if (strcmp((char *)temp->next->content, "..") == 0)
		{
	        path = getcwd(path, 1024);  
            chdir("..");
	        path = getcwd(path, 1024);
            chdir(path);
		}
		free(new_dir);
	}
    else if (ft_lstsize(temp) > 2)
        printf("minishell: cd: too many arguments\n");
	else
		chdir("/nfs/homes/mmad");
	free(path);
}