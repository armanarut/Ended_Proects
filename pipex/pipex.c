/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 19:33:05 by akazarya          #+#    #+#             */
/*   Updated: 2022/05/28 19:36:08 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	here_doc(t_pipe *pip)
{
	char	*temp;

	pip->fd_in = open(pip->file_in, O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (pip->fd_in == -1)
		ft_exit(ERR_FILE, pip->file_in, 1);
	while (1)
	{
		write(2, "pipe heredoc>", ft_strlen("pipe heredoc>"));
		temp = mini_get_next_line(0);
		if (!temp)
			break ;
		if (!ft_strcmp(temp, pip->limit))
			break ;
		write(pip->fd_in, temp, ft_strlen(temp));
		write(pip->fd_in, "\n", 1);
		free(temp);
	}
	close (pip->fd_in);
}

char	*get_cmd(t_pipe *pip, char *cmd)
{
	int		i;
	char	*command;

	i = -1;
	while (pip->path[++i])
	{
		command = ft_strjoin(pip->path[i], cmd);
		if (access(command, X_OK) == 0)
			return (command);
		free(command);
	}
	return (NULL);
}

void	make_exec(t_pipe *pip, char **envp, int id)
{
	char	*command;

	pip->cmd_args = ft_split(pip->cmds[id], ' ');
	command = get_cmd(pip, pip->cmd_args[0]);
	if (!command)
		ft_exit(ERR_COMMAND, pip->cmd_args[0], 1);
	if (pip->here == 2)
		unlink(pip->file_in);
	execve(command, pip->cmd_args, envp);
	ft_exit(ERR_ARGUMENT, 0, 1);
}

void	cmd_pipe(t_pipe *pip, char **envp, int id)
{
	int	fd[2];
	int	pid;

	if (pipe(fd) == -1)
		ft_exit(ERR_PIPE, 0, 1);
	pid = fork();
	if (pid == -1)
		ft_exit(ERR_FORK, 0, 1);
	if (pid)
	{
		close(fd[1]);
		dup2(fd[0], 0);
		waitpid(pid, 0, 0);
	}
	else
	{
		close(fd[0]);
		dup2(fd[1], 1);
		make_exec(pip, envp, id);
	}
}
