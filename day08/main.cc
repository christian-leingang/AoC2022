#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <deque>
#include <algorithm>

#include "../utils/io.cc"

bool checkTree(const std::vector<std::vector<int>> &vec, int &i, int &j, int &smallest, std::vector<std::vector<char>> &visibleTrees)
{
    if (vec.at(i).at(j) > smallest)
    {
        smallest = vec.at(i).at(j);
        if (!visibleTrees.at(i).at(j))
        {
            visibleTrees.at(i).at(j) = true;
            return true;
        }
    }
    return false;
}

int part_01(const std::vector<std::vector<int>> &vec)
{
    int sum = 0;
    std::vector<std::vector<char>> visibleTrees(vec.size(), std::vector<char>(vec.at(0).size(), false));

    for (int i = 0; i < vec.size(); i++)
    {
        int smallest = -1;
        for (int j = 0; j < vec.at(i).size(); j++)
            if (checkTree(vec, i, j, smallest, visibleTrees))
                sum++;
    }

    for (int j = 0; j < vec.at(0).size(); j++)
    {
        int smallest = -1;
        for (int i = 0; i < vec.size(); i++)
            if (checkTree(vec, i, j, smallest, visibleTrees))
                sum++;
    }

    for (int i = vec.size() - 1; i >= 0; i--)
    {
        int smallest = -1;
        for (int j = vec.at(i).size() - 1; j >= 0; j--)
            if (checkTree(vec, i, j, smallest, visibleTrees))
                sum++;
    }

    for (int j = vec.at(0).size() - 1; j >= 0; j--)
    {
        int smallest = -1;
        for (int i = vec.size() - 1; i >= 0; i--)
            if (checkTree(vec, i, j, smallest, visibleTrees))
                sum++;
    }

    return sum;
}

int checkSurroundings(const std::vector<std::vector<int>> &vec, size_t &i, size_t &j)
{
    if (i == 0 || j == 0 || i >= vec.size() - 1 || j >= vec.size() - 1)
        return 0;

    int score{1};
    int distance = 0;

    // oben
    for (size_t k = i; k > 0; k--)
    {
        distance++;
        if (vec.at(i).at(j) <= vec.at(k - 1).at(j))
            break;
    }
    score *= distance;
    distance = 0;

    // links
    for (size_t k = j; k > 0; k--)
    {
        distance++;
        if (vec.at(i).at(j) <= vec.at(i).at(k - 1))
            break;
    }
    score *= distance;
    distance = 0;

    // unten
    for (size_t k = i; k < vec.size() - 1; k++)
    {
        distance++;
        if (vec.at(i).at(j) <= vec.at(k + 1).at(j))
            break;
    }
    score *= distance;
    distance = 0;

    // rechts
    for (size_t k = j; k < vec.size() - 1; k++)
    {
        distance++;
        if (vec.at(i).at(j) <= vec.at(i).at(k + 1))
            break;
    }
    score *= distance;

    return score;
}

int part_02(const std::vector<std::vector<int>> &vec)
{
    int highScore = 0;
    for (size_t i = 0; i < vec.size(); i++)
    {
        for (size_t j = 0; j < vec.at(0).size(); j++)
        {
            int curScore = checkSurroundings(vec, i, j);
            if (curScore > highScore)
            {
                highScore = curScore;
                std::cout << vec.at(i).at(j) << " i: " << i << "j: " << j << " high: " << highScore << std::endl;
            }
        }
    }

    return highScore;
}

int main()
{
    std::vector<std::vector<int>> input_p = commons::file_to_square_int_vec("input.txt");

    int part_01_int = part_01(input_p);
    int part_02_int = part_02(input_p);

    std::cout << part_01_int << "\n";
    std::cout << part_02_int << "\n";
    return 0;
}
