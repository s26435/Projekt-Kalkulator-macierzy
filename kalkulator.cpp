//Jan Wolski
//02.01.2021
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <cstdlib>

using  std::endl;
using  std::cin;
using  std::cout;

auto pow(int x, int n) -> int//potegowanie
{
    int wynik = 1;
    for(int i = 1; i <= n; i++)
    {
        wynik *= x;
    }
    return wynik;
}

int **create()//tworzenie macierzy
{
    int **matrix;
    matrix = new int *[3];
    for(int j=0; j < 3; j++)
    {
        matrix[j] = new int [3];
    }
    return matrix;
}

auto fillMatrix(int **matrix) -> void // wczytywanie macierzy z klawiatury
{
    char  it[25];
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cout << "Podaj: [" << i+1 << "][" << j+1 <<"] = ";
            cin >> it;
            matrix[i][j] = atoi(it); //atof zamienia stringa na int

        }
    }
}

auto freemem(int **matrix) -> void //czyszczenie pamieci po macierzach
{
    for(int i = 0; i < 3; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int **adding(int **matrixA, int **matrixB) //dodawanie
{
    int **matrixC = create();
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            matrixC[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
    return matrixC;
}

auto show(int **matrix) -> void //pokazywanie macierzy
{
    cout << endl;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

auto add() -> void //dodawanie
{
    cout << "--Dodawanie macierzy--" <<endl;
    int **A = create();
    int **B = create();
    cout << "Podaj liczby do macierzy A: " << endl;
    fillMatrix(A);
    cout << "Podaj liczby do macierzy B: " << endl;
    fillMatrix(B);
    int **C = adding(A, B);
    show(A);
    cout << " + " << endl;
    show(B);
    cout << " = " << endl;
    show(C);

    freemem(A);
    freemem(B);
}

int **substraction(int **matrixA, int **matrixB) //odejmowanie macierzy
{
    int **matrixC = create();
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            matrixC[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
    return matrixC;
}

auto sub() -> void //odejmowanie
{
    cout << "--Odejmowanie macierzy--" <<endl;
    int **A = create();
    int **B = create();
    cout << "Podaj liczby do macierzy A: " << endl;
    fillMatrix(A);
    cout << "Podaj liczby do macierzy B: " << endl;
    fillMatrix(B);
    int **C = substraction(A, B);
    show(A);
    cout << " - " << endl;
    show(B);
    cout << " = " << endl;
    show(C);
    freemem(A);
    freemem(B);
}

int **multiplication(int **A, int **B) //mnozenie macierzy
{

    int wynik = 0;
    int **C = create();
    for(int i = 0; i < 3; i++)//iterowanie dla m macierzy c
    {
        for(int g = 0; g < 3; g++)//iterowanie dla n macierzy c
        {
            wynik = 0;
            for(int j = 0; j < 3; j++)
            {
                wynik += A[i][j]*B[j][g];
            }
            C[i][g] = wynik;
        }
    }
    return C;
}

auto multi() -> void //mnozenie
{
        int **A = create();
        int **B = create();
        cout << "Podaj liczyby do macierzy A:" << endl;
        fillMatrix(A);
        cout << "Podaj liczyby do macierzy B:" << endl;
        fillMatrix(B);
        cout << "------ Mnozenie macierzy --------" << endl;
        show(A);
        cout << endl << " * " << endl;
        show(B);
        int **C = multiplication(A, B);
        cout << endl << " = " << endl;
        show(C);
}

int **transpozycja(int **matrix) //transponowanie macierzy
{
    int **trans = create();
     for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            trans[j][i] = matrix[i][j];
        }
    }
  return trans;
}

auto tran() -> void //transpozycja
{
    int **matrix = create();
    fillMatrix(matrix);
    cout << "----- Transponowanie macierzy -------" << endl;
    matrix = transpozycja(matrix);
    show(matrix);
}

auto main() -> int
{
short ch = 0;
    do
    {
        cout << "       KALKULATOR MACIERZY" << endl;
        cout << "----------------------------------" << endl;
        cout << "1 - dodawanie" << endl;
        cout << "2 - odejmowanie" << endl;
        cout << "3 - mnozenie" << endl;
        cout << "4 - Transpozycja" << endl;
        cout << "5 - koniec" << endl;
        cout << "----------------------------------" << endl;

        cin >> ch;
        switch(ch)
        {
        case 1:
            add();
            break;
        case 2:
            sub(); break;
        case 3:
            multi();
            break;
        case 4:
            tran();
            break;
        case 5:
            break;
        default:
            cout << "Zly znak!" << endl;
        }
    }
    while(ch!=5);
    return 0;
}
