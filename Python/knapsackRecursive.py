def Knapsack(values,weights, capacity):
        n = len(values)
        if n==0 or capacity==0:
            return 0
        a = 0
        if weights[n-1] <= capacity:
            a =  values[n-1] + Knapsack(values[:n-1],weights[:n-1],capacity-weights[n-1])
        
        b =  Knapsack(values[:n-1],weights[:n-1],capacity)
                                              
        return max(a,b) 
        
print(Knapsack([1,6,10,16],[1,2,3,5], 10))