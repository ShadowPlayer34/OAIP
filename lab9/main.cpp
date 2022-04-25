#include<iostream>
using namespace std;

struct Sponsor
{
    char name[32];
    char surname[32];
    char lastname[32];
    char home_address[128];
    char groop[32];
    char reyt[32];
};
Sponsor* AddStruct(Sponsor* Obj, const int amount);
void setData(Sponsor* Obj, const int amount);
void showData(const Sponsor* Obj, const int amount);
void redata(Sponsor* Obj, const int amount);
void find(const Sponsor* Obj, const int amount);
Sponsor* del(Sponsor* Obj, const int amount);
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
        cout << "4. Удаление структуры\n";
        cout << "5. Сортировка\n";
        cout << "6. Поиск\n";
        cout << "7. Exit\n";
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
            del(OurSponsors, sponsorAmount);
            sponsorAmount--;
        }
        if (num == 5) {
            
        }
        if (num == 6){
            find(OurSponsors, sponsorAmount);
        }
        if (num == 7) {
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
    cout << "Группа: ";
    cin.getline(Obj[amount].groop, 32);
    cout << "Рейтинг: ";
    cin.getline(Obj[amount].reyt, 32);
    cout << endl;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void showData(const Sponsor* Obj, const int amount)
{
    for (int i = 0; i < 100; i++) {
        cout << "\n";
    }
    cout << "№  " << "Фамилия\t\t" << "Имя\t\t\t" << "Отчество\t\t" << "Адрес\t\t\t\t" << "Группа\t\t" << "Рейтинг" << endl;
    cout << "=============================================================================================================================" << endl;
    for (int i = 0; i < amount; i++)
    {
        cout << i + 1 << "  " << Obj[i].surname << '\t' << '\t' << Obj[i].name << '\t'  << '\t' <<Obj[i].lastname << '\t' << '\t' << '\t'<< Obj[i].home_address << '\t' << '\t' << '\t' << '\t' << Obj[i].groop << '\t' << '\t' << Obj[i].reyt <<'\t'  <<  endl;
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
             << Obj[o].lastname << '\n' << "4. Адрес: " << Obj[o].home_address << '\n' << "5. Группа: " << Obj[o].groop
             << '\n' << "6. Рейтинг: " << Obj[o].reyt << endl;
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
                cin >> Obj[o].groop;
                break;
            case 6:
                cin >> Obj[o].reyt;
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
    cout << "Инструкция: b-база, n-имена, f-фамилии, o-отчество, d-домашний адрес, g-группы, r-рейтинг, i-инструкция, e-выход" << endl;
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
                    cout << i + 1 << "  " << Obj[i].name << '\t' << Obj[i].surname << '\t' << Obj[i].lastname << '\t' << Obj[i].home_address << '\t' << Obj[i].groop << '\t' << Obj[i].reyt << endl;
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
                cout << "№  " << "Группа\t" << endl;
                cout << "========================================" << endl;
                for (int i = 0; i < amount; i++)
                {
                    cout << i + 1 << "  " << Obj[i].groop << endl;
                }
                cout << endl;
                break;
            case 'r':
                cout << "№  " << "Рейтинг\t" << endl;
                cout << "========================================" << endl;
                for (int i = 0; i < amount; i++)
                {
                    cout << i + 1 << "  " << Obj[i].reyt << endl;
                }
                cout << endl;
                break;
            case 'e':
                exit = true;
                break;
            case 'i':
                cout << "Инструкция: b-база, n-имена, f-фамилии, o-отчество, d-домашний адрес, g-группы, r-рейтинг, i-инструкция, e-выход" << endl;
                cout << endl;
                break;

            default:
                cout << "Такой опции нет, если забыли, введите i\n";
        }
    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Sponsor* del(Sponsor* Obj, const int amount){
    for (int i = 0; i < 100; i++) {
        cout << "\n";
    }
    cout << "Имя\n";
    for (int i = 0; i < amount; i++)
    {
        cout << i + 1 << "  " << Obj[i].name << endl;
    }
    cout << "\nВведите номер имени данные которого хотите изменить: ";
    int o;
    cin >> o;
    o--;
    Sponsor* time = new Sponsor[amount];
    for (int i = 0; i < amount; i++)
    {
        if(i == o){
            continue;
        }
        time[i] = Obj[i]; // копируем во временный объект
    }
    delete [] Obj;
    Obj = time;
    return Obj;
}
