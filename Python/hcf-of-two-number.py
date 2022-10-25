def find_hcf(a,b):  
    while(b):  
        a, a = b, a % b  
        return a  
a = int(input (" Enter the first number: ") ) 
b = int(input (" Enter the second number: "))    
num = find_hcf(a, b)   
print("  The HCF of two number a and b is ")  
print(num)
