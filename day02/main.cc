#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <cstdlib>

#include "../utils/io.cc"

int part_01(std::vector<std::pair<char, char>> vec)
{
   int sum{};
   for (auto pair : vec)
   {
      // Adding up the values of the symbols
      switch (pair.second)
      {
      case 'X':
         sum++;
      case 'Y':
         sum++;
      case 'Z':
         sum++;
      };

      // Win
      if ((pair.first == 'A' && pair.second == 'Y') || (pair.first == 'B' && pair.second == 'Z') || (pair.first == 'C' && pair.second == 'X'))
         sum += 6;
      // Draw
      if ((pair.first == 'A' && pair.second == 'X') || (pair.first == 'B' && pair.second == 'Y') || (pair.first == 'C' && pair.second == 'Z'))
         sum += 3;
   }
   return sum;
}

int part_02(std::vector<std::pair<char, char>> vec)
{
   int sum{};
   for (auto pair : vec)
   {
      switch (pair.second)
      {
      case 'Y':
         sum += 3;
      case 'Z':
         sum += 3;
      };

      // Rock
      if ((pair.first == 'A' && pair.second == 'Y') || (pair.first == 'B' && pair.second == 'X') || (pair.first == 'C' && pair.second == 'Z'))
         sum += 1;
      // Paper
      if ((pair.first == 'A' && pair.second == 'Z') || (pair.first == 'B' && pair.second == 'Y') || (pair.first == 'C' && pair.second == 'X'))
         sum += 2;
      // Scissor
      if ((pair.first == 'A' && pair.second == 'X') || (pair.first == 'B' && pair.second == 'Z') || (pair.first == 'C' && pair.second == 'Y'))
         sum += 3;
   }
   return sum;
}

// main function for calling functions
int main()
{
   std::vector<std::pair<char, char>> input_p = commons::file_to_char_pair_vec("input.txt");

   int part_01_int = part_01(input_p);
   int part_02_int = part_02(input_p);

   std::cout << part_01_int << "\n";
   std::cout << part_02_int << "\n";
   return 0;
}