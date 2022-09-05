/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:43:22 by amsryan           #+#    #+#             */
/*   Updated: 2022/08/10 18:34:26 by amsryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_val(t_data *val)
{
	int	j;

	j = 0;
	if (val->path && val->path[0])
	{
		while (val->path[j])
		{
			free(val->path[j]);
			j++;
		}
		free(val->path);
	}
	j = 0;
	if (val->cmd_path && val->cmd_path[0])
	{
		while (val->cmd_path[j])
		{
			free(val->cmd_path[j]);
			j++;
		}
		free(val->cmd_path);
	}
	freeing_cmd(val);
}

void	freeing_cmd(t_data *val)
{
	int	j;

	j = 0;
	if (val->cmd1 && val->cmd1[0])
	{
		while (val->cmd1[j])
		{
			free(val->cmd1[j]);
			j++;
		}
		free(val->cmd1);
	}
	j = 0;
	if (val->cmd2 && val->cmd2[0])
	{
		while (val->cmd2[j])
		{
			free(val->cmd2[j]);
			j++;
		}
		free(val->cmd2);
	}
}

void	ft_print_er(char *s, t_data *val)
{
	int	i;

	i = ft_strlen(s);
	write(2, s, i);
	free_val(val);
	exit(1);
}

void	ft_print_error(int i, t_data *val)
{
	if (i == 1)
		ft_print_er("Not enough arguments!\n", val);
	if (i == 2)
		ft_print_er("No detected path!\n", val);
	if (i == 3)
		ft_print_er("No detected cmd!\n", val);
	if (i == 4)
		ft_print_er("Couldn't open file!\n", val);
	if (i == 5)
		ft_print_er("Couldn't open child process!\n", val);
	if (i == 6)
		ft_print_er("Couldn't properly run the pipe()!\n", val);
	if (i == 7)
		ft_print_er("Couldn't properly run the execve()!\n", val);
}
