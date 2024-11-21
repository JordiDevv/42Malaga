/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:21:35 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/11/21 15:42:44 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "ft_printf/ft_printf.h"
# include "bonus/get_next_line/get_next_line.h"
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdarg.h>
# include <stdbool.h>

extern char	**environ;

typedef struct  s_data
{
    int     fds[2];
    int     **pipe;
    int     file1;
    int     cmd1;
    int     cmd2;
    int     step;
    bool    here_doc;

    char    *limiter;
    char    **path_mat;
    char    *full_rute;
    char    **split_cmd;
}           t_data;

char	*ft_strchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char    *strmcat(int n, int i, ...);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);

char	**ft_split(char const *s, char c);

void	valid_cmd(char *cmd, t_data *program_data);

void	ex_cmd1(t_data *program_data, int argc);
void	ex_cmd2(t_data *program_data);

void	free_mat(char **mat);
void	free_exit(t_data *program_data);

void	ex_nextcmd(t_data *program_data, int i);
void	ex_finalcmd(t_data *program_data, int i);
void    init_heredoc(t_data *program_data, char **argv, int argc);

#endif