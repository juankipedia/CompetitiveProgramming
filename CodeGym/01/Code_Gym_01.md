*Code Gym 01.*

#Data Structures.

Data structure is ‘a way to store and organize data’ in order to support
efficient insertions, queries, searches, updates, and deletions.

Although a data structure in itself does not solve the given programming problem
-the algorithm operating on it does-, using the most efficient data structure
for the given problem may be a difference between passing or exceeding the
problem’s time limit.

Note that for competitive programming, you just have to be able to use
(i.e. know the strengths, weaknesses, and time/space complexities) a certain data
structure to solve the appropriate contest problem. Its theoretical background is
good to know, but can be skipped.

##Data Structures with Built-in Libraries

###Linear Data Structures
A data structure is classified as linear if its elements form a sequence.
Sorting and searching:

* Sorting
 1. O(n^2) Bubble/Selection/Insertion Sort.
 2. O(n log n) Merge/Heap/Random Quick Sort.
 3. Special purpose sorting algorithms: O(n) Counting Sort, Radix Sort,
 	Bucket Sort(rarely appear in programming contests).
* Searching
 1. O(n) Linear Search from index 0 to index n − 1 (avoid this in programming
    contests).
 2. O(log n) Binary Search: use lower bound in C++ STL \<algorithm\>.
 	If the input is unsorted, it is fruitful to sort it just once using an
 	O(n log n) sorting algorithm above in order to use Binary Search many times.
 3. O(1) with Hashing (but we can live without hashing for most contest
    problems).

####Static Array in C/C++
the declared array size is this value + small extra buffer.
Typical dimensions of the array are: 1-D, 2-D, 3-D, and rarely goes beyond 4-D.
Typical operations for array are: accessing certain indices, sorting the array,
linearly scanning, or binary searching the array.

####Resizeable Array a.k.a. Vector: C++ STL \<vector\>
All else the same as static array but has auto-resize feature.
Usually, we initialize
the size with some guess value for better performance. Typical operations are:
push back(), at(), [] operator, erase(), and typically use iterator to scan the
content of the vector.

####Linked List: C++ STL \<list\>
Linked List is usually avoided in typical contest problems.

####Stack: C++ STL \<stack\>
Typical operations are push()/pop() (insert/remove from top of stack), top()
(obtain content from the top of stack), empty().

####Queue: C++ STL \<queue\>
This behavior is called First In First Out (FIFO), similar to normal queue in the
real world. Typical operations are push()/pop() (insert from back/take out from
front of queue), front()/back() (obtain content from the front/back of queue),
empty().

###Non-Linear Data Structures
For some computational problems, there are better ways to organize data other
than ordering it sequentially.

####Balanced Binary Search Tree (BST): C++ STL \<map\>/\<set\>
C++ STL has \\<map\> and \<set\> which are usually the implementation of RB Tree, thus
all operations are in O(log n). Mastery of these two STL templates can save a lot
of precious coding time during contests! The difference is simple: \<map\> stores
(key → data) pair whereas \<set\> only stores the key.

####Heap: C++ STL \<queue\>: priority queue
guarantees that the top of the heap is the maximum element. There is usually no
notion of ‘search’ in Heap, but only insertion and deletion, which can be easily
done by traversing a O(log n) leaf-to-root or root-to-leaf path.

####Hash Table: no native C++ STL support (Java HashMap/HashSet/HashTable)
Hash Table is another form of non-linear data structures, but we do not recommend
using it in contests unless necessary. Reasons: designing a good performing hash
function is quite tricky and there is no native C++ STL support for it. Moreover
C++ STL \<map\> or \<set\> are usually good enough as the typical input size of
programming contest.
