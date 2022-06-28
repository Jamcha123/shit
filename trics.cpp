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

struct node
{
    int data;
    node* next;
    node(int data)
    {
        this->data = data;
        next = 0;
    }
};
template<typename T>T mytype1(T x, T y, T z)
{
    std::ofstream file("linkfuck.txt", std::ios::app);
    node* head = new node(0);
    node* second = new node(0);
    node* third = new node(0);

    head->data = x;
    head->next = second;

    second->data = y;
    second->next = third;

    third->data = z;
    third->next = 0;

    file << head->data << " " << second->data << " " << third->data << " ";
}
int main()
{
    int num1, num2, num3;
    srand(time(0));

    num1 = rand()%1000 + 100;

    num2 = rand()%1000 + 100;

    num3 = rand()%1000 + 100;

    for(int i = 0; i < 1000; i++)
    {
        mytype1<int>(num1, num2, num3);
    }
    int key;
    int c = 1;
    char a = 'a';
    std::cout << "enter a key : ";
    std::cin >> key;

    std::fstream fin("linkfuck.txt", std::fstream::in);
    std::fstream fout("shitme.txt", std::fstream::out);

    while(fin >> c)
    {
        int temp = (key + a);

        fout << (char)temp;
    }
    fin.close();
    fout.close();
}
