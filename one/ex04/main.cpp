/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 14:52:30 by jlacerda          #+#    #+#             */
/*   Updated: 2025/07/26 14:56:58 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

#define INFO_EMOJI "ℹ️  "
#define ERROR_EMOJI "❌ "
#define REPLACE_EMOJI "🔄 "
#define FILE_EMOJI "📄 "
#define RESET "\033[0m"
#define ORANGE "\033[38;5;214m"
#define YELLOW "\033[33m"
#define RED "\033[31m"

#define BREAKLINE_STR "\n"
#define EMPTY_STR ""

/**
 * Reads the entire content of the given input file stream into a single string.
 * Each line is separated by a newline character in the resulting string.
 * @param file The input file stream to read from. It must be already opened.
 * @return A string containing the entire content of the file, 
 * with lines separated by newline characters.
 * @note If the file is empty, an empty string is returned.
 * @note The function does not close the file stream; 
 * it is the caller's responsibility to manage the file stream's lifecycle.
 * @warning Ensure that the file stream is valid and opened before 
 * calling this function to avoid undefined behavior.
 */
std::string readFile(std::ifstream &file) {
    std::string line;
    std::string content = EMPTY_STR;
    while (std::getline(file, line)) {
        content += line + BREAKLINE_STR;
    }
    return content;
}

/**
 * Replaces all occurrences of s1 with s2 in the given content string.
 * If s1 or s2 is empty, the original content is returned unchanged.
 * If s1 is not found in content, the original content is returned unchanged.
 * @param content The original string content where replacements will be made.
 * @param s1 The substring to be replaced.
 * @param s2 The substring to replace with.
 * @return A new string with all occurrences of s1 replaced by s2.
 * @note If s1 is an empty string, no replacements 
 * will be made and the original content is returned.
 * @note If s1 is not found in content, no replacements 
 * will be made and the original content is returned.
 * @example replaceAll("hello world, hello!", "hello", "hi") returns "hi world, hi!"
 * @example replaceAll("hello world", "", "hi") returns "hello world" (no change)
 * @example replaceAll("hello world", "bye", "hi") returns "hello world" (no change)
 * @warning This function does not handle overlapping occurrences of s1.
 * For example, replaceAll("aaa
 */
std::string replaceAll(const std::string& content,
    const std::string& s1, const std::string& s2) {
    std::string result;
    size_t pos = 0;
    size_t found = 0;

    if (s1.empty() || s2.empty()) return content;

    while (true) {
		found = content.find(s1, pos);
		if (found == std::string::npos) break;
        result += content.substr(pos, found - pos);
        result += s2;
		pos = found + s1.length();
    }
    result += content.substr(pos);
	return result;
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << ERROR_EMOJI
            << RED << "Error: " << RESET
            << "Invalid number of arguments."
            << std::endl;
        std::cerr << INFO_EMOJI << YELLOW << "Usage: " << RESET 
            << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }
    
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    
    std::ifstream infile(filename.c_str());
    if (!infile.is_open()) {
        std::cerr << ERROR_EMOJI
            << RED << "Error: " << RESET
            << "Cannot open file " << filename << std::endl;
        return 1;
    }
    
    std::string outputFile = filename + ".replace";
    std::ofstream outfile(outputFile.c_str());
    if (!outfile.is_open()) {
        std::cerr << ERROR_EMOJI
            << RED << "Error: " << RESET
            << "Cannot create output file " << outputFile << std::endl;
        return 1;
    }
    
    std::string content = readFile(infile);
    std::string result = replaceAll(content, s1, s2);
	outfile << result;
	infile.close();
    outfile.close(); 
    std::cout << std::endl << REPLACE_EMOJI << "Replaced all occurrences of '" << s1 
        << "' with '" << s2 << "' in: " 
        << YELLOW << filename << RESET << std::endl;
    std::cout << FILE_EMOJI << "Resulting content written to: "
        << ORANGE << outputFile << RESET << std::endl  << std::endl;
    return 0;
}