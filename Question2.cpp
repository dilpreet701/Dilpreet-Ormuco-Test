#include<Question2.h>
using namespace std;

// function to convert string to int for comapring
unsigned long long int convertStringToInt(string s){
    int index_after_trailing_zero;
    
    if(!s.length())
        return 0;
    
    unsigned long long int num=0;
    for(int i=0;i<s.length();i++){
        num+=pow(10,i)*(s[i]-'0');
    }
    return num;
}


// this function checks if given string provided is valid
bool checkValidity(string s1, string s2){

        for(int i=0;i<s1.length();i++){
        if(!(s1[i]=='.' || (s1[i]>=48 && s1[i]<=57))) {
           return 0;
        }
    }

    for(int i=0;i<s2.length();i++){
        if(!(s2[i]=='.' || (s2[i]>=48 && s2[i]<=57))) {
            return  0;
        } 
    }
    return 1;
}

//function to compare versions of 2 strings
// this function returns the smaller version string always
string compareVersions(string s1, string s2) {
    
     int s1_start_index=0;
     int s2_start_index=0;

     if(!checkValidity(s1,s2))
       return "Invalid Versions";
     
    while(s1_start_index != -1 && s2_start_index != -1) {

    size_t dotIndex_s1 = s1.find('.',s1_start_index);
    size_t dotIndex_s2 = s2.find('.',s2_start_index);
    
    string s1_sub_version="",s2_sub_version="";
    
    if (dotIndex_s1 != string::npos) {
        s1_sub_version = s1.substr(s1_start_index,dotIndex_s1-s1_start_index);
        s1_start_index = dotIndex_s1 + 1;
    }

    else {
        s1_sub_version = s1.substr(s1_start_index);
        s1_start_index = -1;
    }

    
    if (dotIndex_s2 != string::npos) {
        s2_sub_version = s2.substr(s2_start_index,dotIndex_s2-s2_start_index);
        s2_start_index = dotIndex_s2 + 1;
    }

    else {
        s2_sub_version = s2.substr(s2_start_index);
        s2_start_index = -1;
    }
    
    reverse(s1_sub_version.begin(),s1_sub_version.end());
    reverse(s2_sub_version.begin(),s2_sub_version.end());
    

    if(convertStringToInt(s1_sub_version)<convertStringToInt(s2_sub_version))
        return s1;

    else if(convertStringToInt(s1_sub_version)>convertStringToInt(s2_sub_version))
        return s2;

    }
    
    if((s1_start_index != -1 && s2_start_index !=-1) || (s1_start_index == -1 && s2_start_index ==-1))
     return "Versions are same";

    else if(s1_start_index != -1 && !convertStringToInt(s1.substr(s1_start_index)))
    return "Versions are same";
    
    else if(s1_start_index != -1)
    return s2;
    
    else if(s2_start_index != -1 && !convertStringToInt(s2.substr(s2_start_index)))
    return "Versions are same";

    else 
    return s1;
}

// function to test our code
void test(string actual, string expected){
    if(actual==expected)
    cout<<"Success"<<endl;
    else
    cout<<"Failed"<<endl;
}

int main() {
    
    //runninng the test cases
    // compares 2 strings and checks which one is smaller
    test(compareVersions("241.867", "241.897"),"241.867");
    test(compareVersions("041.843", "41.943"),"041.843");
    test(compareVersions("12.24", "12.24"),"Versions are same");
    test(compareVersions("256.512.0.0", "256.512.0"),"Versions are same");
    test(compareVersions("78.0098.100", "78.098.1"),"78.098.1");
    test(compareVersions("49.057.450", "49.057.45"),"49.057.45");
    test(compareVersions("-985.98", "985.98"),"Invalid Versions");
    test(compareVersions("9a5.98", "985.98"),"Invalid Versions");

    return 0;
}