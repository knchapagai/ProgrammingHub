
def isPalindrome(x: int) -> bool:
        x = str(x)
        if len(x) <= 1:
            return True
        else:
            return x[0] == x[-1] and isPalindrome(x[1:-1])
        
print(isPalindrome(input("Please guess a letter: ")))

