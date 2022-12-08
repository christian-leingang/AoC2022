#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <deque>
#include <algorithm>
#include <map>
#include <cctype>

#include "../utils/io.cc"

std::map<std::string, long> getDirMap(const std::vector<std::string> &vec)
{
    std::vector<std::string> curDir;
    std::map<std::string, long> dirMap;

    for (size_t i = 0; i < vec.size(); i++)
    {
        std::string command = vec.at(i);
        std::vector<std::string> commandVec = commons::splitByCharToStringVec(command, ' ');

        if (commandVec.at(1) == "cd")
        {
            if (commandVec.at(2) == "..")
                curDir.pop_back();
            else
                curDir.push_back(commandVec.at(2));
        }
        else if (commons::is_digits(commandVec.at(0)))
        {
            std::string pathStr;
            for (const auto &piece : curDir)
            {
                pathStr += piece + "/";
                dirMap[pathStr] += std::atoi(commandVec.at(0).c_str());
            }
        }
    }
    return dirMap;
}

int part_01(const std::map<std::string, long> &dirMap)
{
    int sum = 0;
    for (auto dir : dirMap)
        if (dir.second <= 100000)
            sum += dir.second;

    return sum;
}

int part_02(std::map<std::string, long> &dirMap)
{
    int curSize = dirMap["//"];
    int freeUpSpace = curSize - 40000000;

    int smallest = curSize;
    for (auto dir : dirMap)
        if (dir.second < smallest && dir.second >= freeUpSpace)
            smallest = dir.second;
            
    return smallest;
}

// main function for calling functions
int main()
{
    std::vector<std::string> input_p = commons::file_to_str_vec("input.txt");
    std::map<std::string, long> dirMap = getDirMap(input_p);

    long part_01_int = part_01(dirMap);
    int part_02_int = part_02(dirMap);

    std::cout << part_01_int << "\n";
    std::cout << part_02_int << "\n";
    return 0;
}
