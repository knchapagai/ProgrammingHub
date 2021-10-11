class HashMap():
    
    # Helper class
    class Node():

        def __init__(self, key, value):
            self.key = key
            self.value = value
            self.next = None

    # Public methods

    def __init__(self, size):
        self.size = size
        self.__arr = [None for i in range(size)]


    def get(self, key):
        ind = self.__hash(key) % self.size
        node = self.__find_key(ind, key)
        if node == None:
            return None
        return node.value


    def put(self, key, value):  
        ind = self.__hash(key)
        if self.__arr[ind] == None: 
            self.__arr[ind] = self.Node(key, value)
        else:
            last_node = self.__get_end_node(ind)
            last_node.next = self.Node(key, value)

    # Private methods
    def __hash(self, key):
        return hash(key) % self.size

    def __find_key(self, ind, key):
        node = self.__arr[ind]
        while node != None and node.key != key:
            node = node.next

        return node
        
    def __get_end_node(self, ind):
        node = self.__arr[ind]
        while node.next != None:
            node = node.next
        return node
