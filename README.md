# DSA-LAB
This repo holds the code and output screenshots of each DSA Lab of this Semester 4. <br>
Each folder is named according to Lab number. <br>
Inside each folder there is:
- readme file containing problem statement
- code of each problem
- screenshots of the output of each problem

## LAB 1

### Q1
Write a C/C++ program to traverse and print alternate elements of a linear character array. 
Rather than using a subscripted index, you are required to use a pointer to traverse the array

### Q2
Write a C/C++ program to find the minimum element in a linear integer array. Rather than using the subscripted index, you are required to use the pointer to access the elements of the linear array.

### Q3
Write a menu-driven  C program to perform Insertion, deletion, and display operations on an array of structures. 
Input: array of structures with the structure members being of integer, float and string data types.
Expected result:  To create an array of structures with its members suitably populated by the user through a function,                
suitably deleted and displayed through respective functions.

## LAB 2

### Q1
Write a C/C++ to perform advanced sorting techniques like quick and merge sorts on an array of structures. Perform the above sorting operations by implementing a menu with sort as options and sort it in ascending order.

## LAB 3

### Q1
Implementation of singly linked list

### Q2
Different operations on singly linked list

## LAB 4

### Q1
Implementation of circular linked list

### Q2
Different operations on circular linked list

## LAB 5

### Q1
Implementing stack using array.

### Q2
Convert infix expression to postfix expression.

## LAB 6

### Q1
Convert infix expression to prefix expression.

### Q2
Convert postfix expression to prefix expression.

## LAB 7

### Q1
Linked list implementation of priority queue.

### Q2
Array implementation of priority queue. In this implementation, assume the maximum size of all 1D queues are the same. 
Thus, you can use a 2D array for implementing the priority queue. Each 1D queue is to be implemented as a circular queue.

## LAB 8

### Q1
Linked list Implementation of a complete binary tree. The program must have the following functionalities.

Insert(): inserts a new ITEM to the complete binary tree. The items are of integer type.

Height(): returns height of a node recursively. Height (N) = MAX(Height(L), Height(R)) + 1. Here, L and R respectively represent the Left child and Right child of node N. Height of a leaf node is 0.

Preorder(): returns the preorder traversal sequence of the binary tree. Use recursive implementation.

Postorder(): returns the postorder traversal sequence of the binary tree. Use recursive implementation.

Inorder(): returns the inorder traversal sequence of the binary tree. Use recursive implementation.

## LAB 9

### Q1
 Write a program to implement a binary search tree (BST) having following functionalities.

BSTInsert(): This function adds a given ITEM to the BST. If the ITEM already exists in the BST then it will not insert the ITEM any more.

BSTSearch(): This function finds the LOCATION of a given ITEM in the BST. The function also returns PARENT location of the node containing the ITEM. 

BSTInorderStack(): This function finds Inorder traversal sequence of a BST using stack. You are not supposed to use recursive implementation of Inorder traversal.


User appropriate parameters to the functions.

Each node contains a character type of data.

## LAB 10

### Q1
You have implemented BST insertion in the previous lab session. Extend that program to perform deletion operations on BST. While deleting, consider all the deletion cases.

Deletion of node with degree 0.

Deletion of node with degree 1.

Deletion of node with degree 2.


## LAB 11

### Q1
 Write a program to implement the following operations on Graph(G) of Cities using the BFS algorithm.

Insert(): This function adds a node to the graph using adjacency matrix.

BFS_Display(): Print all the nodes reachable from a given starting node in a digraph using BFS  method.

BFS_Search():This function is  used to search for a key element in the tree and display “Search Success” in case of presence or “Search Failure” otherwise. Also display the path to the search of the key.

BFS_ Connect():Check whether a given graph is connected or not .

User appropriate parameters to the functions.

Each node contains a character type of data.


## LAB 12

### Q1
Given a weighted, undirected and connected graph G, the objective is to find the minimum spanning tree G' for G using prim's algorithm

a.Initially, the tree is empty.

b.The tree starts building from a random source vertex.

c.A new vertex gets added to the tree at every step.

d.This continues till all the vertices of the graph are added to the tree.

Input:A Cost Adjacency Matrix for  graph G.

Output: Spanning tree with minimum cost .It should print the edge and its corresponding weight and finally total minimum cost.