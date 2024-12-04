#include <iostream>
#include <sstream>
#include <queue>
#include <functional>
#include <map>

int main()
{
    std::vector<int> firstList;
    std::map<int, int> ocurrencesOnSecondList;
    std::string line;

    while (std::getline(std::cin, line))
    {
        std::istringstream iss(line);
        int num1, num2;
        if (iss >> num1 >> num2)
        {
            firstList.push_back(num1);
            ocurrencesOnSecondList[num2]++;
        }
    }

    int similarity = 0;
    for (int number : firstList)
    {
        if (ocurrencesOnSecondList.find(number) != ocurrencesOnSecondList.end())
        {
            similarity += number * ocurrencesOnSecondList[number];
        }
    }

    std::cout << similarity << std::endl;

    return 0;
}
