#include<iostream>
#include<vector>

int main()
{
    std::vector positivesquares{1,4,9,25,36};
    std::vector<double> temperature(365);

    std::vector<int> intValues(3);
    std::cout<<"enter 3 int values: ";
    std::cin>>intValues[0]>>intValues[1]>>intValues[2];

    std::cout<<"the sum of values is "<<intValues[0]+intValues[1]+intValues[2]<<"\n";
    std::cout<<"the product of values is "<<intValues[0]*intValues[1]*intValues[2]<<"\n";
}