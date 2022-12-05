#include <iostream>
#include <string>
#include <vector>
#include <stack>

#include "../utils/io.cc"

int initStackVec(const std::vector<std::string> &vec, std::vector<std::stack<char>> &stackVec)
{
    int lineNo = 0;
    for (auto line : vec)
    {
        if (line.rfind("1", 1) < 2)
        {
            for (char num : line)
                if (std::isdigit(num))
                    stackVec.push_back(std::stack<char>{});
            return lineNo;
        }
        lineNo++;
    }
    return 0;
}

void fillStackVec(const std::vector<std::string> &vec, std::vector<std::stack<char>> &stackVec, const int &stackBase)
{
    for (int i{stackBase - 1}; i >= 0; i--)
    {
        for (size_t j{0}; j <= vec.at(i).length(); j++)
        {
            char letter = vec.at(i)[j];
            if (std::isalpha(letter))
                stackVec.at((j - 1) / 4).push(letter);
        }
    }
}

void moveCratesSingle(const std::vector<std::string> &vec, std::vector<std::stack<char>> &stackVec)
{
    for (auto line : vec)
    {
        if (!line.rfind("move", 0) == 0)
            continue;

        int moves = std::atoi(line.substr(5, 2).c_str());
        int from = line[line.length() - 6] - '1';
        int to = line.back() - '1';

        for (int i{0}; i < moves; i++)
        {
            char movingLetter = stackVec.at(from).top();
            stackVec.at(from).pop();
            stackVec.at(to).push(movingLetter);
        }
    }
}

void moveCratesMultiple(const std::vector<std::string> &vec, std::vector<std::stack<char>> &stackVec)
{
    for (auto line : vec)
    {
        if (!line.rfind("move", 0) == 0)
            continue;

        int moves = std::atoi(line.substr(5, 2).c_str());
        std::vector<char> movingVec;
        int from = line[line.length() - 6] - '1';
        int to = line.back() - '1';

        for (int i{0}; i < moves; i++)
        {
            movingVec.push_back(stackVec.at(from).top());
            stackVec.at(from).pop();
        }

        std::reverse(movingVec.begin(), movingVec.end());

        for (int i{0}; i < moves; i++)
            stackVec.at(to).push(movingVec.at(i));
    }
}

std::string getTopOfStacks(const std::vector<std::stack<char>> &stackVec)
{
    std::string top{};
    for (auto stack : stackVec)
        top += stack.top();

    return top;
}

std::string part_01(const std::vector<std::string> &vec)
{
    int stackBase{};
    std::vector<std::stack<char>> stackVec;

    stackBase = initStackVec(vec, stackVec);
    fillStackVec(vec, stackVec, stackBase);
    moveCratesSingle(vec, stackVec);
    std::string top = getTopOfStacks(stackVec);

    return top;
}

std::string part_02(std::vector<std::string> vec)
{
    int stackBase{};
    std::vector<std::stack<char>> stackVec;

    stackBase = initStackVec(vec, stackVec);
    fillStackVec(vec, stackVec, stackBase);
    moveCratesMultiple(vec, stackVec);
    std::string top = getTopOfStacks(stackVec);

    return top;
}

int main()
{
    std::vector<std::string> input_p = commons::file_to_str_vec("input.txt");

    std::string part_01_str = part_01(input_p);
    std::string part_02_str = part_02(input_p);

    std::cout << part_01_str << "\n";
    std::cout << part_02_str << "\n";
    return 0;
}
