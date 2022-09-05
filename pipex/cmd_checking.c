/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_checking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 15:41:37 by amsryan           #+#    #+#             */
/*   Updated: 2022/08/16 16:49:52 by amsryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmd2_check(t_data *val)
{
	int	i;

	i = -1;
	while (val->path[++i])
	{
		if (access(val->cmd2[0], X_OK | R_OK) == 0)
		{
			val->cmd2_path = val->cmd2[0];
			break ;
		}
		if (val->path[i] == NULL)
			ft_print_error(3, val);
		val->path[i] = ft_strjoin(val->path[i], "/");
		val->path[i] = ft_strjoin(val->path[i], val->cmd2[0]);
		val->cmd2_path = val->path[i];
		if (access(val->path[i], X_OK | R_OK) == 0)
			break ;
	}
}

void	cmd_check(t_data *val)
{
	int	i;

	i = -1;
	while (val->cmd_path[++i])
	{
		if (access(val->cmd1[0], X_OK | R_OK) == 0)
		{
			val->cmd1_path = val->cmd1[0];
			break ;
		}
		if (val->cmd_path[i] == NULL)
			ft_print_error(3, val);
		val->cmd_path[i] = ft_strjoin(val->cmd_path[i], "/");
		val->cmd_path[i] = ft_strjoin(val->cmd_path[i], val->cmd1[0]);
		val->cmd1_path = val->cmd_path[i];
		if (access(val->cmd_path[i], X_OK | R_OK) == 0)
			break ;
	}
	cmd2_check(val);
}
