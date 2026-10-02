#include<iostream>
#include<string>
#include<string_view>
#include"Random.h"

class Monster
{
    public:
    enum Type
   {
      dragon,
      goblin,
      ogre,
      orc, 
      skeleton, 
      troll, 
      vampire,
      zombie,
      maxMonsterTypes,
   };
    private:
   Type m_type{};
   std::string m_name{};
   std::string m_roar{};
   int m_hitPoints{};
   
   public:
   Monster(Type type ,std::string_view name,std::string_view roar,int hitPoints)
         :m_type{type},
          m_name{name},
          m_roar{roar},
          m_hitPoints{hitPoints}
          {
          }

constexpr std::string_view getTypeString(Type type) const
{
  switch(type)
  {
    case dragon: return"dragon";
    case  goblin: return"goblin";
    case  ogre: return"orge";
    case  orc: return"orc"; 
    case  skeleton: return"skeleton";
    case  troll: return"troll"; 
    case  vampire: return"vampire";
    case  zombie: return"zombie";
    case  maxMonsterTypes: return"maxMonsterTypes";
    default: return"??";
  }
}

void print() const
{
  if(m_hitPoints==0)
  {
    std::cout<<m_name<<" the "<<getTypeString(m_type)<<" is dead"<<"\n";
    return;
  }
  std::cout<<m_name<<" the "<<getTypeString(m_type)<<" has "<<m_hitPoints<<" hit points and says "<<m_roar<<"\n";
}
  
};

namespace MonsterGenerator
{
  constexpr std::string_view getName(int name)
  {
    switch(name)
    {
      case 0: return"Blank";
      case 1: return"Ronaldo";
      case 2: return "messi";
      case 3: return "zlatan";
      case 4: return "yashin";
      case 5: return "mbappu";
      default: return "???";
    }
  }
  constexpr std::string_view getRoar(int roar)
  {
    switch(roar)
    {
      case 0: return"tackle";
      case 1: return"shoot";
      case 2: return "dribble and shoot";
      case 3: return "fuck i am zlatan";
      case 4: return "blocked the weak shoot";
      case 5: return "run and shoot";
      default: return "???";
      
    }
  }
  constexpr Monster generate()
  {
    return Monster{
            static_cast<Monster::Type>(Random::get(0, Monster::maxMonsterTypes-1)),
            getName(Random::get(0,5)),
            getRoar(Random::get(0,5)),
            Random::get(1, 100)
            };
  }
}

int main()
{
   Monster m{ MonsterGenerator::generate()
  };
	m.print();

}

