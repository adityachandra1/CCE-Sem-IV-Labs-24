#include <iostream>
using namespace std;

int power(int x, unsigned int y)
{
    int temp;
    if( y == 0)
        return 1;
    temp = power(x, y / 2);
    if (y % 2 == 0)
        return temp * temp;
    else
        return x * temp * temp;
}

int main()
{
    int x, y;
    cout << "ENTER X AND Y WHERE X IS THE BASE AND Y IS THE EXPONENT VALUE: ";
    cin >> x >> y;
    cout << power(x, y);
}
