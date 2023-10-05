#ifndef __ORMUCO_QUESTION3_H__
#define __ORMUCO_QUESTION3_H__
#include <bits/stdc++.h>

using namespace std;

struct Cache{
    int data;
    int time_accessed_sec;
    Cache* next;
    Cache* previous;
};

// function to fetch data from cache
void fetch(int data_element,int expiry_time_sec);

// function to push data into cache
void add(int data_element,int expiry_time_sec,int capacity);

//function to print cache at any point of time
void show(int expiry_time_sec);

#endif
