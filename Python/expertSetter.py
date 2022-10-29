#loop for test cases
cases = int(input())

for test in range(cases):
    x , y = input().split()
    x = int(x)
    y = int(y)

    if ( y/x ) < 0.5 :
        print("No")
    else :
        print("Yes")
