#include <vector>
#include <iostream>
#include <sstream>
int main()
{
    std::string line;
    int safe = 0;

    while (std::getline(std::cin, line))
    {
        std::istringstream iss(line);
        int prevLevel = -1;
        int level;
        bool isAscending;
        bool gotFirstPair = false;
        bool isSafe = true;
        while (iss >> level)
        {
            if (prevLevel != -1)
            {
                if (!gotFirstPair)
                {
                    isAscending = level > prevLevel;
                    gotFirstPair = true;
                }

                int diff = level - prevLevel;

                if (std::abs(diff) < 1 || std::abs(diff) > 3 || isAscending && diff < 0 || !isAscending && diff > 0)
                {
                    isSafe = false;
                    break;
                }
            }
            prevLevel = level;
        }
        safe += isSafe;
    }
    std::cout << safe << std::endl;
}