#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
void clean(){
    for (int i = 0; i < 100; i++) {
        cout << endl;
    }
}
//----------------------------------------------------------------------------
int first_task(){
    clean();
    int size = 0;
    int counter = 0;
    int *mass = new int [size];
    ifstream file("/Users/andrejhudik/Documents/Xcode/lab12 OAIP s2/lab12 OAIP s2/read.txt");
    if(file){
        cout << "Файл открыт\n";
        while (!file.eof()){
            if (size == 0)
            {
                mass = new int[size + 1];
            }
            else
            {
                int *temp = new int[size + 1];

                for (int i = 0; i < size; i++)
                {
                    temp[i] = mass[i];
                }
                delete [] mass;

                mass = temp;
            }
        file >> mass[size];
        size++;
        }
    }
    for (int u = 0; u < size; u++){
        cout << mass[u] << " ";
    }
    for (int i = 0; i > -1; i++) {
        if(i >= size - 1){
            i = 0;
        }
        for (int y = 0; y < size - 1; y++) {
                if (mass[y] < mass[y + 1]){
                    counter++;
                }
        }
        if (counter == size - 1) {
            break;
        }
        counter = 0;
        if (mass[i] > mass[i + 1]){
            if (i < size - 1){
                int *tempObj = new int[size+1];
                tempObj[i] = mass[i];
                mass[i] = mass[i + 1];
                mass[i + 1] = tempObj[i];
                delete [] tempObj;
            }
        }

    }
    cout << endl;
    for (int u = 0; u < size; u++){
        cout << mass[u] << " ";
    }
    file.close();
    ofstream file1 ("/Users/andrejhudik/Documents/Xcode/lab12 OAIP s2/lab12 OAIP s2/read.txt", ios_base::app);
    if (file1){
        cout << endl << "Файл открыт";
        file1 << "\nОтсортированный массив: ";
        for (int i = 0; i < size; i++){
            file1 << mass[i] << " ";
        }
    }
    return 0;
}
//----------------------------------------------------------------------------
string second_task(){
    clean();
    string str;
    string term;
    int y;
    cout << "Введите текст: ";
    getline(cin, str);
    ofstream file ("/Users/andrejhudik/Documents/Xcode/lab12 OAIP s2/lab12 OAIP s2/read.txt", ios_base::app);
    if (file){
        ofstream termfile("/Users/andrejhudik/Documents/Xcode/lab12 OAIP s2/lab12 OAIP s2/termfile.txt");
        if (termfile){
            string term = "";
            cout << "\nФайл открыт временный\n";
            ifstream file2("/Users/andrejhudik/Documents/Xcode/lab12 OAIP s2/lab12 OAIP s2/read.txt");
            while(!file2.eof()){
                file2 >> term;
                term += ' ';
                termfile << term;
                
            }
            file2.close();
            termfile.close();
        }
        ofstream file3 ("/Users/andrejhudik/Documents/Xcode/lab12 OAIP s2/lab12 OAIP s2/read.txt");
        string term2 = "";
        ifstream termfile1("/Users/andrejhudik/Documents/Xcode/lab12 OAIP s2/lab12 OAIP s2/termfile.txt");
        file3 << str;
        while(!termfile1.eof()){
            file3 << term2 << " ";
            termfile1 >> term2;
        }
        cout << "Файл открыт\n";
    }else cout << "Файл не открыт";
    file.close();
    cout << "введите 0: ";
    cin >> y;
    return str;
}
//----------------------------------------------------------------------------
string third_task(){
    clean();
    string text;
    string temp;
    unsigned long length;
    unsigned long templength = 1111111;
    ifstream file("/Users/andrejhudik/Documents/Xcode/lab12 OAIP s2/lab12 OAIP s2/read.txt");
    if (file){
        cout << "Файл открыт\n";
        while(!file.eof()){
            file >> text;
            length = text.size()/2;
            if (length <= templength && length > 1){
                templength = length;
                temp = text;
            }
        }
        cout << "Самое короткое слово: ";
        cout << temp;
    }
    cout << "\nВведите 0 для выхода: ";
    cin >> length;
    
    return " ";
}
//----------------------------------------------------------------------------
void fifth_task(){
    string img;
    ifstream text ("/Users/andrejhudik/Documents/Xcode/lab12 OAIP s2/lab12 OAIP s2/read.txt");
    
}
