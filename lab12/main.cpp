#include <iostream>
#include <fstream>
#include "tasks.hpp"
using namespace std;
int first_task();
string third_task();
void fourth_task();
void fifth_task();
int main() {
    int decision;
    for (int i = 1; i > 0;) {
        clean();
        cout << "2. Второе задание\n";
        cout << "3. Третье задание\n";
        cout << "4. Четвертое задание\n";
        cout << "5. Пятое задание\n";
        cout << "Введите номер задания: ";
        cin >> decision;
        cin.get();
        switch (decision) {
            case 2:
                first_task();
                break;
            case 3:
                second_task();
                break;
            case 4:
                third_task();
                break;
            case 5:
                
                break;
                
            default:
                break;
        }
    }
}
