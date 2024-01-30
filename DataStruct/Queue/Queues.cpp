#include<iostream>
#include<stdlib.h>

using namespace std;

//ʹ������ʵ��һ������
template <typename T>
struct queue_arr{
private:
    //ʹ������ʵ�֣�������ʵ���Բ���ָ����rear��front����һ����������Ե�ƫ�ƾͿ�����
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
            arr[i] = 0; //������Ϊ�˺����ӡ��ʱ��ÿ�����0��ǿճ����ĵط�
        }
    }
    bool IsEmpty(){
        if(rear == front && front == -1)
            return true;
        else
            return false;
    }
    bool IsFull(){  //��������Ǻ����ף���ô�ж���������ǲ��������أ�
        if(rear == front && front != -1 && front != 0) 
            return true;
        else
            return false;
    }

    //������Ҫ��ѭ�����飡
    void EnQueue(T data){
        //��������п��ܵ������
        //1. ���ˣ�2. �ǿձ���һ��ΪʲôҪ�ֳ������ۣ�����3. �������������Ҫʹ��ѭ�����飩
        if(IsFull()){
            return; //�����ٿ���һ��
        }
        else if(IsEmpty()){
            front++;
            rear++;
            arr[rear] = data;
        }
        else{
            //���������˵��ѭ�����飬���û��Խ�磬��ôȡģ���ı�ֵ�����Խ���ˣ���ȡģ�ͻ�������ͷ��ʼ
            rear++;
            arr[rear % len] = data;
        }
        
    }
    
    void DeQueue(){
        //ͬ����Ҫ���ж��ٿ���
        //1. �ձ����ùܣ�2. ֻ��һ��Ԫ�أ���Ϊ�ձ�3. ���������front++����
        if(IsEmpty())
            return;
        else if(front == rear)   //ע�⣬���ֻ��һ��Ԫ�صĻ���front��rear����ȵ�
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

//ʹ������ʵ��һ������

int main(){
    int len;
    cout << "�������������" << endl;
    cin >> len;

    queue_arr<int> my_queue(len);
    
    int size;
    cout << "������Ԫ�ظ���" << endl;
    cin >> size;
    for(int i = 0; i < size; i++){
        int data = 0;
        cin >> data;
        my_queue.EnQueue(data);
        my_queue.Print();
    }

    int dele;
    cout << "����Ҫɾ������Ԫ��?" << endl;
    cin >> dele;
    for(int i = 0; i < dele; i++){
        my_queue.DeQueue();
        my_queue.Print();
    }

    cout << "������Ԫ�ظ���" << endl;
    cin >> size;
    for(int i = 0; i < size; i++){
        int data = 0;
        cin >> data;
        my_queue.EnQueue(data);
        my_queue.Print();
    }

    cout << "����Ҫɾ������Ԫ��?" << endl;
    cin >> dele;
    for(int i = 0; i < dele; i++){
        my_queue.DeQueue();
        my_queue.Print();
    }
    

    system("pause");
    return 0;
}