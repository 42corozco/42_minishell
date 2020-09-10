/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 16:54:35 by lryst             #+#    #+#             */
/*   Updated: 2020/09/10 02:41:44 by corozco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char 	*gestion_echo_option(char *str, char *arg)
{
	char *cmd;
	int i;
	int j;
	int save;

	i = 4;
	j = 0;
	if (ft_strcmp(arg, "-n") == 0)
		ft_strcmp(arg, "-n") == 0 ? i = 8 : 0;
	save = i;
	while (str[i++] != '\0')
		j++;
	if (!(cmd = (char*)malloc(sizeof(char) * j + 1)))
		return (NULL);
	i = save;
	j = 0;
	while (str[i] != '\0') 
		cmd[j++] = str[i++];
	cmd[j] = '\0';
	return (cmd);
}

void    gestion_echo(l_cmd *cmd)
{
	l_cmd *test;
	int n;

	test = cmd;
	n = 0;
	if (test->next != NULL)
	{

		test = test->next;
	}
	else
	{
		n = 1;
	}
	if (test->next != NULL)
		test = test->next;
	if (ft_strcmp(test->output, "-n") == 0)
	{
		test = test->next;
		if (test != NULL)
			test = test->next;
		n = 2;
	}
	if (n == 1)
	{
		write(1, "\n", 1);
		return ;
	}
	while (test)
	{
		ft_printf("%s", test->output);
		test = test->next;
	}
	//ft_free_double_tab(tab);
	if (n == 0)
		ft_printf("\n");
}

/* void	gestion_echo(char *str, char *arg)
{
	//char *cmd;
	//char **tab;
	int i;

	i = 4;
	if (ft_strcmp(str, "echo") != 0)
	{
		ft_strcmp(arg, "-n") == 0 ? i = 8 : 0;
		printf("i = %d\n", i);
		
		ft_printf("str = [%s]\n", str);
	}
	if (ft_strcmp(str, "echo") == 0 || ft_strcmp(arg, "-n") != 0)
		ft_printf("\n");
} */ 
