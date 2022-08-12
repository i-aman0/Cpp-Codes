#include<iostream>
#include<stack>
using namespace std;

// Time complexity --> O(n) (bcoz we are traversing the string once)
// Space complexity --> O(n) (bcoz we are creating a separate stack)

bool isMatching(char ch, char topElement){
    if((ch==')' && topElement=='(') || (ch=='}' && topElement=='{') || (ch==']' && topElement=='[')){
        return true;
    }
    else{
        return false;
    }
}

bool isValidParanthesis(string str){
    int len=str.length();
    stack<char> st;

    for(int i=0;i<len;i++){
        char ch=str[i];
        
        if(ch=='(' || ch=='{' || ch=='['){
            st.push(ch);
        }
        else{
            if(!st.empty()){
                char topElement=st.top();

                bool match=isMatching(ch, topElement);
                
                if(match){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }
    if(st.empty()){
        return true;
    }
    else{
        return false;
    }
}

int main()
{
    string str="[{(){()}]()";

    bool isValid=isValidParanthesis(str);

    if(isValid){
        cout<<"The given combination of paranthesis is valid"<<endl;
    }
    else{
        cout<<"The given combination of paranthesis is invalid"<<endl;
    }

    return 0;
}