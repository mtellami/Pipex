/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 13:09:13 by mtellami          #+#    #+#             */
/*   Updated: 2022/11/27 13:09:41 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execution(char *cmd, char **env)
{
	char **command;
	char	*path;

	command = ft_split(cmd, ' ');
	if (!command)
		errors("Error");
	path = get_path(command[0], env);
	if (!path)
		errors("command not found");
	if (execve(path, command + 1, NULL) == -1)
		errors("Error executing");
	free_arr(command);
	free(path);
	exit(EXIT_SUCCESS);
}
