#include<iostream>
#include<vector>
#include<cassert>

namespace playerInventory
{
    enum inventory
    {
       potion,
       torch,
       arrow,
       max_items,

    };
}

std::string_view getItemNamePlural(playerInventory::inventory type)
{
    switch (type)
    {
        case playerInventory::potion:return "potions";
        case playerInventory::torch: return "torches";
        case playerInventory::arrow: return "arrows";

        default:return "???";
    }
}

std::string_view getItemNameSingular(playerInventory::inventory type)
{
    switch (type)
    {
        case playerInventory::potion:return "potion";
        case playerInventory::torch: return "torch";
        case playerInventory::arrow: return "arrow";

        default:return "???";
    }
}

template<typename T>
constexpr std::size_t toUZ(T value)
{
    static_assert(std::is_integral<T>() || std::is_enum<T>());

    return static_cast<std::size_t>(value);
}

int sumOfItems(const std::vector<int>& arr)
{
    int sum{0};
    for(auto& i:arr)
    {
        sum+=i;
    }    
    return sum;
}

void printItemsAndQuantity(const std::vector<int>& arr,playerInventory::inventory type)
{
    bool plural{false};
    if(arr[toUZ(type)]>1)
    {
        plural=true;
    }
    std::cout<<"You have "<<arr[toUZ(type)]<<" "<<(plural?getItemNamePlural(type):getItemNameSingular(type))<<"\n";
}

int main()
{
  std::vector itemCount{1,5,10};
  assert(std::size(itemCount) == playerInventory::max_items);

  for(int i{};i<playerInventory::max_items;i++)
  {
    printItemsAndQuantity(itemCount,static_cast<playerInventory::inventory>(i));
  }
  std::cout<<"You have "<<sumOfItems(itemCount)<<" total items"<<"\n";


}