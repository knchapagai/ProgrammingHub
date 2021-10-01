# Write a short program that prints each number from 1 to 100 on a new line. 
# For each multiple of 3, print "Fizz" instead of the number. 
# For each multiple of 5, print "Buzz" instead of the number. 
# For numbers which are multiples of both 3 and 5, print "FizzBuzz" instead of the number.

def fizzbuzz(limit: int):
    fizzbuzz_list = []

    for num in range(1, limit + 1):
        if num % 15 == 0:
            fizzbuzz_list.append("FIZZBUZZ")
        elif num % 5 == 0:
            fizzbuzz_list.append("BUZZ")
        elif num % 3 == 0:
            fizzbuzz_list.append("FIZZ")
        else:
            fizzbuzz_list.append(num)

    return fizzbuzz_list   

print(fizzbuzz(20))
