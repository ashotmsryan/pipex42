/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:54:27 by amsryan           #+#    #+#             */
/*   Updated: 2022/08/10 15:45:15 by amsryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct t_arg
{
	int			path_place;
	char		**path;
	char		**cmd1;
	char		**cmd2;
	char		**cmd_path;
	char		*cmd1_path;
	char		*cmd2_path;
	int			end[2];
	pid_t		pid1;
	pid_t		pid2;
}				t_data;
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(char *str);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t l);
char	*ft_strjoin(char *s1, char *s2);
void	mng_proc(t_data *val, int fd1, int fd2, char **env);
void	freeing_cmd(t_data *val);
void	free_val(t_data *val);
void	ft_print_error(int i, t_data *val);
void	cmd_check(t_data *val);
void	ft_print_er(char *s, t_data *val);

#endif
