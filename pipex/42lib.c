/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42lib.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:00:58 by amsryan           #+#    #+#             */
/*   Updated: 2022/08/10 15:49:52 by amsryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] != '\0' && s2[i] == '\0')
			return (1);
		if (s1[i] > s2[i])
			return (1);
		else if (s1[i] < s2[i])
			return (-1);
		i++;
	}
	return (0);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (str)
		if (!str[i])
			return (0);
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t l)
{
	size_t	lns;
	char	*str;
	char	*ptr;
	size_t	j;

	str = (char *)s;
	j = 0;
	lns = ft_strlen(str);
	if (start > lns || l == 0)
		j = 0;
	else if (lns - start + 1 > l)
		j = l;
	else
		j = lns - start;
	ptr = (char *)malloc((1 + j));
	if (!ptr)
		return (0);
	lns = 0;
	while (str[start] && lns < j)
		ptr[lns++] = str[start++];
	ptr[lns] = '\0';
	return (ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s;
	int		i;
	int		j;

	s = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	i = 0;
	j = 0;
	while (*s1 && s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	while (*s2 && s2[j])
	{	
		s[i] = s2[j];
		i++;
		j++;
	}
	if (s1)
		free(s1);
	s[i] = '\0';
	return (s);
}
