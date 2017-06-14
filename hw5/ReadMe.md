

1.  The purpose of your program
    To sort integers efficiently with 3 different sorting algorithm
2.  List of files with one/or two-line summary
    main1.cpp,main2.cpp,main3.cpp are main client files 
    SelectionSort.h, sort2.h, sort3.h are header files for the 3 sorts
    SelectionSort.cpp, sort2.cpp, sort3.cpp are implementation files
    I implement sort2.cpp with quicksort; sort3.cpp with mergesort
3.  How to compile it (saying "use included Makefile" is ok)
    (1) type "make selectionSort" in command line to compile 
    selectionSort.cpp (an individual sort)
    (2) type "./selectionSort < randList100.txt" to input 
    testing file and run the program
    Note: replace "selectionSort" with "sort2" & "sort3" to compile 
          the other 2 sorts
    
4.  Outline of data structure (depending on the assignment)
     Dynamic Array
5.  Outline of algorithm (depending on the assignment)
  1.Selection Sort:
     How It Works:
     (1)An array is divided into 2 parts: sorted part and unsorted part.
     Initially, nothing is in sorted part, and the whole array is in
     the unsorted part. 
     (2)At every step, algorithm finds the smallest 
     element in the unsorted part and adds it to the end of the sorted
     part. 
     (3)Algorithm stops when unsorted part becomes empty.
     
     Complexity:
     selection sort algorithm is not very sensitive to the original order
     Worst Case: O(n^2)
     if the array is already sorted in descending order
     Best Case: O(n^2)
     a already sorted array
     Average Case: O(n^2)
     For whatever arrays, Selection Sort always do the 2 steps:
     find the smallest item and exchange it with the left-most unsorted element
     Space Complexity: O(n)
     
  2. Quick Sort:
     How It Works:
     
    (1)Choose a pivot value. Take the value of the middle element as pivot value. 
    It can be any value in range of sorted values. 
    In our case, we choose the value of the middle element.
    (2)Partition. Rearrange elements in such a way, that all elements 
    which are lesser than the pivot go to the left part of the array 
    and all elements greater than the pivot, go to the right part of the array. 
    Values equal to the pivot can stay in any part of the array. 
    (3)Sort both parts. Apply Quick Sort recursively to the left and the right parts.
    
    Complexity:
    depending on the choice of pivot
     Best Case:O(n log n)
     Worst Case: O(n^2)
     eg. choose the 1st element as the pivot for an sorted list
     Average Case:O(n log n)
     reference:
     http://www.cs.umd.edu/~meesh/351/mount/lectures/lec15-quicksort.pdf
     Space Complexity: O(log n)  (because of recursion)
     
  3. Merge Sort: 
     How It Works:
     To sort A[p .. r]:
     (1) Divide Step
	If a given array A has zero or one element, return; it is already sorted. 
	Otherwise, split A[p .. r] into two subarrays A[p .. q] and A[q + 1 .. r], 
	each containing about half of the elements of A[p .. r]. 
     (2) Conquer Step
	recursively sort the two subarrays A[p .. q] and A[q + 1 .. r].
     (3) Combine Step:
      
       (a) Introduce read-indices i, j to traverse arrays A and B, accordingly. 
    Introduce write-index k to store position of the first free cell in the resulting array.
    By default i = j = k = 0.
       (b) At each step: if both indices are in range (i < m and j < n), 
    choose minimum of (A[i], B[j]) and write it to C[k]. 
    Otherwise go to step 4.
       (c) Increase k and index of the array, algorithm located minimal value at, by one. 
    Repeat step 2.
       (d) Copy the rest values from the array, which index is still in range, to the resulting array.
      
     Complexity:
     Worst Case: O(n log n)
     Best Case: O(n log n)
     Average Case: O(n log n)
     Space Complexity(2n)
     
 * 4. REFERENCES:
     Selection Sort:
     http://www.personal.kent.edu/~rmuhamma/Algorithms/MyAlgorithms/Sorting/selectionSort.htm
     Quick Sort:    
     http://mathbits.com/MathBits/CompSci/Arrays/Quick.htm     
     Merge Sort:
     http://www.personal.kent.edu/~rmuhamma/Algorithms/MyAlgorithms/Sorting/mergeSort.htm
6.  A list of people who materially helped you on the assignment. 
    piazza