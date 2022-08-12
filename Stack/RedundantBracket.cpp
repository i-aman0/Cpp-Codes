#include<iostream>
#include<stack>
using namespace std;

bool isRedundantBracket(string &str){
    stack<char> st;
    int strLength=str.length();

    for(int i=0;i<strLength;i++){
        char ch=str[i];

        if(ch=='(' || ch=='+' || ch=='-' || ch=='*' || ch=='/'){
            st.push(ch);
        }
        else{
            if(ch==')'){
                bool isRedundant=true;

                while(st.top()!='('){
                    char topElement=st.top();

                    if(topElement=='+' || topElement=='-' || topElement=='*' || topElement=='/'){
                        isRedundant=false;
                    }
                    st.pop();
                }
                if(isRedundant==true){
                    return true;
                }
                st.pop();
            }
        }
    } 
    return false;
}

int main()
{
    string str="((a+b)*b)";
    bool isRedundant=isRedundantBracket(str);

    if(isRedundant==true){
        cout<<"The expression contains redundant braackets"<<endl;
    }   
    else{
        cout<<"The expression does not contain redundant brackets"<<endl;
    }
    return 0;
}