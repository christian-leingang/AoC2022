#include <iostream>
#include <vector>
#include <iostream>
#include <vector>

#include "../utils/io.cc"

int part_01(std::vector<int> vec)
{
    // go through the vector and compare previous entries to the current one, and return a count of increase
    int depth_count = 0;
    for (size_t i = 1; i < vec.size(); i++)
    {
        if (vec[i] > vec[i - 1])
            depth_count++;
    }
    return depth_count;
}

int part_02(std::vector<int> vec)
{
    // same as first but in three items
    int depth_count_triple = 0;
    for (size_t i = 3; i < vec.size(); i++)
    {
        if ((vec[i - 2] + vec[i - 1] + vec[i]) > (vec[i - 3] + vec[i - 2] + vec[i - 1]))
            depth_count_triple += 1;
    }
    return depth_count_triple;
}

// main function for calling functions
int main()
{
    std::vector<int> input_p1 = commons::file_to_int_vec("input.txt");
    int part_01_int = part_01(input_p1);
    int part_02_int = part_02(input_p1);
    std::cout << part_01_int << "\n";
    std::cout << part_02_int << "\n";
    return 0;
}
