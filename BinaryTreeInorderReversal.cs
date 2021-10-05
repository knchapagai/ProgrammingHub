//C# program to implement In-order traversal in Binary Tree

using System;
using System.Collections.Generic;
using System. Text; 

class Node
{
    public int  item        ;
    public Node left_ptr    ;
    public Node right_ptr   ;
    
}
class BinaryTree
{
    public Node root;
    public Node GetRoot()
    {
        return root;
    }
    public void Inorder_Traverse(Node rootNode)
    {
        if (rootNode != null)
        {
            Inorder_Traverse(rootNode.left_ptr);
            Console.Write("{0} ", rootNode.item);
            Inorder_Traverse(rootNode.right_ptr);
        }
    }
    public void InsertItem(int item)
    {
        Node curNode;
        Node parentNode;
        Node node = new Node();
        
        node.item = item;

        if (root != null)
        {
            curNode = root;

            while (true)
            {
                parentNode = curNode;
                if (item < curNode.item)
                {
                    curNode = curNode.left_ptr;
                    if (curNode == null)
                    {
                        parentNode.left_ptr = node;
                        break;
                    }
                }
                else
                {
                    curNode = curNode.right_ptr;
                    if (curNode == null)
                    {
                        parentNode.right_ptr = node;
                        break;
                    }
                }
            }
        }
        else
        {
            root = node;
        }
    }
    
}
class Demo
{
    static void Main(string[] args)
    {
        BinaryTree tree = new BinaryTree();
       
        tree.InsertItem(10);
        tree.InsertItem(15);
        tree.InsertItem(35);
        tree.InsertItem(26);
        tree.InsertItem(47);
        tree.InsertItem(34);
        tree.InsertItem(90);
        
        Console.WriteLine("Inorder Traversal : ");
        tree.Inorder_Traverse(tree.GetRoot());
        Console.WriteLine(" ");
       
    }
}
