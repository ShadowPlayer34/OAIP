#include <iostream>
#include <fstream>
#include "function.hpp"
using namespace std;

int main() {
    srand (time(NULL));
    setlocale(LC_ALL, "rus");
    int num;
    int YesOrNot = 0;
    military* OurMilitry = 0;
    int militaryAmount = 0;
    for(int i = 1; i > 0;){
        space();
        cout << "1. Cоздание файла\n";
        cout << "2. Добавление данных в структуру\n";
        cout << "3. Добавление элементов(в конец)\n";
        cout << "4. Вывод\n";
        cout << "5. Удаление элемента\n";
        cout << "6. Сортировка\n";
        cout << "7. Бинарный файл\n";
        cout << "8. Exit\n";
        cout << "Введите число: ";
        cin >> num;
        cin.get();
        space();
        if (num == 1) {
            add();
        }
        if (num == 2){
            do
            {
                OurMilitry = AddStruct(OurMilitry, militaryAmount);
                setData(OurMilitry, militaryAmount);

                militaryAmount++;

                cout << "Продолжить ввод данных (1 - да, 0 - нет): ";
                cin >> YesOrNot;
                cin.get();
            } while (YesOrNot != 0);
        }
        if (num == 3){
            addelement(OurMilitry, militaryAmount);
        }
        if (num == 4) {
            screen();
        }
        if (num == 5){
            OurMilitry = del(OurMilitry, militaryAmount);
        }
        if (num == 6){
            OurMilitry = sort(OurMilitry, militaryAmount);
        }
        if (num == 7) {
            bin_file();
        }
        if (num == 8) {
            break;
        }
    }
    return 0;
}
