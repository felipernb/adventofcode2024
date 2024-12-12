#include <iostream>
#include <vector>
#include <string>

bool hasHorizontal(const std::vector<std::vector<char>> &matrix, int x, int y)
{
    if (matrix[x].size() - y < 4)
        return false;
    std::string result;
    for (int i = 0; i < 4; ++i)
    {
        result += matrix[x][y + i];
    }
    return result == "XMAS";
}

bool hasBackwardsHorizontal(const std::vector<std::vector<char>> &matrix, int x, int y)
{
    if (y < 3)
        return false;
    std::string result;
    for (int i = 0; i < 4; ++i)
    {
        result += matrix[x][y - i];
    }
    return result == "XMAS";
}

bool hasVertical(const std::vector<std::vector<char>> &matrix, int x, int y)
{
    if (matrix.size() - x < 4)
        return false;
    std::string result;
    for (int i = 0; i < 4; ++i)
    {
        result += matrix[x + i][y];
    }
    return result == "XMAS";
}

bool hasBackwardsVertical(const std::vector<std::vector<char>> &matrix, int x, int y)
{
    if (x < 3)
        return false;
    std::string result;
    for (int i = 0; i < 4; ++i)
    {
        result += matrix[x - i][y];
    }
    return result == "XMAS";
}

// Top to bottom, left to right
bool hasDiagonal1(const std::vector<std::vector<char>> &matrix, int x, int y)
{
    if (matrix.size() - x < 4 || matrix[x].size() - y < 4)
        return false;
    std::string result;
    for (int i = 0; i < 4; ++i)
    {
        result += matrix[x + i][y + i];
    }
    return result == "XMAS";
}

// Bottom to top, left to right
bool hasDiagonal2(const std::vector<std::vector<char>> &matrix, int x, int y)
{
    if (x < 3 || y < 3)
        return false;
    std::string result;
    for (int i = 0; i < 4; ++i)
    {
        result += matrix[x - i][y - i];
    }
    return result == "XMAS";
}

// Top to bottom, right to left
bool hasDiagonal3(const std::vector<std::vector<char>> &matrix, int x, int y)
{
    if (matrix.size() - x < 4 || y < 3)
        return false;
    std::string result;
    for (int i = 0; i < 4; ++i)
    {
        result += matrix[x + i][y - i];
    }
    return result == "XMAS";
}

// Bottom to top, right to left
bool hasDiagonal4(const std::vector<std::vector<char>> &matrix, int x, int y)
{
    if (x < 3 || matrix[x].size() - y < 4)
        return false;
    std::string result;
    for (int i = 0; i < 4; ++i)
    {
        result += matrix[x - i][y + i];
    }
    return result == "XMAS";
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
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[i].size(); ++j)
        {
            count += hasHorizontal(matrix, i, j);
            count += hasBackwardsHorizontal(matrix, i, j);
            count += hasVertical(matrix, i, j);
            count += hasBackwardsVertical(matrix, i, j);
            count += hasDiagonal1(matrix, i, j);
            count += hasDiagonal2(matrix, i, j);
            count += hasDiagonal3(matrix, i, j);
            count += hasDiagonal4(matrix, i, j);
        }
    }

    std::cout << count << std::endl;

    return 0;
}