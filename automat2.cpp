// automat2.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <cstdlib>
using namespace std;
void rysunek()
{
    std::cout << "   d    | Wejscia |\n";
    std::cout << "| Stany | 0  |  1 |\n";
    std::cout << "|  q0   | q1 | q2 |\n";
    std::cout << "|  q1   | q3 | q0 |\n";
    std::cout << "|  q2   | q0 | q3 |\n";
    std::cout << "|  q3   | q1 | q2 |\n";
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "   start            \n";
    std::cout << "    |           1        \n";
    std::cout << "    V       -------->    \n";
    std::cout << "     q0                  | q2 |  \n";
    std::cout << "            <--------    \n";
    std::cout << "     ^          0          ^  ";
    std::cout << "\n";
    std::cout << "     | |                   | |  \n";
    std::cout << "   1 | | 0               1 | | 1\n";
    std::cout << "     | |                   | |  \n";
    std::cout << "       V         0           V \n";
    std::cout << "             -------->       \n";
    std::cout << "     q1                     q3\n";
    std::cout << "             <--------    \n";
    std::cout << "                 0        \n";
}
void rysunekq0()
{
    
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "   start            \n";
    std::cout << "    |           1        \n";
    std::cout << "    V__     -------->    \n";
    std::cout << "    |q0|                 | q2 |\n";
    std::cout << "     ~~     <--------    \n";
    std::cout << "     ^          0          ^  ";
    std::cout << "\n";
    std::cout << "     | |                   | |  \n";
    std::cout << "   1 | | 0               1 | | 1\n";
    std::cout << "     | |                   | |  \n";
    std::cout << "       V         0           V \n";
    std::cout << "             -------->       \n";
    std::cout << "     q1                     q3\n";
    std::cout << "             <--------    \n";
    std::cout << "                 0        \n";
}
void rysunekq1()
{

    std::cout << "\n";
    std::cout << "\n";
    std::cout << "   start            \n";
    std::cout << "     |          1        \n";
    std::cout << "     V      -------->    \n";
    std::cout << "     q0                  | q2 |  \n";
    std::cout << "            <--------    \n";
    std::cout << "     ^          0          ^  ";
    std::cout << "\n";
    std::cout << "     | |                   | |  \n";
    std::cout << "   1 | | 0               1 | | 1\n";
    std::cout << "     | |                   | |  \n";
    std::cout << "       V         0           V \n";
    std::cout << "     __      -------->       \n";
    std::cout << "    |q1|                    q3\n";
    std::cout << "     ~~      <--------    \n";
    std::cout << "                 0        \n";
}
void rysunekq2()
{

    std::cout << "\n";
    std::cout << "\n";
    std::cout << "   start            \n";
    std::cout << "     |          1        \n";
    std::cout << "     V      -------->      __ \n";
    std::cout << "     q0                  ||q2||\n";
    std::cout << "            <--------      ~~ \n";
    std::cout << "     ^          0          ^  ";
    std::cout << "\n";
    std::cout << "     | |                   | |  \n";
    std::cout << "   1 | | 0               1 | | 1\n";
    std::cout << "     | |                   | |  \n";
    std::cout << "       V         0           V \n";
    std::cout << "             -------->       \n";
    std::cout << "     q1                     q3\n";
    std::cout << "             <--------    \n";
    std::cout << "                 0        \n";
}
void rysunekq3()
{

    std::cout << "\n";
    std::cout << "\n";
    std::cout << "   start            \n";
    std::cout << "     |          1        \n";
    std::cout << "     V      -------->    \n";
    std::cout << "     q0                  | q2 |  \n";
    std::cout << "            <--------    \n";
    std::cout << "     ^          0          ^  ";
    std::cout << "\n";
    std::cout << "     | |                   | |  \n";
    std::cout << "   1 | | 0               1 | | 1\n";
    std::cout << "     | |                   | |  \n";
    std::cout << "       V         0           V \n";
    std::cout << "             -------->      __ \n";
    std::cout << "     q1                    |q3|\n";
    std::cout << "             <--------      ~~\n";
    std::cout << "                 0        \n";
}
int main()
{
    string ciag;
    std::cout << "Program symulujacy dzialanie automatu skonczonego:\n";
    std::cout << " M = (Q, S, d, q0, F) ,gdzie Q = { q0, q1, q2, q3 },  S = {0, 1}, F={ q2 }.\n";
    std::cout << "\n";
   
    rysunek();
    std::cout << "\n";
    
    
    int n = 1;
    while (n==1)
    {
        std::cout << " Prosze podac ciag zlozony z symboli wejsciowych {0,1} \n ";
        std::cin >> ciag;
        std::cout << "\n";
        for (int i = 0;i < (ciag.length());i++)
        {
            if (ciag[i] == '0' || ciag[i] == '1')
            {
                n = 0;
            }
            else
            {
                std::cout << "nieprawidlowy ciag \n";
                n = 1;
                break;
            }
        }
    }
    string stan="q0";
    
    std::cout << "d ( " << stan << " , " << ciag << " ) \n";
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    string sciezka = stan;
    system("cls");
    rysunekq0();
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    for (int i = 0;i < ciag.length();i++)
    {
        sciezka += " --> ";
        switch (ciag[i])
        {
        case '1':
            sciezka += "(1)";
            sciezka += " --> ";
            if (stan == "q0")
            {
                system ("cls");
                stan = "q2";
                rysunekq2();
                std::this_thread::sleep_for(std::chrono::milliseconds(3000));
                sciezka += stan;
            }
            else if (stan == "q1")
            {
                system("cls");
                stan = "q0";
                rysunekq0();
                std::this_thread::sleep_for(std::chrono::milliseconds(3000));
                sciezka += stan;
            }
            else if (stan == "q2")
            {
                system("cls");
                stan = "q3";
                rysunekq3();
                std::this_thread::sleep_for(std::chrono::milliseconds(3000));
                sciezka += stan;
            }
            else if (stan == "q3")
            {
                system("cls");
                stan = "q2";
                rysunekq2();
                std::this_thread::sleep_for(std::chrono::milliseconds(3000));
                sciezka += stan;
            }
            break;
        case '0':
            sciezka += "(0)";
            sciezka += " --> ";
            if (stan == "q0")
            {
                system("cls");
                stan = "q1";
                rysunekq1();
                std::this_thread::sleep_for(std::chrono::milliseconds(3000));
                sciezka += stan;
            }
            else if (stan == "q1")
            {
                system("cls");
                stan = "q3";
                rysunekq3();
                std::this_thread::sleep_for(std::chrono::milliseconds(3000));
                sciezka += stan;
            }
            else if (stan == "q2")
            {
                system("cls");
                stan = "q0";
                rysunekq0();
                std::this_thread::sleep_for(std::chrono::milliseconds(3000));
                sciezka += stan;
            }
            else if (stan == "q3")
            {
                system("cls");
                stan = "q1";
                rysunekq1();
                std::this_thread::sleep_for(std::chrono::milliseconds(3000));
                sciezka += stan;
            }
            break;
        }
    }
    std::cout << "\n";
    std::cout << sciezka;
    std::cout << "\n";
    std::cout << "\n";
    if (sciezka[sciezka.length() - 1] == '2')
        std::cout << "Wejscie zostalo zaakceptowane  \n";
    else 
        std::cout << "Wejscie nie zostalo zaakceptowane  \n";


    return 0;
    



    


}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
