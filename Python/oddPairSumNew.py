noOfCases = int(input())

for testcase in range(noOfCases) :

    arr = input().split()

    checkingVal = 0 
    for i in range(len(arr)-1) :
        for j in range( i+1 , len(arr) ) :

            if ( int(arr[i]) + int(arr[j]) ) % 2 == 1 :
                checkingVal = 1

    if checkingVal == 1 :
        print("YES")
    else :
        print("NO")
