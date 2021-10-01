
row = int(input('Enter number of rows required: '))

for i in range(row):
    for j in range(row-i):
        print(' ', end='') 
    
    for j in range(2*i+1):
        if j==0 or j==2*i or i==row-1:
            print('*',end='')
        else:
            print(' ', end='')
    print()
