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
        cout << "4. Exit\n";
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
        if (num == 4) {
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
    for (int i = 0; i < 100; i++) {
        cout << "\n";
    }
    cout << "1. " << Obj[o].surname << '\n' << "2. " << Obj[o].name << '\n' << "3. "<<Obj[o].lastname << '\n' << "4. " << Obj[o].home_address << '\n' << "5. "<< Obj[o].groop << '\n' << "6. " << Obj[o].reyt <<  endl;
    cout << "Введите число: ";
    cin >> i;
    switch (i) {
        case 1:
            cin.getline(Obj[o].surname, 32);
            break;
        case 2:
            cin.getline(Obj[o].name, 32);
            break;
        case 3:
            cin.getline(Obj[o].lastname, 32);
            break;
        case 4:
            cin.getline(Obj[o].home_address, 128);
            break;
        case 5:
            cin.getline(Obj[o].groop, 32);
            break;
        case 6:
            cin.getline(Obj[o].reyt, 32);
            break;
        default:
            cout << "Неправильное число";
            break;
    }
}
