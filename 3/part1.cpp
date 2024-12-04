#include <string>
#include <iostream>
#include <regex>

int main()
{
    std::string line;

    const auto regex = std::regex(R"(mul\((\d+),(\d+)\))");
    long long result = 0;
    while (std::getline(std::cin, line))
    {
        auto matchesBegin = std::sregex_iterator(line.begin(), line.end(), regex);
        auto matchesEnd = std::sregex_iterator();

        for (std::sregex_iterator i = matchesBegin; i != matchesEnd; ++i)
        {
            std::smatch match = *i;
            int num1 = std::stoi(match[1]);
            int num2 = std::stoi(match[2]);
            result += num1 * num2;
        }
    }
    std::cout << result << std::endl;
    return 0;
}