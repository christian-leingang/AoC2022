#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

#include "../utils/io.cc"

int part_01(std::vector<std::string> vec)
{
    int sum{};
    std::pair<int, int> range1;
    std::pair<int, int> range2;
    std::pair<std::string, std::string> elfes;

    for (std::string str : vec)
    {
        elfes = commons::splitByCharToString(str, ',');
        range1 = commons::splitByCharToInt(elfes.first, '-');
        range2 = commons::splitByCharToInt(elfes.second, '-');
        if ((range1.first <= range2.first && range1.second >= range2.second) || (range1.first >= range2.first && range1.second <= range2.second))
            sum++;
    }

    return sum;
}

int part_02(std::vector<std::string> vec)
{
    int sum{};
    std::pair<int, int> range1;
    std::pair<int, int> range2;
    std::pair<std::string, std::string> elfes;

    for (std::string str : vec)
    {
        elfes = commons::splitByCharToString(str, ',');
        range1 = commons::splitByCharToInt(elfes.first, '-');
        range2 = commons::splitByCharToInt(elfes.second, '-');
        if ((range1.first <= range2.first && range1.second >= range2.first) || (range1.second >= range2.second && range1.first <= range2.second) ||
            (range2.first <= range1.first && range2.second >= range1.first) || (range2.second >= range1.second && range2.first <= range1.second))
            sum++;
    }

    return sum;
}

// main function for calling functions
int main()
{
    std::vector<std::string> input_p = commons::file_to_str_vec("input-test.txt");

    int part_01_int = part_01(input_p);
    int part_02_int = part_02(input_p);

    std::cout << part_01_int << "\n";
    std::cout << part_02_int << "\n";
    return 0;
}
