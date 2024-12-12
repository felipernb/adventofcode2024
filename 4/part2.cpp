#include <vector>
#include <string>
#include <iostream>
bool hasDiagonal1(const std::vector<std::vector<char>> &matrix, int x, int y)
{
    if (matrix.size() - x < 3 || matrix[x].size() - y < 3)
        return false;
    std::string result;
    for (int i = 0; i < 3; ++i)
    {
        result += matrix[x + i][y + i];
    }
    return result == "MAS" || result == "SAM";
}

bool hasDiagonal2(const std::vector<std::vector<char>> &matrix, int x, int y)
{
    if (matrix.size() - x < 3 || y < 2)
        return false;
    std::string result;
    for (int i = 0; i < 3; ++i)
    {
        result += matrix[x + i][y - i];
    }
    return result == "MAS" || result == "SAM";
}

int main()
{
    std::vector<std::vector<char>> matrix;
    std::string line;

    while (std::getline(std::cin, line) && !line.empty())
    {
        std::vector<char> row(line.begin(), line.end());
        matrix.push_back(row);
    }

    int count = 0;
    for (int i = 1; i < matrix.size() - 1; ++i)
    {
        for (int j = 1; j < matrix[i].size() - 1; ++j)
        {
            count += matrix[i][j] == 'A' && hasDiagonal1(matrix, i - 1, j - 1) && hasDiagonal2(matrix, i - 1, j + 1);
        }
    }

    std::cout << count << std::endl;

    return 0;
}