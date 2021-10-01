def triangleShape(n):
    for i in range(n):
        for k in range(i+1):
            print('*',end=' ')
        print()

def poleShape(n):
    for i in range(n):
        print('*')

row = int(input('Enter number of rows: '))
triangleShape(row)
triangleShape(row)
poleShape(row)
