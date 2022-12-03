#include "io.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

namespace commons
{
    std::vector<int> file_to_int_vec(const char *input)
    {
        int temp;
        std::vector<int> vec = {};
        std::ifstream input_file(input);

        while (input_file >> temp)
            vec.push_back(temp);

        input_file.close();
        return vec;
    }

    std::vector<std::string> file_to_str_vec(const char *input)
    {
        std::string temp;
        std::vector<std::string> vec = {};
        std::fstream file(input);

        while (std::getline(file, temp))
            vec.push_back(temp);

        file.close();
        return vec;
    }

    std::vector<std::pair<char, char>> file_to_char_pair_vec(const char *input)
    {
        std::string temp;
        std::vector<std::pair<char, char>> vec = {};
        std::fstream file(input);

        while (std::getline(file, temp))
            vec.push_back(std::make_pair(temp[0], temp[2]));

        file.close();
        return vec;
    }

    char findMatchingCharTwoStrings(std::string str1, std::string str2)
    {
        for (char c : str1)
            for (char d : str2)
                if (c == d)
                    return c;
        return 0;
    }

    char findMatchingCharThreeStrings(std::string str1, std::string str2, std::string str3)
    {
        for (char c : str1)
            for (char d : str2)
                for (char e : str3)
                    if (c == d && c == e)
                        return c;
        return 0;
    }

    int getIntValueFromChar(char c)
    {
        if (isupper(c))
            return ((int)c - 38);
        else
            return ((int)c - 96);
    }
} // namespace commons
