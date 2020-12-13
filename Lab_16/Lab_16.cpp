/*
1. Дан текстовый файл, содержащий последовательность вещественных чисел. 
    Количество чисел в файле заранее не известно. 
    Найти минимальное по модулю значение в файле.
2. Дан текстовый файл, содержащий строки вещественных чисел. 
    Количество чисел в каждой строке может быть различным. 
    Вычислить минимум и максимум в каждой строке. 
    Результат записать в файл.

*/

#include <iostream>
#include <string>
#include <fstream>
#include "funs.h"

using namespace std;

void menu()
{
    cout << "/====================== MENU ======================\\\n";
    cout << "| 1. Минимальное по модулю вещ. значение           |\n";
    cout << "| 2. Минимум и максимум в строках                  |\n";
    cout << "| 9. Вывод меню                                    |\n";
    cout << "| 0. Выход                                         |\n";
    cout << "\\==================================================/\n";
}


int main()
{
    setlocale(LC_ALL, "rus");

    menu();
    string filename;
    cout << "Введите название файла:\n>> ";
    cin >> filename;  // testfile1 || testfile2 || testfile3
    int p;
    bool ext{ true };

    while (ext)
    {
        cout << "\nВыберите пункт меню: ";
        cin >> p;
        cout << "\n";

        ifstream file(filename + ".txt");
        if (!file.is_open())
            cout << "Error: file cannot be open!\n";
        else {
            switch (p) {
            case 1:
            {
                cout << "Минимальное вещественное число по модулю — " << find_min_abs(file) << '\n';
                cout << "Файл успешно обработан!\n";
                break;
            }
            case 2:
            {
                find_maxs_and_mins_in_file(file);
                cout << "Файл успешно обработан!\n";
                break;
            }
            case 9:
            {
                menu();
                break;
            }
            case 0:
            {
                ext = false;
                break;
            }
            default:
            {
                cout << "Нет такого пункта меню!\n";
            }
            }
            file.close();
        }
    }


    //system("pause");
    return 0;
}

