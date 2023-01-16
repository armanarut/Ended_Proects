/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 19:37:10 by akazarya          #+#    #+#             */
/*   Updated: 2022/05/28 19:38:25 by akazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define ERR_INPUT	  "pipex: Invalid number of arguments"
# define ERR_FILE	   "pipex: no such file or directory: "
# define ERR_PERMITION  "pipex: permission denied: "
# define ERR_PIPE	   "pipex: Invalid pipe"
# define ERR_FORK	   "pipex: Invalid fork"
# define ERR_COMMAND	"pipex: command not found: "
# define ERR_ARGUMENT	"pipex: Invalid argument"

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_pipe
{
	char	*file_in;
	int		fd_in;
	int		fd_out;
	char	**cmds;
	char	**cmd_args;
	char	**path;
	int		here;
	char	*limit;
}			t_pipe;

//pipex
void	cmd_pipe(t_pipe *pip, char **envp, int id);
void	make_exec(t_pipe *pip, char **envp, int id);
void	here_doc(t_pipe *pip);

//utils
void	ft_exit(char *err, char *cmd, int id);
void	ft_my_strjoin(char **s1, char const *s2);
char	*mini_get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_strstr(char *str, char *to_find);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);

#endif
