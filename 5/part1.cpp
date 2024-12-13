#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <string>

bool canBePrinted(int num, const std::map<int, std::set<int>> &precedence, const std::vector<int> &prev)
{
    if (precedence.find(num) != precedence.end())
    {
        for (int x : prev)
        {
            if (precedence.at(num).find(x) != precedence.at(num).end())
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    std::map<int, std::set<int>> precedence;
    std::string line;

    while (std::getline(std::cin, line) && !line.empty())
    {
        std::istringstream iss(line);
        int x, y;
        char separator;
        if (iss >> x >> separator >> y && separator == '|')
        {
            precedence[x].insert(y);
        }
    }

    int result = 0;
    while (std::getline(std::cin, line))
    {
        std::vector<int> prev;
        std::istringstream iss(line);
        std::string number;
        bool invalid = false;
        while (std::getline(iss, number, ','))
        {
            int num = std::stoi(number);
            if (canBePrinted(num, precedence, prev))
            {
                prev.push_back(num);
            }
            else
            {
                invalid = true;
                break;
            }
        }
        if (!invalid)
        {
            result += prev[prev.size() >> 1];
        }
    }

    std::cout << result << std::endl;
    return 0;
}
