/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 19:32:30 by akazarya          #+#    #+#             */
/*   Updated: 2022/05/28 19:35:14 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_envp(t_pipe *pip, char **envp)
{
	int	i;

	i = 0;
	while (!ft_strstr(envp[i], "PATH="))
		i++;
	pip->path = ft_split(envp[i] + ft_strlen("PATH="), ':');
	i = -1;
	while (pip->path[++i])
		ft_my_strjoin(&pip->path[i], "/");
}

void	check_files(t_pipe pip, char *file1, char *file2)
{
	int	i;

	i = 2;
	if (!access(file1, F_OK) && pip.fd_in == -1)
		ft_exit(ERR_PERMITION, file1, 0);
	else if (pip.fd_in == -1)
		ft_exit(ERR_FILE, file1, 0);
	else
		i--;
	if (!access(file2, F_OK) && pip.fd_out == -1)
		ft_exit(ERR_PERMITION, file2, 0);
	else if (pip.fd_out == -1)
		ft_exit(ERR_FILE, file2, 0);
	else
		i--;
	if (i)
		exit(1);
}

void	get_args(t_pipe *pip, int argc, char **argv)
{
	int	i;

	pip->here = 1;
	if (argc > 1)
	{
		if (!ft_strcmp(argv[1], "here_doc"))
		{
			pip->file_in = ft_strjoin(0, "here_doc.txt");
			pip->limit = ft_strjoin(0, argv[2]);
			pip->here = 2;
		}
		else
			pip->file_in = ft_strjoin(0, argv[1]);
	}
	if (argc < 4 + pip->here)
		ft_exit(ERR_INPUT, 0, 1);
	pip->cmds = malloc(sizeof(pip) * argc - pip->here);
	if (!pip->cmds)
		return ;
	i = pip->here;
	while (argv[++i + 1])
		pip->cmds[i - pip->here - 1] = ft_strjoin(0, argv[i]);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipe	pip;
	int		id;

	get_args(&pip, argc, argv);
	if (pip.here == 2)
		here_doc(&pip);
	pip.fd_in = open(pip.file_in, O_RDONLY);
	pip.fd_out = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	check_files(pip, pip.file_in, argv[argc - 1]);
	dup2(pip.fd_in, 0);
	dup2(pip.fd_out, 1);
	get_envp(&pip, envp);
	id = -1;
	while (++id < argc - 3 - pip.here)
		cmd_pipe(&pip, envp, id);
	make_exec(&pip, envp, id);
	close(pip.fd_in);
	close(pip.fd_out);
	return (0);
}
