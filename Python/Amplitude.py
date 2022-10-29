"""
You are given an array A of N interger and an interger K.
You want to remove K consecutive elements from A in such a way that the amplitude
of the remaing elements will be minimal. 
Here the amplitude is the difference between the maximal and the mimimal element.

Examples:

1.  A= [5,3,6,1,3]
    K= 2
    Output = 2

    Here we can remove the 3rd and the 4th element to obtain the following array:
    [5,3,3]. Hence the amplitude will be 5 - 3 = 2

2.  A= [3, 5, 1, 3, 9, 8]
    K= 4
    Output = 1

    Here we can remove the 1st, 2nd, 3rd,4th element to obtain the following array:
    [9, 8]. Hence the amplitude will be 9 - 8  = 1
"""

def solution( A, K):
    # length after removing K eements
    rem = len(A) - K
    # sorting the array
    A.sort()
    # getting all the ammplitude
    flag= [A[i]- A[i- rem+1] for i in range(rem-1, len(A))]
    # returing the minimun after removing the K consecutive
    return min(flag[K-1:])