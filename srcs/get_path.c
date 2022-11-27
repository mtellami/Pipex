/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 12:18:54 by mtellami          #+#    #+#             */
/*   Updated: 2022/11/27 14:20:05 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_secure_paths(char **env)
{
	char	**tree;
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strstr(env[i], "PATH"))
		{
			tree = ft_split(env[i] + 5, ':');
			return (tree);
		}
		i++;
	}
	return (NULL);
}

char *get_path(char *cmd, char **env)
{
	char	*path;
	char	**tree;
	int		i;

	tree = get_secure_paths(env);
	if (!tree)
		return (NULL);
	i = 0;
	while (tree[i])
	{
		path = ft_strjoin(tree[i], '/', cmd);
		if (!access(path, F_OK))
		{
			free(tree);
			printf("%s\n", path);
			return (path);
		}
		free(path);
		i++;
	}
	free(tree);
	return (NULL);
}
