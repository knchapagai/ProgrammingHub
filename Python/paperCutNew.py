#problem : how many squares of size k*k can be cut from n*n size board

no_of_case = int(input())

#test case loop
for testcase in range(no_of_case) :

    #taking input
    n , k = input().split()
    n = int(n)
    k = int(k)

    #Logic : quotient of n/k ; then squared is result
    no_of_cut_square = ( n//k ) ** 2
    print( no_of_cut_square)
