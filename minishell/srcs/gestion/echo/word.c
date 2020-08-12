/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 21:45:38 by lryst             #+#    #+#             */
/*   Updated: 2020/08/12 21:50:19 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char			*word(char *str, int *i, char *tab)
{
	int count;
	int save;

	count = 0;
	save = *i;
	while (str[save] && str[save] != ' ')
	{
		save++;
		count++;
	}
	if (!(tab = (char*)malloc(sizeof(char) * count + 1)))
		return NULL;
	count = 0;
	while (*i < save)
		tab[count++] = str[(*i)++];
	tab[count] = '\0';
	return (tab);
}