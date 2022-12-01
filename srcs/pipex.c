/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:29:27 by mtellami          #+#    #+#             */
/*   Updated: 2022/11/30 08:08:42 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	wait_close(int *fd, int *pid)
{
	close(fd[0]);
	close(fd[1]);
	waitpid(pid[0], NULL, 0);
	waitpid(pid[1], NULL, 0);
}

int	main(int ac, char **av)
{
	t_data	data[2];
	int		fd[2];
	int		pid[2];

	if (ac != 5)
		errors("Usage: ./pipex file1 \"cmd1\" \"cmd2\" file2");
	data[0] = get_data(av[2]);
	data[1] = get_data(av[3]);
	if (pipe(fd) == -1)
		errors("Error");
	pid[0] = fork();
	if (pid[0] == -1)
		errors("Error");
	if (pid[0] == 0)
		in_exec(fd, av, data[0]);
	pid[1] = fork();
	if (pid[1] == -1)
		errors("Error");
	if (pid[1] == 0)
		out_exec(fd, av, data[1]);
	wait_close(fd, pid);
	return (EXIT_SUCCESS);
}
