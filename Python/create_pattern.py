# Nisrin Dhoondia
# x, y = list(map(int, input().split()))
x = 11
y = 31
midline = int(x / 2)
midpoint = int(y / 2)
hacktoberfeststr = 'Hacktoberfest-2021'

for i in range(0, x):
    j = 0
    while j < y:
        if i == 0:
            if j == 0:
                print('|', end = '')
                j = j + 1
                continue
            elif j == (y-1):
                print('|')
                j = j + 1
                continue
            else:
                print('*', end = '')
                j = j + 1
                continue
        elif i == (x-1):
            if j == 0:
                print('|', end = '')
                j = j + 1
                continue
            elif j == (y-1):
                print('|')
                j = j + 1
                continue
            else:
                print('*', end = '')
                j = j + 1
                continue
        elif i == midline:
            if j == (midpoint - (len(hacktoberfeststr) // 2)):
                for k in range(0, len(hacktoberfeststr)):
                    print(hacktoberfeststr[k], end = '')
                j = j + len(hacktoberfeststr)
                continue
            elif j % 2 == 0:
                if j != (y-1):
                    print('|', end = '')
                    j = j + 1
                    continue
                else:
                    print('|')
                    j = j + 1
                    continue
            else:
                if j != (y-1):
                    print('-', end = '')
                    j = j + 1
                    continue
                else:
                    print('-')
                    j = j + 1
                    continue
        elif j % 2 == 0:
            if j != (y-1):
                print('|', end = '')
                j = j + 1
                continue
            else:
                print('|')
                j = j + 1
                continue
        else:
            if j != (y-1):
                print('-', end = '')
                j = j + 1
                continue
            else:
                print('-')
                j = j + 1
                continue
