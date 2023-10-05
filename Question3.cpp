#include <Question3.h>
using namespace std;

Cache *head=NULL;
Cache *tail=NULL;

//pages stored in LRU Cache should be unique
// using map we will search data in cache in O(1) time
unordered_map<int,Cache*> nodesPresent;

void setHead(Cache *newHead){
    head=newHead;
}

void setTail(Cache *newTail){
    tail=newTail;
}
Cache* getHead(){
    return head;
}
Cache* getTail(){
    return tail;
}

// remove expired entries from cache before every operation
void removeExpiredCache(int expiry_time_sec){
    Cache *iterate = getHead();
    while(iterate!=NULL) {
        int current_time_sec=static_cast<int>(time(nullptr));
        if(current_time_sec-iterate->time_accessed_sec>=expiry_time_sec) {
            nodesPresent.erase(iterate->data);
        }
        else
            break;
        iterate = iterate->next;
    }
    if(iterate) { 
        setHead(iterate);
        iterate->previous=NULL;
    }
    else {
        setHead(NULL);
        setTail(NULL);
    }
}

// initialising the Cache entry with data values
Cache* intialiseCache(int data_element,int expiry_time_sec, Cache *next, Cache *previous) {
    Cache *newEntry = new Cache();
    newEntry->data=data_element;
    newEntry->next=next;
    newEntry->time_accessed_sec = static_cast<int>(time(nullptr));
    newEntry->previous=previous;
    if(previous)
        previous->next=newEntry;
    return newEntry;
}

// function to push data into cache
void add(int data_element,int expiry_time_sec,int capacity){
    
    removeExpiredCache(expiry_time_sec);
    
    if(nodesPresent.find(data_element)!=nodesPresent.end()) {
       cout<<"Error: data element is already present in LRU Cache"<<endl;
       return; }

    if(!nodesPresent.size()) {
        Cache *newEntry = intialiseCache(data_element,expiry_time_sec,NULL,NULL);
        setHead(newEntry);
        setTail(newEntry);
        nodesPresent[data_element]=newEntry;
    }
    
    else if(nodesPresent.size()<capacity){
        Cache *newEntry = intialiseCache(data_element,expiry_time_sec,NULL,getTail());
        setTail(newEntry);
        nodesPresent[data_element]=newEntry;
    }
    
    else{
        nodesPresent.erase(getHead()->data);
        setHead(getHead()->next);
        Cache *newEntry = intialiseCache(data_element,expiry_time_sec,NULL,getTail());
        setTail(newEntry);
        nodesPresent[data_element]=newEntry;
    }
}

// function to fetch data from cache
void fetch(int data_element,int expiry_time_sec){
    removeExpiredCache(expiry_time_sec);
    if(nodesPresent.find(data_element)==nodesPresent.end()) {
       cout<<"Error: data element is not present in LRU Cache"<<endl; 
       return; }
       
    cout<<"Data Value is "<<data_element<<endl;
    cout<<"Data fetched from Cache and entry was refreshed"<<endl;
         
     if(nodesPresent.size()==1){
         return;
     }
       
    Cache* data_fetch_entry = nodesPresent[data_element];
    
    if(data_fetch_entry->previous==NULL)
        setHead(data_fetch_entry->next);
    
    if(data_fetch_entry->next==NULL)
        setTail(data_fetch_entry->previous);
        
    if(data_fetch_entry->previous && data_fetch_entry->next){
        data_fetch_entry->previous->next=data_fetch_entry->next;
        data_fetch_entry->next->previous=data_fetch_entry->previous;
    }
    
    getTail()->next=data_fetch_entry;
    data_fetch_entry->previous=getTail();
    data_fetch_entry->next=NULL;
    data_fetch_entry->time_accessed_sec=static_cast<int>(time(nullptr));
    setTail(data_fetch_entry);
}

//function to print cache at any point of time
void show(int expiry_time_sec){
    
    removeExpiredCache(expiry_time_sec);
    
    if(!nodesPresent.size()) {
        cout<<"Current Cache is Empty"<<endl;
        return;
    }
    cout<<"traversing the whole cache list"<<endl;
    Cache *iterate=getHead();
    while(iterate!=NULL){
        cout<<"Current Cache data is "<<iterate->data<<endl;
        iterate=iterate->next;
    }
}

int main() {
    
    int capacity;
    cout<<"Please Enter the capacity of LRU Cache"<<endl;
    cin>>capacity;
    
    int expiry_time_sec;
    cout<<"please enter the expiration time of cache in seconds"<<endl;
    cin>>expiry_time_sec;
    
    string operation;
    
    setHead(NULL);
    setTail(NULL);
    
    while(1){
        
        string operation;
        
        cout<<"you have 4 operations to perform"<<endl;
        cout<<"type 'put' to enter data into cache"<<endl;
        cout<<"type 'fetch' to extract the data from cache"<<endl;
        cout<<"type 'show' to show the contents of the cache"<<endl;
        cout<<"type 'exit' to stop all the operations and exit"<<endl;
        
        cin>>operation;
        
        if(operation=="put")
        {
            int data_element;
            cout<<"Enter the data element you want to put"<<endl;
            cin>>data_element;
            add(data_element,expiry_time_sec,capacity); 
        }
        
        else if(operation=="fetch")
        {
            int data_element;
            cout<<"enter the data element you want to fetch"<<endl;
            cin>>data_element;
            fetch(data_element,expiry_time_sec);
        }
        
        else if(operation=="show")
        {
            show(expiry_time_sec);
        }
        
        else if(operation=="exit"){
            cout<<"terminating the code gracefully"<<endl;
            return 0;
        }
    }
	return 0;
}