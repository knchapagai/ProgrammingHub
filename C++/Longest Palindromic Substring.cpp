#include <bits/stdc++.h>
using namespace std;
 
int longestPalSubstr(char* str)
{
    // The result (length of LPS)
    int maxLength = 1;
 
    int start = 0;
    int len = strlen(str);
 
    int low, high;
 
    // One by one consider every
    // character as center point of
    // even and length palindromes
    for (int i = 1; i < len; ++i) {
        // Find the longest even length palindrome
        // with center points as i-1 and i.
        low = i - 1;
        high = i;
        while (low >= 0 && high < len
               && str[low] == str[high]) {
            --low;
            ++high;
        }
 
          // Move back to the last possible valid palindrom substring
        // as that will anyway be the longest from above loop
        ++low; --high;
          if (str[low] == str[high] && high - low + 1 > maxLength) {
            start = low;
              maxLength = high - low + 1;
        }
 
        // Find the longest odd length
        // palindrome with center point as i
        low = i - 1;
        high = i + 1;
        while (low >= 0 && high < len
               && str[low] == str[high]) {
            --low;
            ++high;
        }
 
        // Move back to the last possible valid palindrom substring
          // as that will anyway be the longest from above loop
        ++low; --high;
          if (str[low] == str[high] && high - low + 1 > maxLength) {
            start = low;
              maxLength = high - low + 1;
        }
    }
 
    cout << "Longest palindrome substring is: ";
    int ans=maxlength; 
    while(ans--)
      cout<<str[start++];
 
      return maxLength;
}
 
// Driver program to test above functions
int main()
{
    char str[] = "forgeeksskeegfor";
    cout << "\nLength is: "
         << longestPalSubstr(str)
         << endl;
    return 0;
}
 
