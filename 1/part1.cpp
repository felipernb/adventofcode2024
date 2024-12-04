#include <iostream>
#include <sstream>
#include <queue>
#include <functional>

int main()
{
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap1;
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap2;
    std::string line;

    while (std::getline(std::cin, line))
    {
        std::istringstream iss(line);
        int num1, num2;
        if (iss >> num1 >> num2)
        {
            minHeap1.push(num1);
            minHeap2.push(num2);
        }
    }

    int distance = 0;
    while (!minHeap1.empty() && !minHeap2.empty())
    {
        distance += std::abs(minHeap1.top() - minHeap2.top());
        minHeap1.pop();
        minHeap2.pop();
    }

    std::cout << distance << std::endl;

    return 0;
}