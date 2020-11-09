/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 13:11:51 by akhastaf          #+#    #+#             */
/*   Updated: 2020/11/09 09:32:21 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <string.h>
# include "structs.h"

size_t	ft_strlen(const char *s);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strdup(const char *s1);
void	write_exit(char *s);
void	skip_spaces(char **s);
int		spaces(char *s);
void	skip_digit(char **s);
t_pos	set_pos(t_pos *pos, float x, float y);
t_pos	copy_pos(t_pos *pos, t_pos s);
int		is_wall_at(t_pos pos);
float	normalize_angle(float angle);
float	distance(float x1, float y1, float x2, float y2);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_bzero(void *s, size_t n);
void	free_paths(void);
void	free_map(void);
int		is_map_element(char c);
int		is_zsp(char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strndup(const char *s1, size_t n);
void	int_in_char(unsigned char *str, int value);
#endif
