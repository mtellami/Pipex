/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:43:03 by mtellami          #+#    #+#             */
/*   Updated: 2022/11/29 14:47:01 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	out_exec(int *fd, char **av, t_data data)
{
	int	i;

	close(fd[1]);
	i = open(av[4], O_CREAT | O_RDWR, 0777);
	if (i == -1)
		errors("Error : fail access files");
	if (dup2(fd[0], STDIN_FILENO) == -1)
		errors("Error");
	close(fd[0]);
	if (dup2(i, STDOUT_FILENO) == -1)
		errors("Error");
	close(i);
	execve(data.path, data.cmd, NULL);
}
