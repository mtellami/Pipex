/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 15:27:50 by mtellami          #+#    #+#             */
/*   Updated: 2022/11/27 13:10:19 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	in_exec(int *fd, char **av, char **environ)
{
	int	i;

	i = open(av[1], O_RDONLY);
	if (i == -1)
		errors("Error : fail access files");
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		errors("Error");
	if (dup2(i, STDIN_FILENO) == -1)
		errors("Error");
	close(fd[0]);
	close(fd[1]);
	close(i);
	execution(av[2], environ);
}
