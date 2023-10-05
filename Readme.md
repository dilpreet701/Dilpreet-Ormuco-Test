
## Question 1:
Your goal for this question is to write a program that accepts two lines (x1,x2) and (x3,x4) on the x-axis and returns whether they overlap. As an example, (1,5) and (2,6) overlaps but not (1,5) and (6,8). 
### Answer 1:
In this, approach was to sort both the lines using a comparator function by the first pair value of co-ordinate, cases where first co-ordinate was less than second co-ordinate was also taken care of, then after sorting if second line start point lies before first line ending point then it is claimed to be overlapped else if it starts at the exact same point or starts after that then it is not regarded as overlapping 

## Question 2:
The goal of this question is to write a software library that accepts 2 version string as input and returns whether one is greater than, equal, or less than the other. As an example: “1.2” is greater than “1.1”. Please provide all test cases you could think of. 
### Answer 2:
For this problem, approch was as follows:
=> compare two strings using diff substring of that string at substring was created between two particular dots "."
=> we will compare both of those substrings and if they are not equal we will return the smaller substring's respective original strinf
=> if they are equal then we will move on comparing the next version of substrings of both the strinfs
=> we are taking of trailimng zeroes as those are invalid
=> comparison of 2 substrings is done based upon the integer value equivalent to that string
=> all the version strings that are invalid are also taken care of

## Question 3:
At Ormuco, we want to optimize every bits of software we write. Your goal is to write a new library that can be integrated to the Ormuco stack. Dealing with network issues everyday, latency is our biggest problem. Thus, your challenge is to write a new Geo Distributed LRU (Least Recently Used) cache with time expiration.
### Answer 3:
For this problem, we used doubly linked list to implement the LRU Cache system
=> we basically have 4 operations
   => put data in cache
   => fetch data from cache
   => show data of cache in order
   => exit from the whole program

=> least recenty used cache is maintained at the head of the doubly linked list and will be removed if capaicty is full and new put request is there
=> if capacity of cache is full then LRU cache which is head will be removed from cache and new data will be inserted at end

=> elements in cache always remain sorted as per their accessed time in ascending order from head to tail

=> we are also using hashmap for data to store to avaoid linear seaching time in our algorithm (so for searchig data in cache we will do it in O(N))

=> for the concept of time expiry of cache we are storing the time of cache_accessed when the element was pushed or was accessed last from the cache.

=> now we know elements are in sorted order of accessed_time, we will simply find a first node which does not expire at some operation x and remove all the nodes before that as they all would have been expired

=> we are checkinga nd removing expired cache entries before every operation such as put,fetch and show

=> all the edge cases have been taken care of and handled