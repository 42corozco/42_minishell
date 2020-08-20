/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corozco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 22:43:00 by corozco           #+#    #+#             */
/*   Updated: 2020/08/20 05:09:20 by corozco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			deletenode(t_lists *list, char *strkey)
{
	t_lists		*tmp;
	t_lists		*previous;

	if (list == NULL)
		return ;
	previous = list;
	if (ft_strcmp(previous->name, strkey) == 0)
	{
		list = previous->next;
		free(previous->name);
		(previous->data != NULL) ? free(previous->data) : 0;
		free(previous);
		return ;
	}
	tmp = previous->next;
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->name, strkey) == 0)
		{
			previous->next = tmp->next;
			free(tmp->name);
			(tmp->data != NULL) ? free(tmp->data) : 0;
			free(tmp);
			return ;
		}
		previous = tmp;
		tmp = tmp->next;
	}
}

void			gestion_unset(t_temp *tmp)
{
	int			i;
	int			ret;

	i = 0;
	while (tmp->strcmd[i])
		i++;
	if (i == 1)
		ft_printf("unset: not enough arguments\n");
	i = 0;
	while (tmp->strcmd[++i])
	{
		ret = check_env(tmp->strcmd[i], 0);
		if (ret == -1 || ret == 1)
			ft_printf("minishell: unset: `%s': not a valid identifier \n",
					tmp->strcmd[i]);
		else
			deletenode(tmp->varenv, tmp->strcmd[i]);
	}
}
