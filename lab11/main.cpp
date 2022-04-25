#include<iostream>
#include <iomanip>
using namespace std;

struct Sponsor
{
    char name[32];
    char surname[32];
    char lastname[32];
    char home_address[128];
    char narionality[32];
    char birthday[32];
    int numfactory;
    int tabnum;
    char education[128];
    int year_work;
};
Sponsor* AddStruct(Sponsor* Obj, const int amount);
void setData(Sponsor* Obj, const int amount);
void showData(const Sponsor* Obj, const int amount);
void redata(Sponsor* Obj, const int amount);
void find(const Sponsor* Obj, const int amount);
Sponsor* sort(Sponsor* Obj,  const int amount);
void sotf(Sponsor* Obj,  const int amount);
int main()
{
    setlocale(LC_ALL, "rus");

    Sponsor* OurSponsors = 0;
    int sponsorAmount = 0;
    int YesOrNot = 0; //  продолжить или остановить ввод данных
    int num;
    for(int i = 1; i > 0;){
        for (int u = 0 ; u < 100; u++) {
            cout << endl;

        }
        cout << "1. Добавление данных\n";
        cout << "2. Просмотр данных\n";
        cout << "3. Изменение данных\n";
        cout << "4. Сортировка\n";
        cout << "5. Поиск\n";
        cout << "6. Exit\n";
        cout << "Введите число: ";
        cin >> num;
        cin.get();
        for (int u = 0 ; u < 100; u++) {
            cout << endl;
        }
        if (num == 1) {
            do
            {
                OurSponsors = AddStruct(OurSponsors, sponsorAmount);
                setData(OurSponsors, sponsorAmount);

                sponsorAmount++;

                cout << "Продолжить ввод данных (1 - да, 0 - нет): ";
                cin >> YesOrNot;
                cin.get();
            } while (YesOrNot != 0);
        }

        if (num == 2){
            showData(OurSponsors, sponsorAmount);

        }
        if (num == 3) {
            redata(OurSponsors, sponsorAmount);
        }
        if (num == 4){
            OurSponsors = sort(OurSponsors, sponsorAmount);
        }
        if (num == 5){
            find(OurSponsors, sponsorAmount);
        }
        if (num == 6) {
            break;
        }

    }
    return 0;

}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Sponsor* AddStruct(Sponsor* Obj, const int amount)
{
    if (amount == 0)
    {
        Obj = new Sponsor[amount + 1]; // выделение памяти для первой структуры
    }
    else
    {
        Sponsor* tempObj = new Sponsor[amount + 1];

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
void setData(Sponsor* Obj, const int amount)
{
    cout << endl;
    cout << "Фамилия: ";
    cin.getline(Obj[amount].surname, 32);
    cout << "Имя: ";
    cin.getline(Obj[amount].name, 32);
    cout << "Отчество: ";
    cin.getline(Obj[amount].lastname, 32);
    cout << "Домашний адрес: ";
    cin.getline(Obj[amount].home_address, 128);
    cout << "Национальность: ";
    cin.getline(Obj[amount].narionality, 32);
    cout << "Дата Рождения: ";
    cin.getline(Obj[amount].birthday, 32);
    cout << "№ Цеха: ";
    cin >> Obj[amount].numfactory;
    cout << "Табельный номер: ";
    cin >> Obj[amount].tabnum;
    cout << "Образование: ";
    cin.get();
    cin.getline(Obj[amount].education, 32);
    cout << "Год поступления на работу: ";
    cin >> Obj[amount].year_work;
    cout << endl;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void showData(const Sponsor* Obj, const int amount)
{
    for (int i = 0; i < 100; i++) {
        cout << "\n";
    }
    cout << setw(2) << "№  " << setw(32) << "Фамилия\t\t" << setw(9) << "Имя\t\t\t" << "Отчество\t\t" << "Адрес\t\t\t\t" << "Группа\t\t" << "Рейтинг" << endl;
    cout << "=============================================================================================================================" << endl;
    for (int i = 0; i < amount; i++)
    {
        cout << i + 1 << "  " << setw(32) << Obj[i].surname << setw(9) << Obj[i].name << '\t'  << '\t' <<Obj[i].lastname << '\t' << '\t' << '\t'<< Obj[i].home_address << '\t' << '\t' << '\t' << '\t' << Obj[i].narionality << '\t' << '\t' << Obj[i].birthday << '\t' << Obj[i].numfactory << '\t' << Obj[i].tabnum << '\t' << Obj[i].education << '\t' << Obj[i].year_work <<'\t'  <<  endl;
    }
    int o;
    cout << "\n\nВведите 0 чтобы выйти: ";
    cin >> o;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void redata(Sponsor* Obj, const int amount){
    for (int i = 0; i < 100; i++) {
        cout << "\n";
    }
    cout << "Имя\n";
    for (int i = 0; i < amount; i++)
    {
        cout << i + 1 << "  " << Obj[i].name << endl;
    }
    cout << "\nВведите номер имени данные которого хотите изменить: ";
    int o, i;
    cin >> o;
    o--;
    for (int j = 1; j > 0;) {
        for (int i = 0; i < 100; i++) {
            cout << "\n";
        }
        cout << "1. Фамилия: " << Obj[o].surname << '\n' << "2. Имя: " << Obj[o].name << '\n' << "3. Отчество: "
             << Obj[o].lastname << '\n' << "4. Адрес: " << Obj[o].home_address << '\n' << "5. Национальность: " << Obj[o].narionality
             << '\n' << "6. Дата Рождения: " << Obj[o].birthday<< '\n' << "7. № Цеха: " << Obj[o].numfactory<< '\n' << "8. Табельный номер: " << Obj[o].tabnum<< '\n' << "9. Образование: " << Obj[o].education<< '\n' << "10. Год поступления на работу: " << Obj[o].year_work << endl;
        cout << "Введите число: ";
        cin >> i;
        cout << "Введите новые данные: ";
        switch (i) {
            case 1:
                cin >> Obj[o].surname;
                break;
            case 2:
                cin >> Obj[o].name;
                break;
            case 3:
                cin >> Obj[o].lastname;
                break;
            case 4:
                cin >> Obj[o].home_address;
                break;
            case 5:
                cin >> Obj[o].narionality;
                break;
            case 6:
                cin >> Obj[o].birthday;
                break;
            case 7:
                cin >> Obj[o].numfactory;
                break;
            case 8:
                cin >> Obj[o].tabnum;
                break;
            case 9:
                cin >> Obj[o].education;
                break;
            case 10:
                cin >> Obj[o].year_work;
                break;
            default:
                cout << "Неправильное число";
                break;
        }
        cout << "Желаете еще что-то изменить?(1 - да, 0 - нет): ";
        cin >> i;
        cin.get();
        if (i == 1){
            continue;
        } else if(i == 0){
            break;
        }
    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void find(const Sponsor* Obj, const int amount)
{
    char option;
    int a = 1;
    bool exit = false;
    cout << "Инструкция: b-база, n-имена, f-фамилии, o-отчество, d-домашний адрес, g-группы, r-рейтинг, t-# цеха, l-табельный номер, j-образование, u-год поступлени на работу, i-инструкция, e-выход" << endl;
    while (a > 0) {
        if (exit){
            break;
        }
        cout << "Введите опцию: ";
        cin >> option;
        switch (option) {
            case 'b':
                cout << "№  " << "Имя\t" << "Фамилия\t" << "Отчество\t" << "Домашний адрес\t" << "Группа\t" << "Рейтинг\t" << endl;
                cout << "========================================" << endl;
                for (int i = 0; i < amount; i++)
                {
                    cout << i + 1 << "  " << Obj[i].name << '\t' << Obj[i].surname << '\t' << Obj[i].lastname << '\t' << Obj[i].home_address << '\t' << Obj[i].narionality << '\t' << Obj[i].birthday << '\t' << Obj[i].numfactory << '\t' << Obj[i].tabnum << '\t' << Obj[i].education << '\t' << Obj[i].year_work << endl;
                }
                cout << endl;
                break;
            case 'n':
                cout << "№  " << "Имя\t" << endl;
                cout << "========================================" << endl;
                for (int i = 0; i < amount; i++)
                {
                    cout << i + 1 << "  " << Obj[i].name << endl;
                }
                cout << endl;
                break;
            case 'f':
                cout << "№  " << "Фамилия\t" << endl;
                cout << "========================================" << endl;
                for (int i = 0; i < amount; i++)
                {
                    cout << i + 1 << "  " << Obj[i].surname << endl;
                }
                cout << endl;
                break;
            case 'o':
                cout << "№  " << "Отчество\t" << endl;
                cout << "========================================" << endl;
                for (int i = 0; i < amount; i++)
                {
                    cout << i + 1 << "  " << Obj[i].lastname << endl;
                }
                cout << endl;
                break;
            case 'd':
                cout << "№  " << "Домаший адрес\t" << endl;
                cout << "========================================" << endl;
                for (int i = 0; i < amount; i++)
                {
                    cout << i + 1 << "  " << Obj[i].home_address << endl;
                }
                cout << endl;
                break;
            case 'g':
                cout << "№  " << "Национальность\t" << endl;
                cout << "========================================" << endl;
                for (int i = 0; i < amount; i++)
                {
                    cout << i + 1 << "  " << Obj[i].narionality << endl;
                }
                cout << endl;
                break;
            case 'r':
                cout << "№  " << "Дата Рождения\t" << endl;
                cout << "========================================" << endl;
                for (int i = 0; i < amount; i++)
                {
                    cout << i + 1 << "  " << Obj[i].birthday << endl;
                }
                cout << endl;
                break;
            case 't':
                cout << "№  " << "№ Цеха\t" << endl;
                cout << "========================================" << endl;
                for (int i = 0; i < amount; i++)
                {
                    cout << i + 1 << "  " << Obj[i].numfactory << endl;
                }
                cout << endl;
                break;
            case 'l':
                cout << "№  " << "Табельный номер\t" << endl;
                cout << "========================================" << endl;
                for (int i = 0; i < amount; i++)
                {
                    cout << i + 1 << "  " << Obj[i].tabnum << endl;
                }
                cout << endl;
                break;
            case 'j':
                cout << "№  " << "Образование\t" << endl;
                cout << "========================================" << endl;
                for (int i = 0; i < amount; i++)
                {
                    cout << i + 1 << "  " << Obj[i].education << endl;
                }
                cout << endl;
                break;
            case 'u':
                cout << "№  " << "Год поступления на работу\t" << endl;
                cout << "========================================" << endl;
                for (int i = 0; i < amount; i++)
                {
                    cout << i + 1 << "  " << Obj[i].year_work << endl;
                }
                cout << endl;
                break;
            case 'e':
                exit = true;
                break;
            case 'i':
                cout << "Инструкция: b-база, n-имена, f-фамилии, o-отчество, d-домашний адрес, g-группы, r-рейтинг, t-# цеха, l-табельный номер, j-образование, u-год поступлени на работу, i-инструкция, e-выход" << endl;
                cout << endl;
                break;

            default:
                cout << "Такой опции нет, если забыли, введите i\n";
        }
    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Sponsor* sort(Sponsor* Obj,  const int amount){
    int choise;
    cout << "1. Фамилия\n";
    cout << "2. Имя\n";
    cout << "3. Отчество\n";
    cout << "4. Домашний адрес\n";
    cout << "5. Национальность\n";
    cout << "6. Дата Рождения\n";
    cout << "7. № Цеха\n";
    cout << "8. Табельный номер\n";
    cout << "9. Образование\n";
    cout << "10. Год поступления на работу\n";
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
                        Sponsor* tempObj = new Sponsor[amount];
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
                        Sponsor* tempObj = new Sponsor[amount];
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
                        Sponsor* tempObj = new Sponsor[amount];
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
                        if (Obj[y].home_address[0] < Obj[y + 1].home_address[0]){
                            counter++;
                        }
                }
                if (counter == amount - 1) {
                    break;
                }
                counter = 0;
                if (Obj[i].home_address[0] > Obj[i + 1].home_address[0]){
                    if (i != amount - 1){
                        Sponsor* tempObj = new Sponsor[amount];
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
                        if (Obj[y].narionality[0] < Obj[y + 1].narionality[0]){
                            counter++;
                        }
                }
                if (counter == amount - 1) {
                    break;
                }
                counter = 0;
                if (Obj[i].narionality[0] > Obj[i + 1].narionality[0]){
                    if (i != amount - 1){
                        Sponsor* tempObj = new Sponsor[amount];
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
                        Sponsor* tempObj = new Sponsor[amount];
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
                        if (Obj[y].numfactory < Obj[y + 1].numfactory){
                            counter++;
                        }
                }
                if (counter == amount - 1) {
                    break;
                }
                counter = 0;
                if (Obj[i].numfactory > Obj[i + 1].numfactory){
                    if (i != amount - 1){
                        Sponsor* tempObj = new Sponsor[amount];
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
                        if (Obj[y].tabnum < Obj[y + 1].tabnum){
                            counter++;
                        }
                }
                if (counter == amount - 1) {
                    break;
                }
                counter = 0;
                if (Obj[i].tabnum > Obj[i + 1].tabnum){
                    if (i != amount - 1){
                        Sponsor* tempObj = new Sponsor[amount];
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
        
        case 9:
            for (int i = 0; i > -1; i++) {
                for (int y = 0; y < amount - 1; y++) {
                        if (Obj[y].education[0] < Obj[y + 1].education[0]){
                            counter++;
                        }
                }
                if (counter == amount - 1) {
                    break;
                }
                counter = 0;
                if (Obj[i].education[0] > Obj[i + 1].education[0]){
                    if (i != amount - 1){
                        Sponsor* tempObj = new Sponsor[amount];
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
        
        case 10:
            for (int i = 0; i > -1; i++) {
                for (int y = 0; y < amount - 1; y++) {
                        if (Obj[y].year_work < Obj[y + 1].year_work){
                            counter++;
                        }
                }
                if (counter == amount - 1) {
                    break;
                }
                counter = 0;
                if (Obj[i].year_work > Obj[i + 1].year_work){
                    if (i != amount - 1){
                        Sponsor* tempObj = new Sponsor[amount];
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
