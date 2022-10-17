a=str(input("Enter the first Value : "))   #taking input from users
b=str(input("Enter the second value : "))
result=0            # use this to storing final values
for i in range(0,len(a)):     # loop 1 to get value 
    for j in range(0,len(b)):
        val1=i             #declaring value to calculate the "shift " first
        val1+=1     
        val2=j             
        val2+=1           #staring with the next index bcz first value get multiplied  
        while(val1<len(a)):         #calculating to first shift values
            counter+=1
            val1=val1+1
        while(val2<len(b)):
            counter+=1
            val2=val2+1
        c=(int(a[i])*int(b[j]))          #multiple value and store in varaible
        c=str(c)                          #changing into string bcz inserting 0's after it
        while counter>0:
                c=c+str(0)             #loop to inserting zero 
                counter-=1
        counter=0                     
        result+=int(c)                #adding  final result 
        
    
print("Final result is : ", result)
