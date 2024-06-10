#pragma once
#include <array>
#include <exception>
#include <string>

class exception_fish : std::exception
{
    std::string _message;
    
public:
    exception_fish(const std::string& message) : _message(message){}
    const char* what() const noexcept override
    {   
        
        return _message.c_str();
    }
};

class exception_boot : std::exception
{
    std::string _message;
    
public:
    exception_boot(const std::string& message) : _message(message){}
    const char* what() const noexcept override
    {   
        
        return _message.c_str();
    }
};


class Fishing
{
    enum class Items
    {
        FISH,
        BOOT,
        EMPTY
    };
    int _size_boot = 3;
    mutable int _col_fishing = 1;
    Items _pond[9];

    int random(int a, int b);

public:
    Fishing();

    void catchFish(std::size_t pond) const;
    int attempts() const {return _col_fishing;}
};