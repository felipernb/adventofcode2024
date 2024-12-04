#include <string>
#include <iostream>
#include <regex>

int main()
{
    std::string line;

    std::string finalString;
    while (std::getline(std::cin, line))
    {
        finalString += line;
    }

    const auto mulRegex = std::regex(R"(mul\((\d+),(\d+)\))");
    const auto disabledRegex = std::regex(R"(don't\(\).*?(do\(\)|$))");
    int result = 0;
    const auto cleanedUpLine = std::regex_replace(finalString, disabledRegex, "");
    auto matchesBegin = std::sregex_iterator(cleanedUpLine.begin(), cleanedUpLine.end(), mulRegex);
    auto matchesEnd = std::sregex_iterator();

    for (std::sregex_iterator i = matchesBegin; i != matchesEnd; ++i)
    {
        std::smatch match = *i;
        int num1 = std::stoi(match[1]);
        int num2 = std::stoi(match[2]);
        result += num1 * num2;
    }
    std::cout << result << std::endl;
    return 0;
}