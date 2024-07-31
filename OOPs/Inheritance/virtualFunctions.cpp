#include <bits/stdc++.h>

#define ll long long
#define mod 1e9 + 7

using namespace std;

void v(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand((unsigned int)time(NULL));
}

using namespace std;

class Car{
    private:
    string type;

    public:
    void setType(string type){
        this -> type = type;
    }
    
    string getType(){
        return this -> type;
    }
};

class Mercedes : public Car{
    private:
    string name;

    public:
    Mercedes(){

    }

    void setName(string name){
        this -> name = name;
    }

    string getName(){
        return this -> name;
    }

    string getType(){
        return "SUV";
    }
};

int main(){
    //v();

    Mercedes car1;

    car1.setType("sedan");
    car1.setName("S-580");

    cout << "The type of " << car1.getName() << " is " << car1.getType() << endl;
    return 0;
}