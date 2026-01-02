#include<iostream>
#include<stack>
#include<string>
#include<cmath>

using namespace std;

int main(){
    stack<int> st;
    string expression;
    int operatorCount{0}, operandCount{0};
    int result;

    cout<<"Enter a postfix expression for evaluation:";
    cin>>expression;

    for(int i =0;i<expression.length();i++){
        char ch = expression[i];
        if(isdigit(ch)){
            operandCount++;
            st.push(ch - '0');
        }
        else{
            if(st.size() < 2 ){
                cout<<"Invalid Expression!\n";
            }
            else{
                int operand1 = st.top();
                st.pop();
                int operand2 = st.top();
                st.pop();

                switch (ch)
                {
                case '+':
                    result = operand2 + operand1;break;
                case '-': result = operand2 - operand1;break;
                case '*' : result = operand2 * operand1;break;
                case '/' : result = operand2 / operand1;break;
                case '^' : result = pow(operand2,operand1);
                default: cout<<"Invalid operator encountered!\n";return 0;
                }
                st.push(result);
            }
        }
    }
    if(!st.empty()){
        cout<<"Result:"<<st.top()<<endl;
        st.pop();
    }
    else{
        cout<<"No expression has been evaluated!\n";
    }
    return 0;
}

