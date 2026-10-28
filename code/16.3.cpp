#include<iostream>
#include<vector>

int main()
{
    std::vector vovels{'a','e','i','o','u'};
    std::cout<<"the number of values in array is "<<static_cast<int>(std::ssize(vovels))<<"\n";

    std::cout<<vovels.at(3)<<vovels[3];

}