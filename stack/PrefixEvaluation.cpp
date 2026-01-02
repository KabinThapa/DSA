#include <iostream>
#include <stack>
#include <string>
#include <cmath> 
#include <algorithm> 

using namespace std;

int performOperation(int op1, int op2, char oper) {
    switch (oper) {
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        case '*': return op1 * op2;
        case '/': 
            if(op2 == 0) return 0; 
            return op1 / op2;
        case '^': return pow(op1, op2);
        default: return 0;
    }
}

void evaluatePrefix() {
    string exp;
    cout << "Enter prefix expression (e.g., +1*23): ";
    cin >> exp;

    stack<int> st;

    for (int i = exp.length() - 1; i >= 0; i--) {
        char ch = exp[i];

        if (isdigit(ch)) {
            st.push(ch - '0');
        } 
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            if (st.size() < 2) {
                cout << "Error: Invalid expression!" << endl;
                return;
            }
            
            int op1 = st.top(); st.pop();
            int op2 = st.top(); st.pop();

            int result = performOperation(op1, op2, ch);
            st.push(result);
        }
    }

    if (st.size() == 1) {
        cout << "Final Result: " << st.top() << endl;
    } else {
        cout << "Error: Invalid expression structure." << endl;
    }
}

int main() {
    int choice;
    while (true) {
        cout << "\n--- PREFIX CALCULATOR ---\n";
        cout << "1. Evaluate Expression\n";
        cout << "2. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                evaluatePrefix();
                break;
            case 2:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}