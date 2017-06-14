# ReadMe for COMP 15 HW4
## Binary Search Tree Assignment 


1.  The purpose of your program
	code the implementation of BST
2.  List of files with one/or two-line summary
      BinarySearchTree.cpp
3.  How to compile it (saying "use included Makefile" is ok)
	eclipse build.
4.  Outline of data structure 
       Binary Search Tree
5.  Outline of algorithm 
	INSERT:
    check, whether value in current node and a new value are equal. 
    If so, duplicate is found. Otherwise,
    if a new value is less, than the node's value:
        if a current node has no left child, insert;
        otherwise, handle the left child with the same algorithm.
    if a new value is greater, than the node's value:
        if a current node has no right child, insert;
        otherwise, handle the right child with the same algorithm.

       REMOVE:
	1.Node to be removed has no children.
	 Sets corresponding link of the parent to NULL and disposes the node.
	2.Node to be removed has one child.
	 links single child directly to the parent of the removed node.
	3.Node to be removed has two children.
	replace the root with the leftest prescendent of the right child,
	and delelete that node.
6.  A list of people who materially helped you on the assignment. 
     Yu Lei, Xu Liu
