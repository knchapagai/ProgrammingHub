def isAutomorphic(N) : 
    sq = N * N 
    while (N > 0) : 
        if (N % 10 != sq % 10) : 
            return False
        N /= 10
        sq /= 10
        else:
            return True
N = int(input("Enter the number:"))
if isAutomorphic(N) : 
    print ("Automorphic")
else : 
    print  ("Not Automorphic")
