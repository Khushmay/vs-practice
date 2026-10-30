#include<iostream>
#include<vector>
#include<string>

template<typename T>
bool isValueInArray(const std::vector<T>& arr,T name)
{
    bool found{false};
    for(const auto& num:arr)
    {
        if(num==name)
        {
            found=true;
            break;
        }
    }
   return found;
}

int main()
{
    std::cout<<"Enter a name:";
    std::string name{};
    std::cin>>name;

    std::vector<std::string> names{"Alex", "Betty", "Caroline", "Dave", "Emily","Fred", "Greg", "Holly"};

    bool found{isValueInArray(names,name)};
    if(found)
    {
       std::cout<<"the name was found in array";
    }
    else
    {
        std::cout<<"the name wasnt found in array";
    }

    
}