/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpavel <gpavel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 11:38:21 by gpavel            #+#    #+#             */
/*   Updated: 2020/09/22 15:35:10 by gpavel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main()
{
	char **line;
	int fd;
	int gnl;

	line = malloc(500);
	fd = open("text.txt", O_RDONLY);
	while ((gnl = get_next_line(fd, line)) > 0)
	{
		printf("GNL reutn : %d | line : %s\n", gnl, *line);
		free(*line);
	}
	printf("GNL return : %d | line : %s\n", gnl, *line);
	free(*line);
	return (0);
}

//int main()
//{
//	char *line[500];
//	int fd;
//	int gnl;
//	fd = open("text.txt", O_RDONLY);
//	gnl = get_next_line(fd, line);
//	printf("GNL reutrn: |%d|\nline: |%s|\n", gnl, *line);
//	//system("leaks ProgramGNL");
//	return 0;
//}
