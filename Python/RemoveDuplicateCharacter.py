from collections import OrderedDict 
  
# Function to remove all duplicates from string 
# and order does not matter 
def removeDupWithoutOrder(str): 
  
    # set() --> A Set is an unordered collection 
    #         data type that is iterable, mutable, 
    #         and has no duplicate elements. 
    # "".join() --> It joins two adjacent elements in 
    #             iterable with any symbol defined in 
    #             "" ( double quotes ) and returns a 
    #             single string 
    return "".join(set(str)) 
  
# Function to remove all duplicates from string 
# and keep the order of characters same 
def removeDupWithOrder(str): 
    return "".join(OrderedDict.fromkeys(str)) 
  
# Driver program 
if __name__ == "__main__": 
    str = "geeksforgeeks"
    print ("Without Order = ",removeDupWithoutOrder(str)) 
    print ("With Order = ",removeDupWithOrder(str)) 
