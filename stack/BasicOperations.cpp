#include <iostream>
using namespace std;

class Stack{
    int size,top;
    int* stack;
    public:
    Stack(int size){
        this->size = size;
        top = -1;
        stack = new int[size];
    }
    ~Stack(){
        delete[] stack;
    }
    void push(int item){
        if(top == size - 1){
            cout<<"Stack is full!\n";
        }
        else{
            top++;
            stack[top] = item;
            cout<<item<<" "<<"has been added to the stack!\n";
        }
    }
    void pop(){
        if(top == -1){
            cout<<"Stack underflow!\n";
        }
        else{
            cout<<stack[top]<<" "<<"has been popped out of the stack\n";
            top--;
        }
    }
    
    void peek()const{
        if(top == -1){
            cout<<"Stack underflow!\n";
        }
        else{
            cout<<stack[top]<<' '<<"is the most recent item in the stack!\n";
        }
    }

    void display()const{
        if(top == -1){
            cout<<"Stack underflow!\n";
        }
        else{
            for(int i = top;i >= 0; i--){
                cout<<stack[i]<<' ';
            }
            cout<<endl;
        }
    }

    void summation(){
        if(top == -1){
            cout<<"Stack underflow!\n";
        }
        else{
            int sum{0};
            for (int i=top ; i>= 0;i--){
                sum += stack[i];
            }
            cout<<"The sum of all the elements in the stack is:"<<sum<<endl;
        }
    }

    void printAlternative(){
        if(top == -1){
            cout<<"Stack underflow!\n";
        }
        else{
            for(int i = top; i>= 0 ;i -= 2){
                cout<<stack[i]<<' ';
            }
            cout<<endl;
        }
    }

    void average(){
        if(top == -1){
            cout<<"Stack underflow!\n";
        }
        else{
            int sum{0},count{0};
            for (int i = top ; i >= 0;i--){
                sum += stack[i];
                count++;
            }
            cout<<"Average of all the elements present in the stack is:"<<(double)sum/count<<endl;
        }
    }
};
int main() {
    int s, choice, value;

    cout << "Enter the size of the stack: ";
    if(!(cin >> s )) return 0;
    Stack myStack(s);

    while (true) {
        cout << "\n--- STACK MENU ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Summation\n";
        cout << "6. Alternative Elements\n";
        cout << "7. Average\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                myStack.push(value);
                break;
            case 2:
                myStack.pop();
                break;
            case 3:
                myStack.peek();
                break;
            case 4:
                myStack.display();
                break;
            case 5:
                myStack.summation();
                break;
            case 6:
                myStack.printAlternative();
                break;
            case 7:
                myStack.average();
                break;
            case 8:
                cout << "Exiting program...\n";
                return 0; 
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}