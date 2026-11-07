#include <iostream>
#include <vector>
#include <utility>

template<typename T>
std::pair<std::size_t, std::size_t> findMinAndMax(const std::vector<T>& arr)
{
    std::size_t min{ 0 };
    std::size_t max{ 0 };

    for (std::size_t i{ 1 }; i < arr.size(); ++i)
    {
        if (arr[i] < arr[min])
        {
            min = i;
        }
        if (arr[i] > arr[max])
        {
            max = i;
        }
    }

    return { min, max };
}

template<typename T>
void printArray(const std::vector<T>& arr)
{
    std::cout << "With array ( ";
    for (std::size_t i{ 0 }; i < arr.size(); ++i)
    {
        std::cout << arr[i];
        if (i + 1 < arr.size())
            std::cout << ", ";
        else
            std::cout << " ";
    }
    std::cout << ")\n";
}

template<typename T>
void printMaxAndMin(const std::vector<T>& arr)
{
    std::pair minAndMax{ findMinAndMax(arr) };
    
    std::cout << "The min element has index " << minAndMax.first << " and value " << arr[minAndMax.first] << '\n';

    std::cout << "The max element has index " << minAndMax.second<< " and value " << arr[minAndMax.second] << '\n';
}

int main()
{
    std::vector v1 { 3, 8, 2, 5, 7, 8, 3 };
    printArray(v1);
    printMaxAndMin(v1);

    std::vector v2 { 5.5, 2.7, 3.3, 7.6, 1.2, 8.8, 6.6 };
    printArray(v2);
    printMaxAndMin(v2);

    return 0;
}


