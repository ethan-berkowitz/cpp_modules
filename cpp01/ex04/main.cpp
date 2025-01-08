/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:19:08 by eberkowi          #+#    #+#             */
/*   Updated: 2025/01/06 11:17:45 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

static void	check_for_incorrect_number_of_args(int argc)
{
	if (argc != 4)
	{
		std::cout << "Error: Incorrect number of arguments\n";
		exit (1);
	}	
}

static void	copy_infile_to_string(std::string infile_name, std::string *infile_string)
{
	char c;

	std::ifstream infile(infile_name);
	if (!infile) {
		std::cout << "Error: Cannot open file\n";
		exit (1);
	}	
	while (infile.get(c)) {
		*infile_string += c;
	}
	infile.close();
}

static void	check_for_empty_strings(char *argv[])
{
	if (!argv[1][0] || !argv[2][0] || !argv[3][0]) {
		std::cout << "Error: Strings cannot be empty\n";
		exit (1);
	}
}

static int check_for_s1(std::string infile_string, size_t infile_index, std::string s1, size_t s1_length)
{
	for (size_t i = 0; i < s1_length; ++i) {
		if (infile_string[infile_index] != s1[i])
			return (0);
		infile_index++;
	}
	return (1);
}

int main(int argc, char *argv[])
{
	std::string infile_string;
	
	check_for_incorrect_number_of_args(argc);
	check_for_empty_strings(argv);
	copy_infile_to_string(argv[1], &infile_string);

	std::ofstream outfile((std::string)argv[1] + ".replace");
	if (!outfile) {
		std::cout << "Error: Cannot create file\n";
		return (1);
	}
	
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	size_t s1_length = s1.length();
	
    for (size_t i = 0; i < infile_string.length(); ++i) {
		if (check_for_s1(infile_string, i, s1, s1_length)) {
			i += s1_length - 1;
			outfile << s2;
		}
		else
			outfile.put(infile_string[i]);
    }
	
	outfile.close();
	return (0);
}
