/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bherranz <bherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:18:53 by bherranz          #+#    #+#             */
/*   Updated: 2024/06/19 20:18:54 by bherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	is_rectangular(char **map, t_game *game)
{
	size_t	size;

	size = ft_strlen(*map);
	while (*map)
	{
		if (size != ft_strlen(*map))
			print_error("Error\nThe map must be rectangular\n", 'w', game);
		map++;
	}
}

void	check_walls(char **map, t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (map[0][j])
	{
		if (map[0][j] != '1')
			print_error("Error\nMap must be surrounded by wall\n", 'w', game);
		j++;
	}
	i = 1;
	while (map[i + 1])
	{
		if ((map[i][0] != '1') || (map[i][ft_strlen(map[i]) - 1] != '1'))
			print_error("Error\nMap must be surrounded by wall\n", 'w', game);
		i++;
	}
	j = 0;
	while (map[i][j])
	{
		if (map[i][j] != '1')
			print_error("Error\nMap must be surrounded by wall\n", 'w', game);
		j++;
	}
}

void	check_chars(t_game *game, char **map)
{
	int		exit;
	int		start;
	char	*row;

	exit = 0;
	start = 0;
	while (*map)
	{
		row = *map;
		while (*row)
		{
			if (*row == 'C')
				game->coins++;
			else if (*row == 'E')
				exit++;
			else if (*row == 'P')
				start++;
			else if (*row != '1' && *row != '0' && *row != '!')
				print_error("Error\nCharacters not allowed\n", 'w', game);
			row++;
		}
		map++;
	}
	if (exit != 1 || start != 1 || game->coins == 0)
		print_error("Error\nWrong map\n", 'w', game);
}

void	is_valid(char **map, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
			{
				free_str_array(map);
				print_error("Error\nThe map is not playable\n", 'w', game);
			}
			j++;
		}
		i++;
	}
	free_str_array(map);
}

void	is_playable(char **map, t_game *game)
{
	int		i;
	int		j;
	char	**new_map;

	i = 0;
	new_map = copy_map(map);
	while (new_map[i])
	{
		j = 0;
		while (new_map[i][j])
		{
			if (new_map[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
				fill(new_map, i, j);
			}
			j++;
		}
		i++;
	}
	is_valid(new_map, game);
}
