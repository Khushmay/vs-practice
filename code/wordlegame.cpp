#include<iostream>
#include<string_view>
#include<vector>
#include<string>
#include<limits>
#include<cctype>
#include"Random.h"

namespace words
{
    std::vector<std::string_view>words{ "apple", "brave", "crane", "track", "mango", "squid", "plumb", "ghost", "flame", "grape"};
    std::string_view getRandomWord()
    {
        return words[Random::get(0,words.size()-1)];
    }

}

class session
{
    private:
    std::string_view m_word{words::getRandomWord()};
    std::string m_userInput{"     "};
    std::string m_displayWord{"_____"};
    int m_guesses{5};
    int m_remainingGuesses{m_guesses};

    public:
    std::string_view getWord(){return m_word;} 
    std::string_view getDisplayWord(){return m_displayWord;} 
    std::string getUserInput(){return m_userInput;} 
    int getGuesses(){return m_guesses;} 
    int getRemainingGuesses(){return m_remainingGuesses;}

    void setDisplayWordUpperCase(std::size_t i)
    {
        m_displayWord[i]=std::toupper(m_userInput[i]);    
    }
    void setDisplayWordLowerCase(std::size_t i)
    {
        m_displayWord[i]=m_userInput[i];    
    } 
    void setUserInput(const std::string& userInput){m_userInput=userInput;}

    bool checkIfTheWordHasIt(char word)
    {
        for(auto& i:m_word)
        {
            if(i==word)
            {
                return true;
            }   
        }
        return false;
    }
    void subtractGuesses(){--m_remainingGuesses;}
    bool won()
    {
        if(m_userInput==m_word)
        {
            return true;
        }
        return false;
    }
};

std::string input(session& s)
{
    std::cout<<"ENTER THE WORD:";
    std::string userInput{};

    while(true)
    {
        std::cin>>userInput;

        if(!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n') ; 
            std::cout<<"The input was invalid.\n"<<"Enter the word:";
            continue;
        }
        if(userInput.size()!=5)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n') ; 
            std::cout<<"The input wansnt of 5 letters.\n"<<"Enter the word:";
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        return userInput;
    }
}

void display(session& s)
{
    std::cout<<"WORD:";

    for(int i{};i<5;++i)
    {
        if(s.getWord()[i]==s.getUserInput()[i])
        {
            s.setDisplayWordUpperCase(i);
            std::cout<<s.getDisplayWord()[i];
            continue;
        }
        if(s.checkIfTheWordHasIt(s.getUserInput()[i]))
        {
            s.setDisplayWordLowerCase(i);
            std::cout<<s.getDisplayWord()[i];
            continue;
        }
        std::cout<<"_";
        
    }
    std::cout<<'\n';
}

void handleWinAndLoss(session& s)
{
    if(s.won())
    {
        std::cout<<"congrats u got it right";
    }
    else
    {
        std::cout<<"U LOST , the word was :"<<s.getWord();
    }
}

int main()
{
    std::cout<<"      THE WORDLE BEGINS\n\n"<<"THE TASK: GUESS WORD IN 5 TRIES\n";
    std::cout<<"the lowercase means the wrong position\nthe UPPERCASE means right position\n";

    session s;
    for(int i{};i<s.getGuesses();++i)
    {
    s.setUserInput(input(s));
    display(s);
    s.subtractGuesses();
    if(s.won())
    {
        break;
    }
    }
    handleWinAndLoss(s);

}
 