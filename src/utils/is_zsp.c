/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_zsp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 13:54:20 by akhastaf          #+#    #+#             */
/*   Updated: 2020/11/07 14:00:54 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_zsp(char c)
{
	return (c == 'N' || c == 'W' || c == 'S' || c == 'E'
			|| c == '2' || c == '0');
}
