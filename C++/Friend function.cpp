#include <bits/stdc++.h>
using namespace std;

class C2;
class C1
{
    int val1;
    friend void swapData(C1 &, C2 &); // Reference Taking with the friend function.

public:
    void indata(int a)
    {
        val1 = a;
    }
    void display(void)
    {
        cout << val1 << endl;
    }
};

class C2
{
    int val2;
    friend void swapData(C1 &, C2 &); // Reference Taking with the friend function.

public:
    void indata(int a)
    {
        val2 = a;
    }
    void display(void)
    {
        cout << val2 << endl;
    }
};

void swapData(C1 &c1, C2 &c2)
{
    int temp;
    temp = c1.val1;
    c1.val1 = c2.val2;
    c2.val2 = temp;
}
int main()
{
    C1 o1;
    C2 o2;
    o1.indata(12);
    o1.display();

    o2.indata(15);
    o2.display();

    swapData(o1, o2);
    cout << "The Value After Exchaning is : "<<endl;
    o1.display();
    o2.display();

    return 0;
}