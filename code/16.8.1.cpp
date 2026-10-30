#include <iostream>
#include <string>
#include <string_view>
#include <vector>

int main()
{
    std::vector<std::string_view> names{ "Alex", "Betty", "Caroline", "Dave","Emily", "Fred", "Greg", "Holly" };

    std::cout << "Enter a name: ";
    std::string username{};
    std::cin >> username;

    bool found{ false };
    for (const auto& name : names)
    {
        if (name == username)
        {
            found = true;
            break;
        }
    }

    if (found)
        std::cout << username << " was found.\n";
    else
        std::cout << username << " was not found.\n";

    return 0;
}