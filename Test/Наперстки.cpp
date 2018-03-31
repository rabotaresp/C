#include <stdafx.h>
#include <iostream>
#include <ctime>
using namespace std;
 
int main()
{
    srand( time( 0 ) ); // автоматическая рандомизация
    cout << "rand_value = " << 1 + rand() % 10 << endl;
    system("pause");
    return 0;
}
