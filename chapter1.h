#ifndef CHAPTER1_H
#define CHAPTER1_H

#include <iostream>
using namespace std;

/**
 * CHAPTER 1
 *
 * Example Programs:
 */

// Program 1.1 Compute an integer expression
int Abc(int a, int b, int c)
{
    return a+b+b*c+(a+b-c)/(a+b)+4;
}

// Program 1.2 Compute a floating point expression
float Abc(float a, float b, float c)
{
    return a+b+b*c+(a+b-c)/(a+b)+4;
}

// Program 1.3 Compute an expression using a template function
template<class T>
T Abc(T a, T b, T c)
{
    return a+b+b*c+(a+b-c)/(a+b)+4;
}

// Program 1.4 Compute an expression using reference parameters
template<class T>
T Abc(T &a, T &b, T &c)
{
    return a+b+b*c+(a+b-c)/(a+b)+4;
}

// Program 1.5 Compute an expression using const reference parameters
template<class T>
T Abc(const T &a, const T &b, const T &c)
{
    return a+b+b*c+(a+b-c)/(a+b)+4;
}

// Program 1.6 A more general version of Program 1.5
template<class Ta, class Tb, class Tc>
Ta Abc(const Ta &a, const Tb &b, const Tc &c)
{
    return a+b+b*c+(a+b-c)/(a+b)+4;
}

// Program 1.7 Recursive function to compute n!
int Factorial(int n)
{
    if (n<=1) return 1;
    else return n * Factorial(n-1);
}

// Program 1.8 Add a[0:n-1]
template<class T>
T Sum(T a[], int n)
{// Return sum of numbers a[0:n -1].
   T tsum = 0;
   for (int i = 0; i < n; i++)
      tsum += a[i];
   return tsum;
}

// Program 1.9 Recursive code to add a[0:n-1]
template<class T>
T Rsum(T a[], int n)
{
    if (n > 0)
        return Rsum(a, n-1) + a[n-1];
    return 0;
}

// Program 1.11 Swap two values
template<class T>
inline void Swap(T &a, T &b)
{
    T temp = a; a = b; b = temp;
}

// Program 1.10 Recursive function for permutations
template<class T>
void Perm(T list[], int k, int m)
{// Generate all permutations of list[k:m].
    int i;
    if (k == m) {// list[k:m] has one permutation, output it
        for (i = 0; i <= m; i++)
            cout << list[i];
        cout << endl;
    }
    else    // list[k:m] has more than one permutation
            // generate these recursively
        for (i = k; i <= m; i++) {
            cout << "===SWAP1===" << k << "---" << i << endl;
            Swap(list[k], list[i]);

            cout << "===PERM===" << k+1 << "---" << m << endl;
            Perm(list, k+1, m);

            cout << "===SWAP2===" << k << "---" << i << endl;
            Swap(list[k], list[i]);
        }
}

// Exercise 1.1
template<class T>
bool Input(T& x)
{ // Input a nonnegative value.
    int NumOfAttempts = 3;

    // try at most NumOfAttempts times
    for (int i = 0; i < NumOfAttempts; i++) {
      cout << "Enter a nonnegative value" << endl;
      cin >> x;
      if (x >= 0) return true;
      cout << x << " is not nonnegative" << endl;
    }
    // did not get nonnegative value
    cout << "Sorry, you get only "
        << NumOfAttempts << " chances."
        << endl;
    return false;
}

// Exercise 1.2
template<class T>
bool AscOrder(T list[], int size)
{
    cout << "LIST SIZE " << size << endl;
    for (int i = 0; i < size - 1; i++) {
        if (list[i] > list[i+1]) {
            cout << i << " " << list[i] << " " << list[i+1] << " NOT ASC Order" << endl;
            return false;
        }
    }

    cout << "Yes, it is in ASC order" << endl;
    return true;
}

// Exercise 1.3
int factorial(int n)
{
    if (n<=1) return 1;
    int fact = 1;
    for (int i=1;i<=n;i++) {
        fact *= i;
    }
    return fact;
}

// Exercise 1.4.1 Recursive fibonacci function
int RFibonacci(int n)
{
    if (n<0) { cout << "Illeagel input!" << endl; return -1; }
    if (n==0) return 0;
    if (n==1) return 1;
    return RFibonacci(n-1) + RFibonacci(n-2);
}

// Exercise 1.4.3 Non recursive fibonacci function
int Fibonacci(int n)
{
    if (n<0) { cout << "Illeagel input!" << endl; return -1; }
    if (n==0) return 0;
    if (n==1) return 1;
    if (n>=2) {
        int a = 0;
        int b = 1;
        int result = 0;
        for (int i=2;i<=n;i++) {
            result = a + b;
            a = b;
            b = result;
        }
        return result;
    }
}

// Exercise 1.5
// define globals
int x[20];  // subset vector
void Subsets(int i, int n)
{// Output all subsets of x[1:n].
 // Only x[i:n] to be changed.
   if (i == n) {// x[n] can be 0 or 1
        // output subset without element n
        x[n] = 0;
        for (int j = 1; j <= n; j++)
           cout << x[j] << " ";
        cout << endl;

        // output subset with element n
        x[n] = 1;
        for (int j = 1; j <= n; j++)
           cout << x[j] << " ";
        cout << endl;
        return;
    }

    // leave element i out
    x[i] = 0;
    // generate all subsets with i out
    Subsets(i+1, n);

    // put element i into subset
    x[i] = 1;
    // generate all subsets with i included
    Subsets(i+1, n);
}

// Exercise 1.6
template<class T>
int rSequentialSearch(T a[], int n, const T& x)
{// Search the unordered list a[0:n-1] for x.
 // Return position if found; return -1 otherwise.
   if (n < 1) return -1;
   if (a[n-1] == x) return n - 1;
   return rSequentialSearch(a, n-1, x);
}

// Program 1.12 Allocate memory for a two-dimensional array
template<class T>
bool Make2DArray( T ** &x, int rows, int cols);

// Program 1.13 Make a two-dimensional array but do not catch exceptions
template<class T>
void Make2DArray( T ** &x, int rows, int cols);

// Program 1.14 Free the memory allocated by Make2DArray
template<class T>
void Delete2DArray( T ** &x, int rows);

// Program 1.15  Declaration of the class Currency
enum sign {plus, minus};
class Currency {
  public:

    // Program 1.16  Constructor for Currency
    Currency(sign s=sign::plus, unsigned long d = 0, unsigned int c = 0);

    // destructor
    ~Currency() {}

    // Program 1.17  Setting the private data members
    bool Set(sign s, unsigned long d, unsigned int c);
    bool Set(float a);
    sign Sign() const {return sgn;}
    unsigned long Dollars() const {return dollars;}
    unsigned int Cents() const {return cents;}

    // Program 1.18  Adding two currency values
    Currency Add(const Currency& x) const;

    // Program 1.19  Increment and Output
    Currency& Increment(const Currency& x);
    void Output() const;

  private:
    sign sgn;
    unsigned long dollars;
    unsigned int cents;
};

// Program 1.20  Application of the class Currency
void CurrencyDemo();

// Program 1.21  New declaration of the class Currency


// Program 1.22  New constructor and set codes


// Program 1.23  New code for Add and Output


// Program 1.24  Class declaration using operator overloading


// Program 1.25 Codes for +, Output, and <<


// Program 1.26  Using overloaded operators


// Program 1.27  Exception class BadInitializers


// Program 1.28  Throwing an exception


// Program 1.29  Overloading the friend `<<'


// Program 1.30  Compute and output the roots of a quadratic


// Program 1.31  Finding the largest element


#endif // CHAPTER1_H
