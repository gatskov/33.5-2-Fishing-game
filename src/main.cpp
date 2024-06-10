#include <iostream>
#include "fishing.h"

int main()
{
    std::cout << "+- -- -- -- -- -- -- -- -- -- -- -- -- -- -+\n"
              << "| 33.5 Practical Work.Task 2. Fishing game |\n"
              << "+- -- -- -- -- -- -- -- -- -- -- -- -- -- -+\n\n";
    Fishing game;
    bool fishing = true;

    while (fishing)
    {
        std::cout << "Enter the sector number where the fish can be->  ";
        std::size_t pond;
        std::cin >> pond;
        try
        {
            game.catchFish(pond);
        }
        catch (const exception_fish &e)
        {
            std::cout << e.what() << " in " << game.attempts() << " attempts\n";
            fishing = false;
        }
        catch (const exception_boot &e)
        {
            std::cout << e.what() << '\n';
            fishing = false;
        }
        catch (const std::runtime_error &e)
        {
            std::cout << e.what() << '\n';
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    std::cout << "\n\t+~~~~~~~~~~~~~~+\n"
              << "\t| -=End game=- |\n"
              << "\t+~~~~~~~~~~~~~~+\n";
    return 0;
}