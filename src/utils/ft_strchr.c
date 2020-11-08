/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 13:57:19 by akhastaf          #+#    #+#             */
/*   Updated: 2020/11/05 14:01:57 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	*ft_strchr(const char *s, int c)
{
	char *str;

	str = (char*)s;
	if (!s)
		return (NULL);
	if (!c)
		return (str + ft_strlen(s));
	while (*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	return (NULL);
}
