#include <bits/stdc++.h>
using namespace std;

// sorting 2 pairs using comparator
bool cmp(pair<double,double> firstCo, pair<double,double> secondCo){
    return firstCo.first<=secondCo.first;
}

//function to check string overlapping
bool checkOverlap(pair<double,double> firstCo, pair<double,double> secondCo){

    vector<pair<double,double>> v;

    if(firstCo.first>firstCo.second)
    swap(firstCo.first,firstCo.second);

    if(secondCo.first>secondCo.second)
    swap(secondCo.first,secondCo.second);

    v.push_back(firstCo);
    v.push_back(secondCo);
        
    sort(v.begin(),v.end(),cmp);
    
    if(v[0].second>v[1].first)
      return 1;
    return 0;
} 

void testing(bool actual, bool expected){
    if(actual == expected)
        cout << "Success"<<endl;
    else
        cout << "Failure"<<endl;
}

int main() {
    
    pair<double, double> firstCo;
    pair<double, double> secondCo;
    cout<<" please enter first line both x co-ordinates"<<endl;
    cin>> firstCo.first >> firstCo.second;
        cout<<" please enter second line both x co-ordinates"<<endl;
    cin>> secondCo.first >> secondCo.second;
    
    bool ans = checkOverlap(make_pair(firstCo.first,firstCo.second), make_pair(secondCo.first,secondCo.second));
    if(ans)
       cout<<"Lines overlap"<<endl;
    else
       cout<<"Lines do not overlap"<<endl; 
       
    cout<<"now running other test Cases"<<endl;
    
    // these are basic test cases
    testing(checkOverlap(make_pair(6,12),make_pair(16,17)),0);
    testing(checkOverlap(make_pair(1,15),make_pair(14,17)),1);
    
    // swapped value of co-ordinates
    testing(checkOverlap(make_pair(12,6),make_pair(5,2)),0);
    
    // if one line completly contains other line
    testing(checkOverlap(make_pair(5,15),make_pair(8,12)),1);
    
    // lines with negative co-ordinates
    testing(checkOverlap(make_pair(-11,-14),make_pair(-17,-8)),1);
    
    //line starting from where first line ends is not considered as overlap
    testing(checkOverlap(make_pair(11,18),make_pair(18,25)),0);
    
    return 0;
}