#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

template<typename T>
void qsort(T arry[], int begin, int end);

int main()
{
    int length;
    cout << "输入长度:";
    cin >> length;
    char *arry = new char[length];
    srand(time(0));
    for (int i = 0; i < length; i++)
        //cin >> arry[i];
        arry[i] = rand() % 26 + 97;

    qsort(arry, 0, length-1);
    //cout << (int)'a' << endl;
    for (int i = 0; i < length; i++)
        cout << arry[i] << ' ';
    cout << endl;

    return 0;
}

template<typename T>
void qsort(T arry[], int begin, int end)
{
    if (begin >= end)
        return;
    int b = begin-1;
    int flag = 0;
    for(int i = begin; i <= end; i++)
    {
        if (arry[i] <= arry[end])
        {
            b++;
            T tmp = arry[i];
            arry[i] = arry[b];
            arry[b] = tmp;

        }
    }
    qsort(arry, begin, b-1);
    qsort(arry, b+1, end);
}
