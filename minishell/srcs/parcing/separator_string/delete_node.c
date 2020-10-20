/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 17:54:33 by lryst             #+#    #+#             */
/*   Updated: 2020/10/20 15:46:28 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lstdelone_cmd(t_cmd *lst)
{
	if (lst)
	{
		if (lst->input)
			ft_free(lst->input);
		if (lst->output)
			ft_free(lst->output);
		free(lst);
	}
}

void	remove_space_node(t_cmd **cmd)
{
	t_cmd *save;
	t_cmd *tmp;

	tmp = *cmd;
	while (tmp)
	{
		save = NULL;
		if (tmp->next && (ft_strcmp(tmp->next->output, " ") == 0) &&
		(tmp->next->next == NULL ||
		(ft_strcmp(tmp->next->next->output, " ") == 0)))
		{
			save = tmp->next->next;
			ft_lstdelone_cmd(tmp->next);
			tmp->next = save;
		}
		else
			tmp = tmp->next;
	}
}

void	remove_all_space_node(t_cmd **cmd)
{
	t_cmd *save;
	t_cmd *tmp;

	tmp = *cmd;
	while (tmp)
	{
		save = NULL;
		if (tmp->next && (ft_strcmp(tmp->next->output, " ") == 0))
		{
			save = tmp->next->next;
			ft_lstdelone_cmd(tmp->next);
			tmp->next = save;
		}
		else
			tmp = tmp->next;
	}
}
