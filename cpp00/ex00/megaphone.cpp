/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   megaphone.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: evalieve <evalieve@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/25 15:16:26 by evalieve      #+#    #+#                 */
/*   Updated: 2024/06/13 13:49:55 by evalieve      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

int main(int argc, char *argv[]) {
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	for (int i = 1; i < argc; i++)
	{
		for (int j = 0; argv[i][j]; j++)
			std::cout << (char) std::toupper(argv[i][j]);
	}
	std::cout << std::endl;
}
