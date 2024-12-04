#include <vector>
#include <iostream>
#include <sstream>

bool isSafe(const std::vector<int> &report)
{
    int prevLevel = -1;
    bool isAscending;
    bool gotFirstPair = false;
    bool isSafe = true;
    for (int level : report)
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
    return isSafe;
}

std::vector<std::vector<int>> bruteForceDampening(const std::vector<int> &originalReport)
{
    std::vector<std::vector<int>> dampenedReports;
    for (size_t indexToRemove = 0; indexToRemove < originalReport.size(); ++indexToRemove)
    {

        std::vector<int> dampenedReport;
        dampenedReport.reserve(originalReport.size() - 1); // Reserve space for the new vector

        std::copy_if(originalReport.begin(), originalReport.end(), std::back_inserter(dampenedReport),
                     [indexToRemove, &originalReport, i = 0](int) mutable
                     {
                         return i++ != indexToRemove;
                     });

        dampenedReports.push_back(dampenedReport);
    }
    return dampenedReports;
}

int main()
{
    std::string line;
    int safe = 0;

    while (std::getline(std::cin, line))
    {
        std::istringstream iss(line);
        std::vector<int> report;
        int level;
        while (iss >> level)
        {
            report.push_back(level);
        }

        if (isSafe(report))
        {
            safe++;
        }
        else
        {
            for (std::vector<int> dampened : bruteForceDampening(report))
            {
                if (isSafe(dampened))
                {
                    safe++;
                    break;
                }
            }
        }
    }
    std::cout << safe << std::endl;
}