#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "../utils/io.cc"

bool registerOnSprite(int registerPos, int spritePos)
{
    return registerPos - 1 <= spritePos && registerPos + 1 >= spritePos;
}

int part_01(const std::vector<std::string> &vec)
{
    int signalSums = 0;
    int registerSum = 1;
    bool operationFinished = false;
    int lineNo = 0;

    for (int cycleRound{1}; cycleRound < 222; cycleRound++)
    {
        std::string curCommand = vec.at(lineNo);

        if ((cycleRound + 20) % 40 == 0)
            signalSums += cycleRound * registerSum;

        if (commons::contains(curCommand, "noop"))
        {
            lineNo++;
            continue;
        }

        if (!operationFinished)
            operationFinished = true;

        auto commandPair = commons::splitByCharToString(curCommand, ' ');
        registerSum += std::stoi(commandPair.second);
        lineNo++;
        operationFinished = false;
    }
    return signalSums;
}

void part_02(const std::vector<std::string> &vec)
{
    int registerPos = 1;
    bool operationFinished = false;
    int lineNo = 0;
    std::vector<std::string> picture{};
    int pictureRowNo = -1;

    for (int cycleRound{1}; cycleRound < 240; cycleRound++)
    {
        // Start cycle
        if ((cycleRound - 1) % 40 == 0)
        {
            std::string tempStr{};
            picture.push_back(tempStr);
            pictureRowNo++;
        }

        // During cycle
        if (registerOnSprite(registerPos + 1, cycleRound % 40))
            picture.at(pictureRowNo).push_back('#');
        else
            picture.at(pictureRowNo).push_back('.');

        // End cycle
        std::string curCommand = vec.at(lineNo);

        if (commons::contains(curCommand, "noop"))
        {
            lineNo++;
            continue;
        }

        if (!operationFinished)
            operationFinished = true;

        auto commandPair = commons::splitByCharToString(curCommand, ' ');
        registerPos += std::stoi(commandPair.second);
        lineNo++;
        operationFinished = false;
    }
    for (auto line : picture)
        std::cout << line << std::endl;
}

int main()
{
    auto input_p = commons::file_to_str_vec("input.txt");

    int part_01_int = part_01(input_p);
    // int part_02_int = part_02(input_p);
    part_02(input_p);

    std::cout << part_01_int << "\n";
    // std::cout << part_02_int << "\n";
    return 0;
}
