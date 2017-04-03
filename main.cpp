#include <iostream>
#include <cstring>
#include <windows.h>

using namespace std;

bool q0(char);
bool q1(char, char);

int main()
{
    string str;
    int menu=1;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    while (menu)
    {
        bool f=true;
        system("CLS");
        cout<<"Задание: Пути шахматного короля по бесконечной доске с возвращением по пройденным клеткам в обратном порядке."<<endl;
        cout<<"Правила: A-начало, R-вправо, L-влево, D-вниз, U-вверх, B-конец."<<endl;
        cout<<"Вводить символы необходимо строкой"<<endl<<endl;

        cout<<"Верные примеры: ARRUULBRDDLL, ARDLBRUL." <<endl;
        cout<<"Неверные примеры: ARRUDBLLDU, ALUUDDR."<<endl<<endl;

        cout<<"Введите путь для проверки на корректность:"<<endl;
        cin>>str;
        int l=str.length();
        if (l%2==0)
        {
            for(int i=0, m=l; i<l; ++i, --m)
            {
                if (i==0)
                    f*=q0(str[i]);
                else
                    f*=q1(str[i],str[m]);
            }
            if (f)
                cout<<"Путь составлен ВЕРНО."<<endl;
            else
                cout<<"Путь составлен НЕВЕРНО."<<endl;
        }
        else
            cout<<"Путь составлен НЕВЕРНО."<<endl;
        cout<<endl<<"Введите 0, если хотите выйти из программы, иначе введите любое другое число"<<endl<<">";
        cin>>menu;
    }

}

bool q0(char ch)
{
    if (ch=='A') return true;
    else return false;
}

bool q1(char ch1, char ch2)
{
    if (ch1=='L' && ch2=='R') return true;
    else
    {
        if (ch1=='R' && ch2=='L') return true;
        else
        {
            if (ch1=='D' && ch2=='U') return true;
            else
            {
                if (ch1=='U' && ch2=='D') return true;
                else
                {
                    if (ch1=='B') return true;
                    else return false;
                }
            }
        }
    }
}
