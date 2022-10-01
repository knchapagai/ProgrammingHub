class node:
    def __init__(self,key):
        self.key=key
        self.left=None
        self.right=None

def NN(t): #Count number of nodes in a tree
    if t:
        l = NN(t.left)
        r = NN(t.right)
        return (1 + l + r)
    else:
        return 0

def Number_leaves(t):
    if t==None:
        return 0
    elif t.left==None and t.right==None:
        return 1
    else:
        l=Number_leaves(t.left)
        r=Number_leaves(t.right)
        return l+r
def Number_nonLeaves(t):
    if t==None:
        return 0
    elif t.left==None and t.right==None:
        return 0
    else:
        return (1+Number_nonLeaves(t.left)+Number_nonLeaves(t.right))

def count_full_nodes(root):
    t=root
    if t==None:
        return 0
    elif t.left==None and t.right==None:
        return 0
    else:
        l=count_full_nodes(t.left)
        r=count_full_nodes(t.right)
        c= (1 if (t.left!=None and t.right!=None) else 0 )
        return l+r+c

# Test Cases 

root=node(100)
root.left=node(200)
root.right=node(300)
root.left.left=node(400)
root.left.right=node(500)
root.right.left=node(600)
root.right.right=node(700)

print(NN(root),"<--- No. of nodes")
print(Number_leaves(root),"<--- No. of leaves")
print(Number_nonLeaves(root))

