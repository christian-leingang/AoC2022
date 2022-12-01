#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <cstdlib>

#include "../utils/io.cc"

std::vector<int> get_calories_sum(std::vector<std::string> vec)
{
   std::vector<int> sums;
   int temp_sum{0};
   for (std::string line : vec)
   {
      if (line == "")
      {
         sums.push_back(temp_sum);
         temp_sum = 0;
      }
      else
         temp_sum += std::atoi(line.c_str());
   }
   return sums;
}

int part_01(std::vector<std::string> vec)
{
   std::vector<int> sums = get_calories_sum(vec);
   return *std::max_element(sums.begin(), sums.end());
}

int part_02(std::vector<std::string> vec)
{
   std::vector<int> sums = get_calories_sum(vec);
   std::nth_element(sums.begin(), sums.begin() + 1, sums.end(), std::greater<int>());
   return sums[0] + sums[1] + sums[2];
}

// main function for calling functions
int main()
{
   std::vector<std::string> input_p = commons::file_to_str_vec("input.txt");

   int part_01_int = part_01(input_p);
   int part_02_int = part_02(input_p);

   std::cout << part_01_int << "\n";
   std::cout << part_02_int << "\n";
   return 0;
}