#include<iostream>
#include<vector>

template<typename T>
void printElement(const std::vector<T>& arr,int element)
{
    if(!(element<0||element>=std::ssize(arr)))
    {
        std::cout<<arr[static_cast<std::size_t>(element)]<<"\n";
    }
    else
    {
        std::cout<<"error the element doesnt exist"<<"\n";
    }
}

#include <iostream>
#include <vector>

// Write your printElement function here

int main()
{
    std::vector v1 { 0, 1, 2, 3, 4 };
    printElement(v1, 2);
    printElement(v1, 5);

    std::vector v2 { 1.2, 2.2, 3.3 };
    printElement(v2, 0);
    printElement(v2, -1);

    return 0;
}