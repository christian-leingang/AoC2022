#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <array>
#include <set>

#include "../utils/io.cc"

const std::array<Coord3d, 6> Directions = {
    Coord3d{0, 0, 1},
    Coord3d{0, 0, -1},
    Coord3d{0, 1, 0},
    Coord3d{0, -1, 0},
    Coord3d{1, 0, 0},
    Coord3d{-1, 0, 0},
};

int checkSurroundings(const std::vector<Coord3d> &vec, Coord3d &element)
{
    int freeSpaceCount = 0;
    std::vector<Coord3d> surroundings;
    
    for (auto dir : Directions)
        surroundings.push_back(dir + element);

    for (auto surrounding : surroundings)
    {
        bool found = false;

        for (auto coord : vec)
            if (surrounding == coord)
                found = true;

        if (!found)
            freeSpaceCount++;
    }
    return freeSpaceCount;
}

int part_01(const std::vector<Coord3d> &vec)
{
    int sum = 0;

    for (auto element : vec)
        sum += checkSurroundings(vec, element);

    return sum;
}

void part_02(const std::vector<Coord3d> &vec)
{
}

int main()
{
    auto input_p = commons::file_to_3d_int_vec("input.txt");

    int part_01_int = part_01(input_p);
    // int part_02_int = part_02(input_p);
    part_02(input_p);

    // std::cout << part_01_int << "\n";
    // std::cout << part_02_int << "\n";
    return 0;
}
