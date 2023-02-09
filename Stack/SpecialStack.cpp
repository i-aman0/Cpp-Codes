#include<iostream>
#include<stack>
using namespace std;

class MinStack{
    private:
    stack<pair<int, int>> st;

    public:
    // returns the minimum element of the stack in constant time
    int getMin(){
        return st.top().second;
    }

    // pushes the element into the stack
    void push(int num){
        if(st.empty()){
            st.push({num, num});
        }
        else{
            int top = st.top().second;
            if(top < num){
                st.push({num, top});
            }
            else{
                st.push({num, num});
            }
        }
    }

    // pops the element from the stack
    void pop(){
        if(!st.empty()){
            st.pop();
        }
    }

    // returns the top element of the stack 
    int top(){
        return st.top().first;
    }


};

int main()
{
    MinStack* minStack = new MinStack();

    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);

    cout << minStack -> top() << endl;
    cout << minStack -> getMin() << endl;

    minStack -> pop();

    cout << minStack -> top() << endl;
    cout << minStack -> getMin() << endl;

    minStack -> pop();

    cout << minStack -> top() << endl;
    cout << minStack -> getMin() << endl;

    return 0;
}