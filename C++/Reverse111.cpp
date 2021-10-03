#include <iostream>
#include<algorithm>
using namespace std;

int main() {
    string str = "Hello world!";
    reverse(str.begin(), str.end());
    cout << str;
    return 0;
}
