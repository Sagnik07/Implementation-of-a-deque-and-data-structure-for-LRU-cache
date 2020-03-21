# Implementation-of-a-deque-and-data-structure-for-LRU-cache

Problem:
Statement:​ Implementation of deque.
What is deque?
● Deque is the same as dynamic arrays with the ability to resize itself
automatically when an element is inserted or deleted, with their
storage being handled automatically by the container.
● They support insertion and Deletion from both ends in amortized
constant time.
● Inserting and erasing in the middle is linear in time.
What is expected as solution?
● The C++ standard specifies that a legal (i.e., standard-conforming)
implementation of deque must satisfy the following performance
requirements:
	● deque() - initialize a blank deque.
	● deque(n,x) - initialize a deque of length n with all values as x.
	● push_back(x) - append data x at the end.
	● pop_back() - erase data at the end.
	● push_front(x) - append data x at the beginning.
	● pop_front() - erase data at the beginning.
	● front() - returns the first element(value) in the deque.
	● back() - returns the last element(value) in the deque.
	● empty() - returns true if deque is empty else returns false.
	● size() - returns the current size of deque.
	● resize(x) - changes the size dynamically.
	● clear() - remove all elements of deque.
	● D[n] - returns the nth element of the deque.


Problem:
Statement:​ Design and implement a data structure for LRU (Least
Recently Used) cache. It should support the following operations:
○ get(key) - Get the value (will always be positive) of the key if the key
exists in the cache, otherwise return -1.
○ set(key, value) - Set or insert the value if the key is not already
present. When the cache reaches its capacity, it should invalidate the
least recently used item before inserting the new item.The LRU Cache will be initialized with an integer corresponding to its
capacity in the constructor. Capacity indicates the maximum number
of unique keys it can hold at a time.
Definition of “least recently used”: An access to an item is defined as a
get or a set operation of the item. “Least recently used” item is the one
with the oldest access time. You are free to use any data structure for
the problem.
