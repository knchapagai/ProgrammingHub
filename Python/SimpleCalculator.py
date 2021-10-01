# Simple calculator
input_list = input().split()

if len(input_list) == 2:
    try:
        a,  b = map(int, input_list)

        print("{} + {} = {}".format(a, b, a+b))
        print("{} - {} = {}".format(a, b, a-b))
        print("{} * {} = {}".format(a, b, a*b))

        if b != 0:
            print("{} / {} = {}".format(a, b, a/b))
        else:
            print("Division by zero is not possible.".format(a, b))

    except:
        print("Please input numeric values. Try again.")

else:
    print("Plese input two numbers separated by space. Try again.")

