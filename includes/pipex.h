/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:30:01 by mtellami          #+#    #+#             */
/*   Updated: 2022/11/27 13:16:15 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h> 
# include <sys/wait.h>
# include <stdio.h>

/* -------- Libft -------- */
void	ft_putendl_fd(char *str, int fd);
int		ft_strlen(char *str);
char	**ft_split(char *s, char c);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char c, char *s2);
char	*ft_strstr(char *str, char *to_find);

/* -------- Srcs -------- */
void	in_exec(int *fd, char **av, char **environ);
void	out_exec(int *fd, char **av, char **environ);
void	free_arr(char **str);
void	errors(char *str);
void	execution(char *cmd, char **env);
char 	*get_path(char *cmd, char **env);

#endif