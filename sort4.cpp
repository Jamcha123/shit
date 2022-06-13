#include <iostream>
#include <vector>
#include <iterator>
#include <memory>
#include <array>
#include <string>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
#include <fstream>
#include <conio.h>
#include <algorithm>
#include <iomanip>
#include <bits/stdc++.h>

int main()
{
    std::array<int, 10> arr1 = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    std::array<std::string, 10> arr2 = {"hello", "bye", "fuck", "shit", "popcorn", "pokimon", "milo", "defence", "vole", "ash"};
    std::array<char, 10> arr3 = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    std::vector<int> vec1;
    std::vector<std::string> vec2;
    std::vector<char> vec3;
    int dice;
    int num1, num2, num3;
    srand(time(0));
    char c;

    for(int i = 0; i < 100; i++)
    {
        dice = rand()%3 + 1;
        try{
            switch(dice)
            {
            case 1:
                for(int i = 0; i < arr1.size(); i++)
                {

                }
                break;
            case 2:
                for(int i = 0; i < arr2.size(); i++)
                {

                }
                break;
            case 3:
                for(int i = 0; i < arr3.size(); i++)
                {

                }
                break;
            default:
                throw(dice);
            }
        }
        catch(int n){
            std::cout << "error" << std::endl;
        }
    }
}
