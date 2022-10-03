#include <iostream>  
using namespace std;  
int main()  
{  
    int n1, n2, max_num, flag = 1;  
    cout << " Enter two numbers: \n";  
    cin >> n1 >> n2;      
      
    // use ternary operator to get the large number  
    max_num = (n1 > n2) ? n1 : n2;  
      
    while (flag)    
    {  
        // if statement checks max_num is completely divisible by n1 and n2.  
        if(max_num % n1 == 0 && max_num % n2 == 0)  
        {  
            cout << " The LCM of " <<n1 << " and " << n2 << " is " << max_num;  
            break;  
        }  
        ++max_num; // update by 1 on each iteration  
    }  
    return 0;  
}  
