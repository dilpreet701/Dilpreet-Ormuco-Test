
## Question 1:
Your goal for this question is to write a program that accepts two lines (x1,x2) and (x3,x4) on the x-axis and returns whether they overlap. As an example, (1,5) and (2,6) overlaps but not (1,5) and (6,8). 
### Answer 1:
In this, the points are sorted in the ascending order, i.e. if we have x1,x2 and x3,x4, if x1>x2 we will swap this. Same rule goes with x3,x4.
Now if, x1>x3 we will swap both the points. 
Further, we will check if x3 lies between x1 and x2. If so, return overlapping else return not overlapping.

## Question 2:
The goal of this question is to write a software library that accepts 2 version string as input and returns whether one is greater than, equal, or less than the other. As an example: “1.2” is greater than “1.1”. Please provide all test cases you could think of. 
### Answer 2:
A header file is created which includes the signature of the functions. It is further included in the cpp file.

The question states that we have 2 strings. So, I will run the iterator till '.' for both the strings. I will convert the string (i.e. substring from string1) to number by applying formula, n1 = n1*10 + (s[i] - '0'). Same formula, n2 for string2. 
Now if n1>n2 we will return that string 1 is greater than string 2.
else if n2>n1 will will return that string 2 is greater that string 1.
else if iterator for both the strings have reached till end, we will return that both strings are equal.

## Question 3:
At Ormuco, we want to optimize every bits of software we write. Your goal is to write a new library that can be integrated to the Ormuco stack. Dealing with network issues everyday, latency is our biggest problem. Thus, your challenge is to write a new Geo Distributed LRU (Least Recently Used) cache with time expiration.
### Answer 3:
In this, we have to implement least recently used cache. The path that I choose is that I have created a doubly linked list. I have also created a hashmap to store the reference of the node linked to the key.

Each node of DLL contains key, value and time at which that node will be created.
Each time the node is added or updated the time is set to the current time. 

I have created 3 functions i.e. put, get and print the values.

Before applying every operation, i have checked that for every node present in the DLL if "currentTime" - "time of node created" > expiration time then I will remove that node from DLL. After this, it will perform the specified operation.

For put, i will update the value if key already exists and also update the time to current time. Otherwise, add the key-value to the front of DLL with current time. If the capacity is reached, remove the least recently used i.e. delete the last node from the DLL.
For get, i have checked that if the key is present in map, then return the value. Now, this node is used recently so I have set the time to current time. Also, delete the node and add it to the front as it is the newly used cache. If the key is not present in the map, then return -1.
For print, it will simply iterate over the map and print the key-value pair.