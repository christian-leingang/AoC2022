#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <deque>
#include <algorithm>

#include "../utils/io.cc"

bool sortQueue(std::deque<char> deque)
{
    auto sortedDeque = deque;
    std::sort(sortedDeque.begin(), sortedDeque.end());
    if (std::adjacent_find(sortedDeque.begin(), sortedDeque.end()) == sortedDeque.end())
        return true;
    return false;
}

int part_01(const std::vector<char> &vec)
{
    int marker = 3;
    bool found = false;
    std::deque<char> lastElements;

    for (size_t i = 0; i < 3; i++)
        lastElements.push_back(vec.at(i));

    while (!found)
    {
        lastElements.push_back(vec.at(marker));
        found = sortQueue(lastElements);
        lastElements.pop_front();
        marker++;
    }

    return marker;
}

int part_02(const std::vector<char> &vec)
{
    int marker = 13;
    bool found = false;
    std::deque<char> lastElements;

    for (size_t i = 0; i < 13; i++)
        lastElements.push_back(vec.at(i));

    while (!found)
    {
        lastElements.push_back(vec.at(marker));
        found = sortQueue(lastElements);
        lastElements.pop_front();
        marker++;
    }

    return marker;
}

// main function for calling functions
int main()
{
    std::vector<char> input_p = commons::file_to_char_vec("input.txt");

    int part_01_int = part_01(input_p);
    int part_02_int = part_02(input_p);

    std::cout << part_01_int << "\n";
    std::cout << part_02_int << "\n";
    return 0;
}
