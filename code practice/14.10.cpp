#include<iostream>
#include<string>
#include<string_view>
class Ball
{
   private:
   std::string m_color{};
   double m_radius{};

   public:
   Ball(std::string_view color,double radius)
     :m_color{color},
      m_radius{radius}
      {

      }

   std::string_view getColor() const
   {
      return m_color;
   }
   double getRadius() const
   {
    return m_radius;
   }

};

void print(const Ball& b)
{
    std::cout<<"Ball ("<<b.getColor()<<","<<b.getRadius()<<")"<<"\n";
}

int main()
{
	Ball blue{"blue",10};

	print(blue);

	Ball red{"red",12};
	print(red);

	return 0;
}
