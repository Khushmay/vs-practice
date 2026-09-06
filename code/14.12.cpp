#include<iostream>
#include<string>
#include<string_view>

class Ball
{
    private:
    std::string m_color{};
    double m_radius {};

    public:

    Ball()
         :Ball("black",10)
         {

         }

    Ball(std::string_view color)
        :Ball(color,10)
        {

        }

    Ball(double radius)
        :Ball("black",radius)
        {

        }

    Ball(std::string_view color,double radius)
         :m_color{color},
         m_radius{radius}
         {
            std::cout<<"ball ("<<color<<","<<radius<<")"<<"\n";
         }

};

int main()
{
    Ball def{};
    Ball blue{ "blue" };
    Ball twenty{ 20.0 };
    Ball blueTwenty{ "blue", 20.0 };

    return 0;
}

