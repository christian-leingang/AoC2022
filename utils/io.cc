#include "io.h"

#include <string>
#include <vector>
#include <filesystem>
#include <algorithm>
#include <fstream>

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
} // namespace commons
