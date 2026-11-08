#include <iostream>
#include <string_view>
#include <vector>
#include"Random.h"

namespace WordList
{
    std::vector<std::string_view> words{ "mystery", "broccoli", "account", "almost", "spaghetti", "opinion", "beautiful", "distance", "luggage" };
    std::string_view getRandomword()
    {
        return words[Random::get(0,8)];
    }
}

class Session
{
    private:
    std::string_view m_word{WordList::getRandomword()};
    std::vector<bool> m_wordsCheck=std::vector<bool>(26);
    std::size_t toIndex(char c) const { return static_cast<std::size_t>((c % 32)-1); }
    int m_wrongGuesses{5};
    char m_userInput{};
  
    public:
    std::string_view getWord(){return m_word;}
    int getGuesses(){return m_wrongGuesses;}
    int subtractguess(){return --m_wrongGuesses;}

    bool checkGuessedWords(char c){return m_wordsCheck[toIndex(c)];}
    void guessedWord(char i){m_wordsCheck[toIndex(i)]=true;}

    std::vector<bool>& getWordsEntered(){return m_wordsCheck;}

    bool checkWords(char c)
    {
        for(auto i:m_word)
        {
            if(i==c)
            {
                return true;
            }
        }
        return false;
    }

    bool won()
    {
        for(auto i:m_word)
        {
            if(!checkGuessedWords(i))
            {
                return false;
            }
        }
        return true;
    }

};

char input(Session& s)
{
   char input{};
    std::cout<<"Enter your next letter:";
    while(true)
    {
    std::cin>>input;

     if (!std::cin) 
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout<<"invalid input try again: " ;
            continue;
            
        }
       if (input < 'a' || input > 'z')
        {
            std::cout << "That wasn't a valid input.  Try again: ";
            continue;
        }  
        if(s.checkGuessedWords(input))
        {
            std::cout<<"you already guessed it , try again: ";
            continue;
        }
        return input;
       
    }
     
}

void draw(Session& s)
{
    std::cout<<"The word :";
    for(auto& i:s.getWord())
    {
        if(s.checkGuessedWords(i)==true)
        {
           std::cout<<i;
        }
        else
        {
            std::cout<<"_";
        } 
    }
    std::cout<<". ";
    for(int i{};i<s.getGuesses();++i)
    {
        std::cout<<"+";
    }
    for(char c{'a'};c<='z';++c)
    {
        if(s.checkGuessedWords(c)&&(!s.checkWords(c)))
        {
            std::cout<<c;
        }
    }
    std::cout<<'\n';
}
void handleGuess(Session& s,char c)
{
    if(s.checkGuessedWords(c)&&(!s.checkWords(c)))
    {
        s.subtractguess();
    }
}

bool handleEndOfGame(Session& s)
{
    if(s.getGuesses()==0)
    {
    std::cout<<"you failed to guess the word ="<<s.getWord()<<"\n";
    return true;
    }
    else if(s.won())
    {
        std::cout<<"you won congrats, the word was "<<s.getWord()<<"\n";
        return true;
    }

    return false;
}

int main()
{
    std::cout<<"Welcome to C++man (a variant of Hangman)\n"<<"To win: guess the word.  To lose: run out of pluses."<<"\n";
    std::cout<<'\n'<<'\n';
    Session s{};
    while(!(s.getGuesses()==0))
    {
    draw(s);
    char c{input(s)};
    s.guessedWord(c);
    handleGuess(s,c);
    if(handleEndOfGame(s))
    {
       break;
    }
    }

}



