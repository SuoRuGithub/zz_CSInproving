#include<iostream>
#include<stdlib.h>

using namespace std;

//使用数组实现一个队列
template <typename T>
struct queue_arr{
private:
    //使用数组实现，我们其实可以不用指针标记rear和front，用一个数组标记相对的偏移就可以了
    T* arr;
    int front;
    int rear;
    int len;
public:
    queue_arr(){
        arr = nullptr;
        front = rear = -1;
    }
    queue_arr(int len){
        arr = new T[len];
        this->len = len;
        front = rear = -1;

        for(int i = 0; i < len; i++){
            arr[i] = 0; //这里是为了后面打印的时候好看，用0标记空出来的地方
        }
    }
    bool IsEmpty(){
        if(rear == front && front == -1)
            return true;
        else
            return false;
    }
    bool IsFull(){  //这个倒不是很容易，怎么判断这个队列是不是满了呢？
        if(rear == front && front != -1 && front != 0) 
            return true;
        else
            return false;
    }

    //我们需要用循环数组！
    void EnQueue(T data){
        //想清楚所有可能的情况：
        //1. 满了；2. 是空表（想一想为什么要分出来讨论？）；3. 正常情况（这里要使用循环数组）
        if(IsFull()){
            return; //懒得再拷贝一遍
        }
        else if(IsEmpty()){
            front++;
            rear++;
            arr[rear] = data;
        }
        else{
            //这就是我们说的循环数组，如果没有越界，那么取模不改变值，如果越界了，那取模就会让它从头开始
            rear++;
            arr[rear % len] = data;
        }
        
    }
    
    void DeQueue(){
        //同样需要想有多少可能
        //1. 空表，不用管；2. 只有一个元素，置为空表；3. 其他情况，front++即可
        if(IsEmpty())
            return;
        else if(front == rear)   //注意，如果只有一个元素的话，front和rear是相等的
            front = rear = -1;
        else
            front++;
    }

    void Print(){
        cout << "Queue: ";
        for(int i = 0; i < len; i++){
            cout << arr[i] << " ";
        }
    }
};

//使用链表实现一个队列

int main(){
    int len;
    cout << "请输入队列容量" << endl;
    cin >> len;

    queue_arr<int> my_queue(len);
    
    int size;
    cout << "请输入元素个数" << endl;
    cin >> size;
    for(int i = 0; i < size; i++){
        int data = 0;
        cin >> data;
        my_queue.EnQueue(data);
        my_queue.Print();
    }

    int dele;
    cout << "你想要删除几个元素?" << endl;
    cin >> dele;
    for(int i = 0; i < dele; i++){
        my_queue.DeQueue();
        my_queue.Print();
    }

    cout << "请输入元素个数" << endl;
    cin >> size;
    for(int i = 0; i < size; i++){
        int data = 0;
        cin >> data;
        my_queue.EnQueue(data);
        my_queue.Print();
    }

    cout << "你想要删除几个元素?" << endl;
    cin >> dele;
    for(int i = 0; i < dele; i++){
        my_queue.DeQueue();
        my_queue.Print();
    }
    

    system("pause");
    return 0;
}