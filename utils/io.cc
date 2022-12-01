#include "io.h"

#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>

namespace commons
{
    std::vector<int> file_to_int_vec(const char * input)
    {
        int temp;
        std::vector<int> vec = {};
        std::ifstream input_file(input);

        while (input_file >> temp) vec.push_back(temp);

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
} // namespace commons
