#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

# define ERRCDBAD "error: cd: bad arguments"
# define ERRCDPATH "error: cd: cannot change directory to "
# define ERRFATAL "error: fatal"
# define ERREXEC  "error: cannot execute "

#ifdef TEST_SH
# define TEST		1
#else
# define TEST		0
#endif

typedef struct s_cmd
{
	struct s_cmd *prev;
	char **args;
	char flag;
	int pid;
	int fd[2];
	struct s_cmd *next;
}			t_cmd;

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

void	ft_exit(char *err, char *com, int out)
{
	write(2, err, ft_strlen(err));
	if (com)
		write(2, com, ft_strlen(com));
	write(2, "\n", 1);
	if (out)
		exit(1);
}

void add_list_back(t_cmd **cmd)
{
	t_cmd *last;
	t_cmd *node;

	last = *cmd;
	while(last && last->next)
		last = last->next;
	if(!(node = malloc(sizeof(t_cmd))))
		ft_exit(ERRFATAL, 0, 1);
	node->args = NULL;
	node->flag = 0;
	node->pid = 0;
	node->next = NULL;
	node->prev = last;
	last->next = node;
}

t_cmd *new_list(void)
{
	t_cmd *node;

	if (!(node = malloc(sizeof(t_cmd))))
		ft_exit(ERRFATAL, 0, 1);
	node->args = NULL;
	node->flag = 0;
	node->pid = 0;
	node->next = NULL;
	node->prev = NULL;
	return(node);
}

void	free_list(t_cmd *cmd)
{
	t_cmd *node;

	while(cmd)
	{
		if (cmd->args)
			free(cmd->args);
		node = cmd;
		cmd = cmd->next;
		free(node);
	}
}


void	pipex(t_cmd *cmd, char **envp)
{
	int id = 0;

	while (cmd)
	{
		if (!cmd->args)
			;
		else if (!strcmp(cmd->args[0], "cd"))
		{
			if (!cmd->args[1] || cmd->args[2])
				ft_exit(ERRCDBAD, 0, 0);
			else if (chdir(cmd->args[1]) < 0)
				ft_exit(ERRCDPATH, cmd->args[1], 0);
		}
		else
		{
			if (cmd->flag == '|')
				if (pipe(cmd->fd) == -1)
					ft_exit(ERRFATAL, 0, 1);
			cmd->pid = fork();
			if (!cmd->pid)
			{
				if (cmd->flag == '|')
				{
					dup2(cmd->fd[1], 1);
					close(cmd->fd[1]);
					close(cmd->fd[0]);
				}
				if (id && cmd->prev->flag == '|')
					dup2(cmd->prev->fd[0], 0);
				execve(cmd->args[0], cmd->args, envp);
				ft_exit(ERREXEC, cmd->args[0], 1);
			}
			else
			{
				waitpid(cmd->pid, 0, 0);
				if (cmd->flag == '|')
					close(cmd->fd[1]);
				if (id && cmd->prev->flag == '|')
					close(cmd->prev->fd[0]);
			}
		}
		cmd = cmd->next;
		id++;
	}
}

int main(int argv, char **argc, char **envp)
{
	(void)argv;
	t_cmd	*cmd;
	t_cmd	*list;
	int i;
	int j;
	int len;

	cmd = new_list();
	list = cmd;
	i = 1;
	while(argc[i])
	{
		len = 0;
		while(argc[i + len] && (strcmp(argc[i + len], "|") && strcmp(argc[i + len], ";")))
			len++;
		if (!len && argc[i] && i++)
			continue ;
		if(!(list->args = malloc(sizeof(char *) * (len + 1))))
			ft_exit(ERRFATAL, 0, 1);
		j = 0;
		while(len--)
			list->args[j++] = argc[i++];
		list->args[j] = NULL;
		if (argc[i])
		{
			list->flag = argc[i++][0];
			add_list_back(&list);
			list = list->next;
		}
	}
	pipex(cmd, envp);
	free_list(cmd);
// if (TEST)
// 		while (1);
	return (0);
}
