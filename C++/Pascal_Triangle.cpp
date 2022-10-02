#include <iostream>
using namespace std;

int main()
{
    int r, c = 1;

    cout << "Number of rows: ";
    cin >> r;

    for(int i = 0; i < r; i++)
    {
        for(int space = 1; space <= r-i; space++)
            cout <<"  ";

        for(int j = 0; j <= i; j++)
        {
            if (j == 0 || i == 0)
                c = 1;
            else
                c = c*(i-j+1)/j;

            cout << c << "   ";
        }
        cout << endl;
    }

    return 0;
}

/* Output:

Number of rows: 5

          1   
        1   1   
      1   2   1   
    1   3   3   1   
  1   4   6   4   1
  
*/
