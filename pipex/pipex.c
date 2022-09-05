/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:53:08 by amsryan           #+#    #+#             */
/*   Updated: 2022/08/15 12:58:25 by amsryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	find_paths(t_data *val, char *pt)
{
	int	i;

	i = 5;
	while (i--)
		pt++;
	val->path = ft_split(pt, ':');
	val->cmd_path = ft_split(pt, ':');
}

static void	pars_cmd(t_data *val, char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!av[2] || !av[3] || (av[2] && !av[2][0]) || (av[3] && !av[3][0]))
		ft_print_er("No detected cmd!\n", val);
	val->cmd1 = ft_split(av[2], ' ');
	val->cmd2 = ft_split(av[3], ' ');
	cmd_check(val);
}

static void	managing_files(t_data *val, char **av, char **env)
{
	int	fd1;
	int	fd2;

	fd1 = open(av[1], O_RDONLY);
	if (fd1 < 0)
		ft_print_error(4, val);
	fd2 = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd2 < 0)
		ft_print_error(4, val);
	mng_proc(val, fd1, fd2, env);
}

int	main(int argc, char **argv, char **env)
{
	t_data	val;

	val.path = NULL;
	val.cmd_path = NULL;
	val.cmd1 = NULL;
	val.cmd2 = NULL;
	if (argc == 5)
	{
		while (env[val.path_place]
			&& ft_strncmp("PATH=", env[val.path_place], 5) != 0)
			val.path_place++;
		if (env[val.path_place] == NULL)
			ft_print_error(2, &val);
		find_paths(&val, env[val.path_place]);
		pars_cmd(&val, argv);
		managing_files(&val, argv, env);
		free_val(&val);
	}
	else
		ft_print_error(1, &val);
	return (0);
}
