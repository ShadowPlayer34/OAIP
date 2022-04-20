#include <iostream>
#include <fstream>
using namespace std;
struct military{
    char surname[32];
    char name[32];
    char lastname[32];
    char home_adress[128];
    char nationality[32];
    char birthday[32];
    char position[32];
    char rank[32];
};
void space(){
    for (int u = 0 ; u < 100; u++) {
        cout << endl;

    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
ofstream add(){
    ofstream file("/Users/andrejhudik/Documents/Xcode/lab 13 OAIP s2/lab 13 OAIP s2/read.txt");
    if (file) {
        cout << "Создалось";
    }
    return file;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
military* AddStruct(military* Obj, const int amount)
{
    if (amount == 0)
    {
        Obj = new military[amount + 1]; // выделение памяти для первой структуры
    }
    else
    {
        military* tempObj = new military[amount + 1];

        for (int i = 0; i < amount; i++)
        {
            tempObj[i] = Obj[i]; // копируем во временный объект
        }
        delete [] Obj;

        Obj = tempObj;
    }
    return Obj;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void setData(military* Obj, const int amount)
{
    cout << endl;
    cout << "Surname: ";
    cin.getline(Obj[amount].surname, 32);
    cout << "Name: ";
    cin.getline(Obj[amount].name, 32);
    cout << "Lastname: ";
    cin.getline(Obj[amount].lastname, 32);
    cout << "Home Adress: ";
    cin.getline(Obj[amount].home_adress, 128);
    cout << "Nationality: ";
    cin.getline(Obj[amount].nationality, 32);
    cout << "birthday: ";
    cin.getline(Obj[amount].birthday, 32);
    cout << "position: ";
    cin.getline(Obj[amount].position, 32);
    cout << "rank: ";
    cin.getline(Obj[amount].rank, 32);
    cout << endl;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
ofstream addelement(military* Obj, const int amount){
    string text;
    ofstream add("/Users/andrejhudik/Documents/Xcode/lab 13 OAIP s2/lab 13 OAIP s2/read.txt");
    if (add){
        cout << "Файл открыт\n";
        for(int i = 0; i < amount; i++){
            add << "Surname: " << Obj[i].surname << "\t";
            add << "Name: " << Obj[i].name << "\t";
            add << "Lastname: " << Obj[i].lastname << "\t";
            add << "Home Adress: " << Obj[i].home_adress << "\t";
            add << "Birthday: " << Obj[i].birthday << "\t";
            add << "Nationality: " << Obj[i].nationality << "\t";
            add << "Position: " << Obj[i].position << "\t";
            add << "Rank: " << Obj[i].rank << "\t";
            add << "\n";
        }
        add.close();
    }
    return add;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void screen(){
    string word;
    ifstream file("/Users/andrejhudik/Documents/Xcode/lab 13 OAIP s2/lab 13 OAIP s2/read.txt");
    if (file) {
        cout << "Файл открыт\n";
        while (!file.eof()) {
            if (word == "Surname:"){
                cout << endl;
            }else{
                cout << word << " ";}
            file >> word;
        }
        cout << "\nДля выхода введите 0: ";
        cin >> word;
    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
military* del(military* Obj, const int amount){
    space();
    cout << "Имя\n";
    for (int i = 0; i < amount; i++)
    {
        cout << i + 1 << "  " << Obj[i].name << endl;
    }
    cout << "\nВведите номер имени данные которого хотите изменить: ";
    int o, choise;
    cin >> o;
    o--;
    for (int j = 1; j > 0;) {
        space();
        cout << "1. Фамилия: " << Obj[o].surname << '\n' << "2. Имя: " << Obj[o].name << '\n' << "3. Отчество: "
             << Obj[o].lastname << '\n' << "4. Адрес: " << Obj[o].home_adress << '\n' << "5. День Рождения: " << Obj[o].birthday << "\n" << "6. Национальность: " << Obj[o].nationality << '\n' << "7. Должность: " << Obj[o].position << '\n' << "8. Ранг: " << Obj[o].rank << endl;
        cout << "Введите число: ";
        cin >> choise;
        cout << "Введите новые данные: ";
        switch (choise) {
            case 1:
                memset(Obj[o].surname, 0, 20);
                break;
            case 2:
                memset(Obj[o].name, 0, 20);
                break;
            case 3:
                memset(Obj[o].lastname, 0, 20);
                break;
            case 4:
                memset(Obj[o].home_adress, 0, 40);
                break;
            case 5:
                memset(Obj[o].birthday, 0, 20);
                break;
            case 6:
                memset(Obj[o].nationality, 0, 20);
                break;
            case 7:
                memset(Obj[o].position, 0, 20);
                break;
            case 8:
                memset(Obj[o].rank, 0, 20);
                break;
            default:
                cout << "Неправильное число";
                break;
        }
        cout << "\nЖелаете еще что-то удалить?(1 - да, 0 - нет): ";
        cin >> choise;
        cin.get();
        if (choise == 1){
            continue;
        } else if(choise == 0){
            break;
        }
    }
    return Obj;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
military* sort(military* Obj,  const int amount){
    int choise;
    cout << "1. Surname\n";
    cout << "2. Name\n";
    cout << "3. Lastname\n";
    cout << "4. Home address\n";
    cout << "5. Nationality\n";
    cout << "6. Birthday\n";
    cout << "7. Position\n";
    cout << "8. Rank\n";
    cout << "Выберите что хотите отсортировать по алфавиту: ";
    cin >> choise;
    int counter = 0;
    switch (choise) {
        case 1:
            for (int i = 0; i > -1; i++) {
                for (int y = 0; y < amount - 1; y++) {
                        if (Obj[y].surname[0] < Obj[y + 1].surname[0]){
                            counter++;
                        }
                }
                if (counter == amount - 1) {
                    break;
                }
                counter = 0;
                if (Obj[i].surname[0] > Obj[i + 1].surname[0]){
                    if (i != amount - 1){
                        military* tempObj = new military[amount];
                        tempObj[i] = Obj[i];
                        Obj[i] = Obj[i + 1];
                        Obj[i + 1] = tempObj[i];
                        delete [] tempObj;
                    } else{
                        i = 0;
                        continue;
                    }
                }
            }
            break;
        case 2:
            for (int i = 0; i > -1; i++) {
                for (int y = 0; y < amount - 1; y++) {
                        if (Obj[y].name[0] < Obj[y + 1].name[0]){
                            counter++;
                        }
                }
                if (counter == amount - 1) {
                    break;
                }
                counter = 0;
                if (Obj[i].name[0] > Obj[i + 1].name[0]){
                    if (i != amount - 1){
                        military* tempObj = new military[amount];
                        tempObj[i] = Obj[i];
                        Obj[i] = Obj[i + 1];
                        Obj[i + 1] = tempObj[i];
                        delete [] tempObj;
                    } else{
                        i = 0;
                        continue;
                    }
                }
            }

            break;
        case 3:
            for (int i = 0; i > -1; i++) {
                for (int y = 0; y < amount - 1; y++) {
                        if (Obj[y].lastname[0] < Obj[y + 1].lastname[0]){
                            counter++;
                        }
                }
                if (counter == amount - 1) {
                    break;
                }
                counter = 0;
                if (Obj[i].lastname[0] > Obj[i + 1].lastname[0]){
                    if (i != amount - 1){
                        military* tempObj = new military[amount];
                        tempObj[i] = Obj[i];
                        Obj[i] = Obj[i + 1];
                        Obj[i + 1] = tempObj[i];
                        delete [] tempObj;
                    } else{
                        i = 0;
                        continue;
                    }
                }
            }

            break;
        case 4:
            for (int i = 0; i > -1; i++) {
                for (int y = 0; y < amount - 1; y++) {
                        if (Obj[y].home_adress[0] < Obj[y + 1].home_adress[0]){
                            counter++;
                        }
                }
                if (counter == amount - 1) {
                    break;
                }
                counter = 0;
                if (Obj[i].home_adress[0] > Obj[i + 1].home_adress[0]){
                    if (i != amount - 1){
                        military* tempObj = new military[amount];
                        tempObj[i] = Obj[i];
                        Obj[i] = Obj[i + 1];
                        Obj[i + 1] = tempObj[i];
                        delete [] tempObj;
                    } else{
                        i = 0;
                        continue;
                    }
                }
            }

            break;
        case 5:
            for (int i = 0; i > -1; i++) {
                for (int y = 0; y < amount - 1; y++) {
                        if (Obj[y].nationality[0] < Obj[y + 1].nationality[0]){
                            counter++;
                        }
                }
                if (counter == amount - 1) {
                    break;
                }
                counter = 0;
                if (Obj[i].nationality[0] > Obj[i + 1].nationality[0]){
                    if (i != amount - 1){
                        military* tempObj = new military[amount];
                        tempObj[i] = Obj[i];
                        Obj[i] = Obj[i + 1];
                        Obj[i + 1] = tempObj[i];
                        delete [] tempObj;
                    } else{
                        i = 0;
                        continue;
                    }
                }
            }

            break;
        case 6:
            for (int i = 0; i > -1; i++) {
                for (int y = 0; y < amount - 1; y++) {
                        if (Obj[y].birthday[0] < Obj[y + 1].birthday[0]){
                            counter++;
                        }
                }
                if (counter == amount - 1) {
                    break;
                }
                counter = 0;
                if (Obj[i].birthday[0] > Obj[i + 1].birthday[0]){
                    if (i != amount - 1){
                        military* tempObj = new military[amount];
                        tempObj[i] = Obj[i];
                        Obj[i] = Obj[i + 1];
                        Obj[i + 1] = tempObj[i];
                        delete [] tempObj;
                    } else{
                        i = 0;
                        continue;
                    }
                }
            }

            break;
    
        case 7:
            for (int i = 0; i > -1; i++) {
                for (int y = 0; y < amount - 1; y++) {
                        if (Obj[y].position < Obj[y + 1].position){
                            counter++;
                        }
                }
                if (counter == amount - 1) {
                    break;
                }
                counter = 0;
                if (Obj[i].position > Obj[i + 1].position){
                    if (i != amount - 1){
                        military* tempObj = new military[amount];
                        tempObj[i] = Obj[i];
                        Obj[i] = Obj[i + 1];
                        Obj[i + 1] = tempObj[i];
                        delete [] tempObj;
                    } else{
                        i = 0;
                        continue;
                    }
                }
            }

            break;
        
        case 8:
            for (int i = 0; i > -1; i++) {
                for (int y = 0; y < amount - 1; y++) {
                        if (Obj[y].rank < Obj[y + 1].rank){
                            counter++;
                        }
                }
                if (counter == amount - 1) {
                    break;
                }
                counter = 0;
                if (Obj[i].rank > Obj[i + 1].rank){
                    if (i != amount - 1){
                        military* tempObj = new military[amount];
                        tempObj[i] = Obj[i];
                        Obj[i] = Obj[i + 1];
                        Obj[i + 1] = tempObj[i];
                        delete [] tempObj;
                    } else{
                        i = 0;
                        continue;
                    }
                }
            }

            break;
    }
    return Obj;
}
