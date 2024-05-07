/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 03:16:22 by abquaoub          #+#    #+#             */
/*   Updated: 2024/05/07 09:43:03 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char	*ft_strdup_if(char *str, char c)
{
	char	*new_str;
	int		i;
	int		j;

	new_str = (char *)malloc(sizeof(char) * ft_strlen(str));
	if (!new_str)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		new_str[j] = str[i];
		i++;
		j++;
	}
	new_str[i] = '\0';
	return (new_str);
}
t_list	*ft_create_var(char *command, char c)
{
	char	*new_command;
	t_list	*list_command;

	new_command = (char *)malloc(sizeof(char) * ft_strlen(command));
	list_command = NULL;
	new_command = ft_strdup_if(command, c);
	ft_lstadd_back(&list_command, ft_lstnew((char *)new_command));
	free(new_command);
	return (list_command);
}

void	ft_if_exist_var_echo(t_list *env, t_list *head)
{
	t_list	*temp_node;
	t_list	*temp_env;
	char	**result;
	int		i;

	temp_node = head;
	temp_env = env;
	while (temp_node)
	{
		while (temp_env)
		{
			if (strcmp((char *)temp_env->key, (char *)temp_node->content) == 0)
			{
				result = ft_split((char *)temp_env->value, ' ');
				i = 0;
				while (result[i])
				{
					printf("%s ", result[i]);
					i++;
				}
			}
			temp_env = temp_env->next;
		}
		temp_env = env;
		temp_node = temp_node->next;
	}
	temp_node = head;
	temp_env = env;
}

int	ft_found_dolar(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			return (i);
		i++;
	}
	return (0);
}

void	ft_echo(t_list *env, char **command)
{
	t_list	*temp;
	int		i;
	int		flag_op;
	int		flag;
	char	*var1;
	char	*var2;

	temp = NULL;
	flag_op = 0;
	flag = 0;
	i = 1;
	while (command[i])
	{
		if (strcmp(command[i], "-n") == 0)
		{
			flag_op = 1;
			i += 1;
		}
		if (ft_strchr_edit(command[i], '$') == 1)
		{
			var1 = ft_substr(command[i], 0, ft_found_dolar(command[i]));
			if (!ft_strtrim(var1, " "))
				printf("%s ", var1);
			else
				printf("%s", var1);
			var2 = ft_substr(command[i], ft_found_dolar(command[i]),
					ft_strlen(command[i]));
			temp = ft_create_var(var2, '$');
			ft_if_exist_var_echo(env, temp);
			flag = 1;
		}
		else
			printf("%s ", command[i]);
		flag = 0;
		i++;
	}
	if (flag_op == 1)
		return ;
	else
		printf("\n");
}
