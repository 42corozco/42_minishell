/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_or_not.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 19:27:07 by lryst             #+#    #+#             */
/*   Updated: 2020/11/22 19:33:07 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		dup_or_not(t_temp *tmp)
{
	if (tmp->flag[1] == 1)
	{
		tmp->oldfd = dup(1);
		dup2(tmp->fd, 1);
	}
}
