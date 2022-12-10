#include "io.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <sstream>

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

    std::vector<std::vector<int>> file_to_square_int_vec(const char *input)
    {
        std::string temp;
        std::vector<std::vector<int>> vec = {};
        std::ifstream input_file(input);

        while (input_file >> temp)
        {
            std::vector<char> data(temp.begin(), temp.end());
            std::vector<int> lineNumbers;
            for (auto c : data)
            {
                int curDigit = c - '0';
                lineNumbers.push_back(curDigit);
            }
            vec.push_back(lineNumbers);
        }
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

    std::vector<char> file_to_char_vec(const char *input)
    {
        std::string temp;
        std::fstream file(input);

        std::getline(file, temp);
        std::vector<char> vec(temp.begin(), temp.end());
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

    std::pair<std::string, std::string> splitByCharToString(std::string text, char c)
    {
        std::string segment;
        std::stringstream textss{text};
        std::vector<std::string> seglist;
        while (std::getline(textss, segment, c))
            seglist.push_back(segment);
        return std::make_pair(seglist.at(0), seglist.at(1));
    }

    std::vector<std::string> splitByCharToStringVec(std::string text, char c)
    {
        std::string segment;
        std::stringstream textss{text};
        std::vector<std::string> seglist;
        while (std::getline(textss, segment, c))
            seglist.push_back(segment);
        return seglist;
    }

    bool is_digits(const std::string &str)
    {
        return std::all_of(str.begin(), str.end(), ::isdigit); // C++11
    }

    // call with print_vec<int>(vec)
    template <typename T>
    void print_vec(std::vector<std::vector<T>> boolVec)
    {
        for (size_t i = 0; i < boolVec.size(); i++)
        {
            for (size_t j = 0; j < boolVec.at(i).size(); j++)
                std::cout << boolVec.at(i).at(j);
            std::cout << std::endl;
        }
    }

    bool contains(std::string text, std::string word)
    {
        return text.rfind(word, 0) == 0;
    }
    // std::pair<int, int> splitByCharToInt(std::string text, char c)
    // {
    //     std::string segment;
    //     std::stringstream textss{text};
    //     std::vector<std::string> seglist;
    //     while (std::getline(textss, segment, c))
    //         seglist.push_back(segment);
    //     return std::make_pair(std::stoi(seglist.at(0)), std::stoi(seglist.at(1)));
    // }

} // namespace commons
