/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mng_files.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 17:30:57 by amsryan           #+#    #+#             */
/*   Updated: 2022/08/15 12:57:37 by amsryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	exe_file1(t_data *val, int fd1, char **env)
{
	dup2(val->end[1], 1);
	close(val->end[1]);
	close(val->end[0]);
	dup2(fd1, 0);
	close(fd1);
	if (execve(val->cmd1_path, val->cmd1, env) == -1)
		ft_print_error(7, val);
}

static void	exe_file2(t_data *val, int fd2, char **env)
{
	dup2(val->end[0], 0);
	close(val->end[1]);
	close(val->end[0]);
	dup2(fd2, 1);
	close(fd2);
	if (execve(val->cmd2_path, val->cmd2, env) == -1)
		ft_print_error(7, val);
}

void	mng_proc(t_data *val, int fd1, int fd2, char **env)
{
	if (pipe(val->end) < 0)
		ft_print_error(6, val);
	val->pid1 = fork();
	if (val->pid1 == 0)
		exe_file1(val, fd1, env);
	else if (val->pid1 == -1)
		ft_print_error(5, val);
	val->pid2 = fork();
	if (val->pid2 == 0)
		exe_file2(val, fd2, env);
	else if (val->pid2 == -1)
		ft_print_error(5, val);
	close (fd1);
	close (fd2);
	close (val->end[0]);
	close (val->end[1]);
	waitpid(val->pid1, NULL, 0);
	waitpid(val->pid2, NULL, 0);
}
