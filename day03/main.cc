#include <iostream>
#include <string>
#include <vector>

#include "../utils/io.cc"

int part_01(std::vector<std::string> vec)
{
    int sum{};
    std::vector<char> result_vec{};
    for (auto str : vec)
    {
        std::string half = str.substr(0, str.length() / 2);
        std::string otherHalf = str.substr(str.length() / 2);

        result_vec.push_back(commons::findMatchingCharTwoStrings(half, otherHalf));
    }

    for (char c : result_vec)
        sum += commons::getIntValueFromChar(c);

    return sum;
}

int part_02(std::vector<std::string> vec)
{
    int sum{};
    for (size_t i = 0; i < vec.size(); i += 3)
    {
        char badge = commons::findMatchingCharThreeStrings(vec.at(i), vec.at(i + 1), vec.at(i + 2));
        sum += commons::getIntValueFromChar(badge);
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
