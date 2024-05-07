// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   save.c                                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/02/13 03:16:22 by abquaoub          #+#    #+#             */
// /*   Updated: 2024/05/05 17:15:07 by mmad             ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "ft_minishell.h"

// void	ft_free(char **str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		free(str[i]);
// 		i++;
// 	}
// 	free(str);
// }

// char *ft_strdup_edit(char *str, char c, t_list *flag)
// {
// 	char *new_str = (char *)malloc(sizeof(char) * ft_strlen(str));
// 	if (!new_str)
// 		return (NULL);
	
// 	flag->flag2 = 0;
// 	// printf("(ft_strdup_edit) flag at certain position %d\n", flag->flag2);
// 	int i;
// 	int j;
// 	i = 0;
// 	j = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == c)
// 		{
// 			flag->flag2 = 1;
// 			i++;
// 		}
// 		new_str[j] = str[i];
// 		i++;
// 		j++;
// 	}
// 	new_str[i] = '\0';
// 	// printf("(ft_strdup_edit) flag at certain position %d\n", flag->flag2);
// 	return (new_str);
	
// }
// t_list * ft_creat_var(char **command)
// {
// 	char **new_command = (char **)malloc(sizeof(char *) * 10);
// 	t_list *list_command = ft_lstnew(" ");
// 	t_list *temp = list_command;
// 	int i;
// 	i = 0;	
// 	while (command[i])
// 	{
// 		if (i >= 1)
// 			printf("(ft_strdup_edit) flag at certain position %d\n", temp->flag2);
// 		new_command[i] = ft_strdup_edit(command[i], '$', temp);
// 		// if (list_command->flag2 == 1)
// 		// 	list_command->flag2 = 1;
// 		// else
// 		// 	list_command->flag2 = 0;
			
// 		// printf("flag at certain position %d\n", list_command->flag2);
// 		if (i >= 1)
// 			printf("(ft_strdup_edit) flag at certain position %d\n", temp->flag2);
// 		ft_lstadd_back(&temp, ft_lstnew((char *)new_command[i]));
// 		i++;
// 	}
// 	t_list *test = temp;
// 	while (test)
// 	{
// 		printf("content %s flag %d\n", (char *)test->content, test->flag2);
// 		test = test->next;
// 	}	// exit(0);
	
// 	// new_command[i] = NULL;
// 	// i = 0;
// 	// while (new_command[i])
// 	// {
// 	// 	i++;
// 	// }
// 	temp = temp->next->next;
// 	list_command = temp;
	
// 	// ft_display(temp);
// 	// printf("OUT (ft_strdup_edit) flag at certain position %d -- %s\n", list_command->flag2, (char *)list_command->content);
// 	return list_command;
// }

// void	ft_if_exist_var_echo(t_list *env, t_list *head)
// {

// 	t_list	*temp;
// 	t_list	*temp0;

// 	temp = head;
// 	temp0 = env;
// 	while (temp)
// 	{
// 		printf("content %s flag %d\n", (char *)temp->content, temp->flag2);
// 		temp = temp->next;
// 	}
	
// 	exit(0);
// 	while (temp)
// 	{
// 		while (temp0)
// 		{
// 			if (strcmp((char *)temp0->key, (char *)temp->content) == 0 && temp->flag2 == 1)
// 			{
// 				printf("%s ", (char *)temp0->value);
// 			}
// 			temp0 = temp0->next;
// 		}
// 		temp0 = env;
// 		if (temp->flag2 == 0)
// 			printf("%s ", (char *)temp->content);
// 		temp = temp->next;
// 	}
// 	temp = head;
// 	temp0 = env;
// 	printf("\n");
// }

// void	ft_print_list_if(t_list *head)
// {
// 	// printf("-----------------------------------------\n");
// 	while (head)
// 	{
// 		printf("%s\n", (char *)head->key);
// 		head = head->next;
// 	}
// 	// printf("-----------------------------------------\n");
// }

// int ft_if_dolar_exist(char *str, char c)
// {
// 	int i;
// 	int flag = 0;
// 	i = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == c)
// 			flag = 1;
// 		i++;		
// 	}
// 	if (flag == 1)
// 		return (1);
// 	return (0);
// }
// void ft_echo(t_list *env, char **command)
// {
// 	// (void)env;
// 	ft_print_list_if(env);

// 	int i;
// 	int flag = 0;
// 	i = 1;
// 	while (command[i])
// 	{
// 		if (ft_if_dolar_exist(command[i], '$') == 1)
// 			flag = 1;
// 		printf("[%s] flag %d\n", command[i], flag);
// 		flag = 0;
// 		i++;
// 	}	
// }

// /*
// 	// exit(0);
// 	// t_list *list_command = ft_creat_var(command);
// 	// t_list	*temp = list_command;
// 	// while (temp)
// 	// {
// 	// 	printf("content %s flag %d\n", (char *)temp->content, temp->flag2);
// 	// 	temp = temp->next;
// 	// }
// 	// exit(0);
// 	// // list_command->flag2 = 0;
// 	// // ft_display(list_command->next->next);
// 	// ft_if_exist_var_echo(env, list_command); 
//  */


/*
	// exit(0);
	// t_list *list_command = ft_creat_var(command);
	// t_list	*temp = list_command;
	// while (temp)
	// {
	// 	printf("content %s flag %d\n", (char *)temp->content, temp->flag2);
	// 	temp = temp->next;
	// }
	// exit(0);
	// // list_command->flag2 = 0;
	// // ft_display(list_command->next->next);
	// ft_if_exist_var_echo(env, list_command); 
 */

/*
mmad@c4r8p8:~/Desktop$ echo mohammed $    // printf("new_command [%s]    // printf("new_command [%s
bash: syntax error near unexpected token `('

 */

// t_list * ft_sort_name(t_list *head)
// {

// 	t_list *temp = head;
// 	t_list *next_temp;
// 	t_list *buff = NULL;

// 	while (temp->next)
// 	{
// 		next_temp = temp->next;
// 		while (next_temp)
// 		{
// 			if (strcmp((char *)temp, (char *)next_temp) > 0)
// 			{
// 				strcpy((char *)buff, (char *)temp);
// 				strcpy((char *)temp, (char *)next_temp);
// 				strcpy((char *)next_temp, (char *)buff);
// 			}
// 			next_temp = next_temp->next;
// 		}
// 		temp = temp->next;
// 	}
// 	return (head);
// }