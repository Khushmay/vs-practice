#include <iostream>
#include <limits>
#include <vector>

template <typename T>
void printArray(const std::vector<T>& arr)
{
    for (std::size_t index{ 0 }; index < arr.size(); ++index)
    {
        std::cout << arr[index] << ' ';
    }

    if (arr.size() > 0)
        std::cout << '\n';
}

template <typename T>
int findIndex(const std::vector<T>& arr, T val)
{
    for (std::size_t index{ 0 }; index < arr.size(); ++index)
    {
        if (arr[index] == val)
            return static_cast<int>(index);
    }

    return -1; 
}

template <typename T>
T getValidNumber(std::string_view prompt, T low, T high)
{
    T val {};
    do
    {
        std::cout << prompt;
        std::cin >> val;

        if (!std::cin)
            std::cin.clear(); 

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    } while (val < low || val > high);

    return val;
}

int main()
{
    std::vector arr{ 4.4, 6.6, 7.7, 3.3, 8.8, 2.2, 1.1, 9.9 };

    auto num { getValidNumber("Enter a number between 1 and 9: ", 1.0, 9.0) };

    printArray(arr);

    int index { findIndex(arr, num) };

    if (index != -1)
        std::cout << "The number " << num << " has index " << index << '\n';
    else
        std::cout << "The number " << num << " was not found\n";

    return 0;
}