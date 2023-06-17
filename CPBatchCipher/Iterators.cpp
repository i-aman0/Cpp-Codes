#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<string> solarSystem;
    solarSystem.push_back("Mercury");
    solarSystem.push_back("Venus");
    solarSystem.push_back("Earth");
    solarSystem.push_back("Mars");
    solarSystem.push_back("Jupiter");
    solarSystem.push_back("Saturn");
    solarSystem.push_back("Uranus");
    solarSystem.push_back("Neptune");

    vector<string> :: iterator milano = solarSystem.begin();
    // we can also write the above line as 
    // auto milano = solarSystem.begin();
    while(milano != solarSystem.end()){
        cout << *milano << " ";
        milano++;
    }

    cout<<endl;

    vector<string> :: reverse_iterator enterprise = solarSystem.rbegin();
    while(enterprise != solarSystem.rend()){
        cout << *enterprise << " ";
        enterprise++;
    }
    return 0;
}