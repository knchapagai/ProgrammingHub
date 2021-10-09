from collections import deque
class graph:
    
    def __init__(self,vertices,gdict=None):
        self.vertices = vertices
        if gdict is None:
           gdict = {}
        self.gdict = gdict
        
    def AddEdge(self,i,j,undir=True):
        if i not in self.gdict:
            self.gdict[i] = []
        self.gdict[i].append(j)
        
        if undir:
            if j not in self.gdict:
                self.gdict[j] = []
            self.gdict[j].append(i)
    
    def PrintGraph(self):
        print(self.gdict)
        
    def BFS(self,source,dest=-1):
        visited = {}
        deq = deque()
        parent = {}
        dist = {}
        
        deq.append(source)
        visited[source]=True
        parent[source] = source
        dist[source] = 0
        
        while len(deq)>0:
            element = deq[0]
            print(element)
            print("###########")
            deq.popleft()
            
            if self.gdict[element] is not None:
                for i in self.gdict[element]:
                    if i not in visited:
                        deq.append(i)
                        visited[i]=True
                        parent[i] = element
                        dist[i] = dist[element]+1
                        
        print("Distance: {}".format(dist[dest]))
        print("Destination Path and Distances")
        
        if dest!=-1:
            print(dest)
            while dest!=source:
                print(parent[dest]) 
                dest = parent[dest]
                       
obj = graph(5)
obj.AddEdge(1,2)
obj.AddEdge(1,3)
obj.AddEdge(3,4)
obj.AddEdge(2,5)
obj.PrintGraph()
obj.BFS(1,5)