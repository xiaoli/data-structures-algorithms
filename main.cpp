#include <iostream>
#include "chapter1.h"
using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    int a = 3;
    int b = 4;
    int c = 5;
    cout << Abc(a,b,c) << endl;
    cout << a << b << c << endl;

    cout << Factorial(5) << endl;

    int aa[3] = {1, 2, 3};
    cout << Rsum(aa, 3) << endl;

    char ab[] = {'1', '2', '3', '4', '5'};
    int n = 3;
    cout << "The permutations of 123 are" << endl;
    Perm(ab, 0, n-1);

    int ac;
    if (Input(ac)) cout << "The number is " << a << endl;
    else cout << "Did not get a nonnegative number" << endl;

    AscOrder(aa, 3);

    cout << factorial(5) << endl;

    cout << RFibonacci(3) << endl;
    cout << Fibonacci(3) << endl;

    Subsets(1, 4);

    return 0;
}
