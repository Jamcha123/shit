#include <iostream>
#include <vector>
#include <iterator>
#include <memory>
#include <string>
#include <array>
#include <fstream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
#include <algorithm>
#include <iomanip>
#include <bits/stdc++.h>

#define hello std::cout << "valkommen till sten, sax, pasar" << std::endl;

struct metrics
{
    uint32_t usage;
    uint32_t freed;

    uint32_t currentusage() {return usage - freed;}
};
static metrics s_metrics;
void* operator new(size_t size)
{
    s_metrics.usage += size;

    return malloc(size);
}
void operator delete(void* memory, size_t size)
{
    s_metrics.freed += size;

    free(memory);
}
static void memoryusage()
{
    std::cout << "memory usage is " << s_metrics.currentusage() << " bytes" << std::endl;
}
class roc1
{
    std::array<std::string, 3> arr1 = {"1. sten", "2. pasar", "3. sax"};
public:
    void stuff();
};
void roc1::stuff()
{
    std::array<std::string, 3>::iterator ptr;
    for(ptr = arr1.begin(); ptr < arr1.end(); ptr++)
    {
        std::cout << *ptr << " ";
    }
    std::cout << std::endl;
}
class single
{
    std::string player1;
    int pos = 0;
    int dice;
    int youdice;
    char choice;
    roc1 r;
public:
    void singlerock();
};
void single::singlerock()
{
    std::cout << "vad heter du : ";
    std::cin >> player1;
    memoryusage();
    do
    {
        std::cout << "valkomen " << player1 << std::endl;
        r.stuff();
        do
        {
            std::cout << "vilken valjer du? tryck nummer : \n";
            std::cin >> youdice;s
            if(youdice <= 0 || youdice > 3)
            {
                std::cout << "nummer ar for hog eller lag" << std::endl;
            }
        }while(youdice <= 0 || youdice > 3);
        system("cls");
        dice = rand()%3 + 1;
        if(youdice == dice)
        {
            std::cout << "ingen vinner" << std::endl;
        }
        else if(youdice == 1 && dice == 3)
        {
            std::cout << "du vann" << std::endl;
            pos++;
        }
        else if(youdice == 2 && dice == 1)
        {
            std::cout << "du vann" << std::endl;
            pos++;
        }
        else if(youdice == 3 && dice == 2)
        {
            std::cout << "du vann" << std::endl;
            pos++;
        }
        else
        {
            std::cout << "du forlora" << std::endl;
            pos--;
        }
        std::cout << "du har " << pos << std::endl;
        if(pos >= 3)
        {
            system("cls");
            std::cout << player1 << " vinner" << std::endl;
            break;
        }
        else if(pos <= -3)
        {
            system("cls");
            std::cout << player1 << " forlora" << std::endl;
            break;
        }
        std::cout << "vill du spela igen(j/n)?" << std::endl;
        std::cin >> choice;
        if(choice == 'n' || choice == 'N')
        {
            break;
        }
        system("cls");
    }while(choice == 'j' || choice == 'J');
}
class mulit
{

};
int main()
{
    single s;
    mulit m;
    int level;
    srand(time(0));
    hello;
    std::cout << "vill du spela ensam eller tillsammas : \n";
    std::cout << "1. ensam \n";
    std::cout << "2. tillsammas \n";
    std::cin >> level;
    try{
        if(level == 1)
        {
            s.singlerock();
        }
        else if(level == 2)
        {

        }
        else
        {
            throw(level);
        }
    }
    catch(int n)
    {
        std::cout << "wrong choice" << std::endl;
    }
}
