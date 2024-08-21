/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 18:49:49 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/08/15 18:49:49 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <fcntl.h>
# include "../push_swap.h"

# define BUFFER_SIZE 4

char	*get_next_line(int fd);
char	*ft_free(char **str);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
char	*ft_substr(const char *s, unsigned int start, size_t len);
void	write_res(t_stack *a);

#endif