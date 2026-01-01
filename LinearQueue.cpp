#include<iostream>
using namespace std;
#define MAX 100

class LinearQueue{
    private:
        int* LQ;
        int front,rear,size;

    public:

        LinearQueue(int size){
            this->size = size;
            LQ = new int[size];
            front = -1;
            rear = -1;
        }
        void enqueue(int item){
            if(rear == size-1){
                cout<<"Queue overflowed!\n";
            }
            else if(front == -1){
                front = 0;
            }
            else{
                rear++;
                LQ[rear] = item;
                cout<<item<<" has been enqueued to the queue!\n";
            }
        }
        
        void dequeue(){
            if(front == -1 || front > rear){
                cout<<"Queue underflow!\n";
            }
            else{
                cout<<LQ[front]<<" has been deueued from the queue!\n";
                front++;
            }
            if(front>rear){
                front = rear = -1;
            }
        }

        void display()const{
            if(front == -1 || front > rear){
                cout<<"Queue underflow!\n";
                return;
            }
            cout<<"The items in the queue are:\n";
            for(int i = front ; i<=rear ; i++){
                cout<<LQ[i]<<" ";
            }
            cout<<endl;
        }

        void summation(){
            if(front == -1 || front > rear){
                cout<<"Queue underflow!\n";
                return;
            }
            int sum{0};
            for(int i = front;i<=rear;i++){
                sum += LQ[i];
            }
            cout<<"The sum of all the elements in the queue is:"<<sum<<endl;
        }
};

int main(){
    int size,choice,item;
    cout<<"Enter the size of the queue:";
    cin>>size;

    LinearQueue q(size);

    while(true){
        cout<<"Menu option\n";
        cout<<"1. Enqueue\n2. Dequeue\n3. Display\n4.Summation\n5. Exit";
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"Enter an item to enqueue:";
                cin>>item;
                q.enqueue(item);
                break;

            case 2: 
                q.dequeue();
                break;
            
            case 3:
                q.display();
                break;;
            
            case 4:
                q.summation();
                break;
            
            case 5:
                cout<<"Exiting....";
                return 0;
            
            default:
                cout<<"Please enter a valid input and try again later!\n";
        }
    }
}