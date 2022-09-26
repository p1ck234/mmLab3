#include <iostream>
#include <fstream>
#include <istream>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int find(char *образец, char *строка)
{
    // i-с какого места строки  ищем
    // j-с какого места образца ищем
    for (int i=0;строка[i];++i) {
        for (int j=0;;++j) {
            if (!образец[j]) return i; // образец найден
            if(строка[i+j]!=образец[j]) break;
        }
        // пока не найден, продолжим внешний цикл
    }
    // образца нет
    return -1;
}

int main() {
    const int N=400,M=100;
    string s;
    char Stroka[N]{};
    char Obraz[M]{"host"};
    /*ifstream File;
    File.open("//Users//p1ck23//c++//bud3//bud3//input.txt");
    int counter = 0;
    while (!File.eof())
    {
        for(int i = 0;i<N; i++)
        {
            File>>Stroka[i];
            counter++;
        }
        //File.getline(Stroka,N);
    }
    File.close();*/
    std::ifstream file("//Users//p1ck23//c++//bud3//bud3//input.txt", std::ifstream::binary);
        if (file) {
            file.seekg(0, file.end);
            int length = file.tellg();
            file.seekg(0, file.beg);
            char* arr = new char[length];
            file.read(arr, length);
            file.close();
            std::cout.write(arr, length);
            for (int i = 0; i < length; i++) {
                Stroka[i] = arr[i];
            }
            delete[] arr;
        }
    for (int i = 0; i<N; i++)
    {
        cout<<Stroka[i];
    }
    //cout << endl << strlen(Stroka)<<"   " << counter << endl;
    //cout << strlen(Obraz) << endl;
    cout<<Obraz<< endl;
    int res = -1;
    for (int i = 0; i<N-strlen(Obraz)+1; i++)
    {
        for (int j=0; j<strlen(Obraz); j++)
        {
            if (Stroka[i + j] != Obraz[j]) break;
            else if(j==strlen(Obraz)-1) {res=i;break;}
        }
    }
    
    cout<< "Direct Search: " << res << endl;
    cout << "Knut-Morris-Pratt: " << find(Obraz, Stroka) << endl;
}

