# ReadMe for COMP 15 HW3
## ISIS Course Roster and Waitlists

1.  The purpose of your program
    Model SIS, an course enrollment system to add & drop student 
    from roster & waitlist.

2.  List of files with one/or two-line summary
    queue.cpp ; implementation of queue ADT used for the 2 waitlist
    IsisCourse.cpp ; model a roster (Set), and two waitlists (Queues)

3.  How to compile it 
    by eclipse

4.  Outline of data structure 
ADT:
    Set for the course list; 
    queue for the 2 waitlists
data structrue:    
    both by dynamic arrays

5.  Outline of algorithm (depending on the assignment)
    waitlist_position:
    	1. determine if it is major or other waitlist
    	2. while not empty, dequeue
    	3. enqueue to temp list 
    	4. compare the dequeued value to student; if true, break
    	5. enqueue remaining elements of waitlist to temp
    	6. copy temp elements to waitlist

6.  A list of people who materially helped you on the assignment. 
     TA Alex Goldschmidt