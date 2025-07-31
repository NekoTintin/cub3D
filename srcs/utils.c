/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:40:40 by qupollet          #+#    #+#             */
/*   Updated: 2025/07/31 17:45:54 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	ft_print_warning(char *msg)
{
	ft_putstr_fd(YELLOW "Warning: " END, 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
}