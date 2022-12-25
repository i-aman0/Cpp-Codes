#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main()
{
    


    // creation 
    unordered_map<string, int> m;





    // insertion

    // 1
    pair<string, int> p1=make_pair("aman", 5);
    m.insert(p1);

    // 2
    pair<string, int> p2("khan", 2);
    m.insert(p2);

    // 3
    m["sahil"]=4;





    // searching

    cout<<m["aman"]<<endl;

    cout<<m.at("khan")<<endl;

    // cout<<m.at("unknown")<<endl; 
    // since unknown key does not exist hence key not found error will be thrown
    
    // but if we do the same thing in this way
    // cout<<m["unknown"]<<endl;
    // a new entry with key unknown will be created and its value will be set to 0



    // size 
    cout<<m.size()<<endl;



    // to check presence of a key, use the count function
    // the function returns 1 if the key is present and 0 if the key is not present 
    cout<<m.count("hello")<<endl;  // returns 0
    cout<<m.count("aman")<<endl;   // returns 1





    // traversing 

    // 1. For-each loop
    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }

    // 2. using iterator
    unordered_map<string, int> :: iterator itr = m.begin();    // this line gives an iterator named itr for unordered  map and initializes it to the beginning of the unordered map
    while(itr != m.end()){
        cout<<itr->first<<" "<<itr->second<<endl;
        itr++;
    }



    return 0;
}