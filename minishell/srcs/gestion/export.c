/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corozco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 02:32:22 by corozco           #+#    #+#             */
/*   Updated: 2020/08/10 05:12:58 by corozco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Elle tri la liste export
*/

void		range_export(t_lists *la)
{
	t_lists	*tmp;
	t_lists	*tmp1;
	t_lists	*tmp3;
	char	*s1;
	char	*s2;

	tmp = la;
	while (tmp->next != NULL)
	{
		tmp3 = tmp;
		tmp1 = tmp->next;
		while (tmp1 != NULL)
		{
			if (ft_strcmp(tmp1->name, tmp3->name) < 0)
				tmp3 = tmp1;
			tmp1 = tmp1->next;
		}
		s1 = tmp->name;
		s2 = tmp->data;
		tmp->name = tmp3->name;
		tmp->data = tmp3->data;
		tmp3->name = s1;
		tmp3->data = s2;
		tmp = tmp->next;
	}
}

char			*search_key(char *str)
{
	char		*ss;
	char		*tmp;

	tmp = ft_strchr(str, '=');
	if (tmp != NULL)
	{
		str[tmp - str] = 0;
		if (!(ss = ft_strdup(str)))
			exit(1);
		str[(int)ft_strlen(str)] = '=';
	}
	else 
		if (!(ss = ft_strdup(str)))
			exit(1);
	return (ss);
}
/*
int				search_env(char *str, t_temp *tmp)
{
	char		*ss;
	return (ret);
}
*/
static int	search_equal(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '=')
			return (1);
	}
	return (0);
}

int			check_env(char *str)
{
	int		i;

	if ((ft_isalpha(str[0]) == 0) && str[0] != '_')
			return (-1);
	i = 1;
	while (str[i] && str[i] != '=')
	{
		if (ft_isalpha(str[1]) || str[0] != '_')
			i++;
		else
			return (-1);
	}
	return (0);
}

void		gestion_export(t_temp *tmp)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	while (tmp->strcmd[i])
		i++;
	if (i == 1)
	{
		range_export(tmp->exportenv);
		print_list(tmp->exportenv);
	}
	else
	{
		i = 0;
		while (tmp->strcmd[++i])
		{
			if (check_env(tmp->strcmd[i]) != 0)
			{
				ft_printf("minishell: export: `%s': not a valid identifier\n", tmp->strcmd[i]);
				break ;
			}
			//chercher si la env existe.
			if ((ret = search_equal(tmp->strcmd[i])) == 1)
			{
				add_list_front(&tmp->varenv, tmp->strcmd[i], NULL);
				add_list_front(&tmp->exportenv, tmp->strcmd[i], NULL);
			}
			else
				add_list_front(&tmp->exportenv, tmp->strcmd[i], "");
		}
	}
}