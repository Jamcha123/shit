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
    system("cls");
    std::cout << "singleplayer" << std::endl;
    std::cout << "vad heter du : ";
    std::cin >> player1;
    do
    {
        system("cls");
        std::cout << "valkomen " << player1 << std::endl;
        r.stuff();
        do
        {
            std::cout << "vilken valjer du? tryck nummer : \n";
            std::cin >> youdice;
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
    std::string player1, player2;
    int youdice1, youdice2;
    int pos1 = 0;
    int pos2 = 0;
    char choice;
    roc1 r;
public:
    void mulitrock();
};
void mulit::mulitrock()
{
    system("cls");
    std::cout << "mulitplayer" << std::endl;
    std::cout << "forsta spelare namn : ";
    std::cin >> player1;
    std::cout << "andra spelare name : ";
    std::cin >> player2;
    do
    {

        system("cls");
        r.stuff();
        std::cout << player1 << " ska valja : ";
        std::cin >> youdice1;

        system("cls");
        r.stuff();
        std::cout << player2 << " ska valja : ";
        std::cin >> youdice2;

        system("cls");
        if(youdice1 == youdice2)
        {
            std::cout << "ingen vann" << std::endl;
        }
        else if(youdice1 == 1 && youdice2 == 3)
        {
            std::cout << player1 << " vann" << std::endl;
            pos1++;
        }
        else if(youdice1 == 2 && youdice2 == 1)
        {
            std::cout << player1 << " vann" << std::endl;
            pos1++;
        }
        else if(youdice1 == 3 && youdice2 == 2)
        {
            std::cout << player1 << " vann" << std::endl;
            pos1++;
        }
        else if(youdice1 == 1 && youdice2 == 2)
        {
            std::cout << player2 << " vann" << std::endl;
            pos2++;
        }
        else if(youdice1 == 2 && youdice2 == 3)
        {
            std::cout << player2 << " vann" << std::endl;
            pos2++;
        }
        else if(youdice1 == 3 && youdice2 == 1)
        {
            std::cout << player2 << " vann" << std::endl;
            pos2++;
        }
        else
        {
            std::cout << "en tryck fel nummer" << std::endl;
            break;
        }
        std::cout << player1 << " poang ar " << pos1 << std::endl;
        std::cout << player2 << " ponag ar " << pos2 << std::endl;
        if(pos1 >= 3)
        {
            system("cls");
            std::cout << player1 << " hade " << pos1 << " och vann spelat" << std::endl;
        }
        else if(pos2 >= 3)
        {
            system("cls");
            std::cout << player2 << " hade " << pos2 << " och vann spelat" << std::endl;
            break;
        }
        std::cout << "vill ni spela igen(j/n)";
        std::cin >> choice;
        if(choice == 'N' || choice == 'n')
        {
            break;
        }
    }while(choice == 'J' || choice == 'j');
}
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
            m.mulitrock();
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
