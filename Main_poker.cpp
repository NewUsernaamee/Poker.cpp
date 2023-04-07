// Main_poker.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <cstdlib>
#include <iostream>
#include <ctime>
#include "deck.h"
#include "game_rules.h"

#include "cards.h"
#include "hand.h"


//структура часть колоды

//создание псевдослучайного числа
int RandomInt(int min, int max)
{
    int x;
    x = min + std::rand() / ((RAND_MAX + 1u) / (max - min));
    return x;
}

//запуск в режиме обычной проверки
void start1(void)
{
    Deck deck = Deck();
    deck.Shufle();
    Hand topSeven;
    topSeven.TakeHand(deck);
    std::cout << topSeven;
    std::cout << "\n";
    topSeven.Boble();
    std::cout << topSeven;
    Hand Copy;
    Copy.CopyHand(topSeven);
    GameRules Cheker(Copy);
    Cheker.Check4();
    Cheker.Check3();
    Cheker.Check2();
    Cheker = Copy;
    Cheker.CheckStreet();
    Cheker.IsFlesh();
}
//проверка со стритом и флешем
void start2(void)
{
    Hand topSeven = topSeven.CreateStreetFlesh();
    std::cout << topSeven << "\n";
    GameRules Cheker(topSeven);
    Cheker.CheckStreet();
    Cheker.IsFlesh();
    std::cout << topSeven;
}

void start3(void)
{
    Hand topSeven = topSeven.CreateStreet();
    GameRules Cheker(topSeven);
    Cheker.CheckStreet();
    Cheker.IsFlesh();
    std::cout << topSeven;
}

void begin(int x)
{
    std::cout << ace << " " << ja << "\n";
    switch (x)
    {
    case 1:
        start1(); break;
    case 2:
        start2(); break;
    case 3:
        start3(); break;
    default:    break;
    }
}

int main()
{
    std::srand(time(0));

    int x;
    std::cout << "enter 1 if you want to check random generation\nenter 2 if you want to check function of street and flesh\nenter 3 if you want to check function of street\n";
    std::cin >> x;
    begin(x);
    return 0;

}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
