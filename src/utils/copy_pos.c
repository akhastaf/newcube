/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 13:30:39 by akhastaf          #+#    #+#             */
/*   Updated: 2020/11/07 14:06:36 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/structs.h"

t_pos	copy_pos(t_pos *pos, t_pos s)
{
	pos->x = s.x;
	pos->y = s.y;
	return (*pos);
}
