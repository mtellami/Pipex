/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:43:03 by mtellami          #+#    #+#             */
/*   Updated: 2022/11/27 13:10:51 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	out_exec(int *fd, char **av, char **environ)
{
	int	i;

	i = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0007);
	if (i == -1)
		errors("Error : fail access files");
	if (dup2(fd[0], STDIN_FILENO) == -1)
		errors("Error");
	if (dup2(i, STDOUT_FILENO) == -1)
		errors("Error");
	close(fd[0]);
	close(fd[1]);
	close(i);
	execution(av[3], environ);
}