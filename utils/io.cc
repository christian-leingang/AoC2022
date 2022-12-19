#include "io.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <sstream>

class Coord3d
{
private:
    int x, y, z;

public:
    Coord3d(int num1, int num2, int num3)
    {
        this->x = num1;
        this->y = num2;
        this->z = num3;
    }
    Coord3d(){};

    Coord3d operator+(const Coord3d &coord)
    {
        Coord3d coord3d{};
        coord3d.x = this->x + coord.x;
        coord3d.y = this->y + coord.y;
        coord3d.z = this->z + coord.z;
        return coord3d;
    };

    bool operator==(const Coord3d &coord)
    {
        return (this->x == coord.x) && (this->y == coord.y) && (this->z == coord.z);
    };
};

namespace commons
{

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

    std::vector<int> str_to_int_vec(const std::string &str)
    {
        std::vector<char> data(str.begin(), str.end());
        std::vector<int> lineNumbers;
        for (auto c : data)
        {
            int curDigit = c - '0';
            lineNumbers.push_back(curDigit);
        }
        return lineNumbers;
    }

    std::vector<std::vector<int>> file_to_square_int_vec(const char *input)
    {
        std::string temp;
        std::vector<std::vector<int>> vec = {};
        std::ifstream input_file(input);

        while (input_file >> temp)
        {
            std::vector<int> lineNumbers = str_to_int_vec(temp);
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

    std::vector<std::pair<char, int>> file_to_char_int_pair_vec(const char *input)
    {
        std::string temp;
        std::vector<std::pair<char, int>> vec = {};
        std::fstream file(input);

        while (std::getline(file, temp))
        {
            auto splitStr = splitByCharToString(temp, ' ');
            vec.push_back(std::make_pair(splitStr.first[0], std::atoi(splitStr.second.c_str())));
        }
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

    std::vector<Coord3d> file_to_3d_int_vec(const char *input)
    {
        std::string temp;
        std::vector<Coord3d> vec = {};
        std::ifstream input_file(input);

        while (input_file >> temp)
        {
            std::vector<std::string> strVec = splitByCharToStringVec(temp, ',');
            Coord3d coord3d{std::atoi(strVec[0].c_str()), std::atoi(strVec[1].c_str()), std::atoi(strVec[2].c_str())};
            vec.push_back(coord3d);
        }
        input_file.close();
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

    std::vector<std::pair<std::string, std::string>> vec_to_str_pair(std::vector<std::string> &vec)
    {
        std::vector<std::pair<std::string, std::string>> pair_vec;
        std::string firstElement{""};

        for (auto line : vec)
        {
            if (line == "")
                continue;
            if (firstElement == "")
                firstElement = line;
            else
            {
                pair_vec.push_back(std::make_pair(firstElement, line));
                firstElement = "";
            }
        }
        return pair_vec;
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
