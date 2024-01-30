#include<iostream>
#include<stdlib.h>
#include<stack>


using namespace std;

// //ʹ������ʵ�֣�˵��ʵ��������֮ǰ��vector������ȫ������ջ������Ҫ������
// template <typename T>
// struct vector{
// private:
//     T* start;
//     T* end;
//     int len;    //������ڴ�ĳ���
//     int size;   //�洢Ԫ�ص���Ŀ    //��ʵ˵��ʵ����end��size����һ���Ϳ�����
// public:
//     vector(){
//         this->start = nullptr;
//         this->end = nullptr;
//     }
//     vector(int len){    //����һ�����ȵ��ڴ棬���ǲ����κζ���
//         start = new T[len];
//         end = start - 1;    //����һ����ջ��endӦ����start��ǰһ��λ�ã���Ԫ�ظ���Ӧ����end - start + 1
//         this->len = len;
//     }
//     ~vector(){
//         delete[] start;
//     }

//     void push(T data){
//         if (++size <= len){
//             *(this->end + 1) = data;
//             end++;
//         }
//         else{
//             T* start_temp = new T[len + 4];
//             for(int i = 0; i < size; i++){  //��ʱsize�Ѿ���������
//                 start_temp[i] = start[i];
//             }
//             delete[] start;
//             start = start_temp;
//             end = start + size - 1;
//             this->len += 4;
//         }
//     }

//     void pop(){
//         if(this->IsEmpty()){
//             cout << "���Ǹ���ջ���������pop����" << endl;
//             return;   
//         }

//         this->end--;
//         size--;
//     }

//     void read(){
//         return *end;
//     }

//     void Print(){   //�ⲻӦ����ջ���еĹ��ܣ�ֻ�ǵ���Ϊ�˲���
//         for(int i = 0; i < size; i++){
//             cout << start[i] << " ";
//         }
//         cout << endl;
//     }

//     bool IsEmpty(){
//         if (size == 0)
//             return true;
//         else
//             return false;
//     }
// };

// //���������ǽ�Ҫʹ������ʵ��ջ�Ĳ���
// // template <typename T>
// // struct ListNode{
// //     T data;
// //     ListNode* next;
// //     ListNode* prev;
// // };

// // template <typename T>
// // struct Stack{
// // private:
// //     ListNode<T>* L; //ͷ���
// //     ListNode<T>* end;
// // public:
// //     Stack(){
// //         L = new ListNode<T>;
// //         end = L;    
// //         L->next = nullptr;
// //         L->prev = nullptr;
// //     }

// //     //ע���������ҽ������β����Ϊ"top"�����ǽ�ͷ�����Ϊջ��Ҳ����ȫ���Եģ��������Ӽ򵥣�������ʾ��
// //     void push(T data){
// //         ListNode<T>* p = new ListNode<T>;
// //         p->data = data;
// //         end->next = p;
// //         end = p;
// //         end->next = NULL;
// //     }
// //     void pop(){
// //         end = end->prev;
// //         delete end->next;
// //     }
// //     void Print(){   //ֻ��������
// //         ListNode<T>* p = L->next;
// //         cout << "Stack: ";
// //         while(p != NULL){
// //             cout << p->data << " ";
// //             p = p->next;
// //         }
// //         cout << endl;
// //     }
// // };

// //֮ǰд�ķ������鷳��������һ�ԣ�ֻ�õ�����Ϳ�����ɲ���
// template <typename T>
// struct ListNode{
//     T data;
//     ListNode* next;
// };

// template <typename T>
// struct Stack{
// private:
//     ListNode<T>* top;
// public:
//     Stack(){
//         this->top = nullptr;    //������ǲ�������һ���յ�ͷ��㣬���һ��������Ӧ����topָ��NULL
//     }

//     void push(T data){
//         ListNode<T>* temp = new ListNode<T>;
//         temp->data = data;

//         //ѹջҪ���Ĳ�����1 �´���һ����㣬������nextָ��top�� 2 ����½������µ�top
//         temp->next = top;
//         top = temp;
//     }

//     void pop(){
//         //��ջҪ���Ĳ��� 1 ����һ����Ϊtop��2 �ͷ�ԭ���Ŀռ�
//         ListNode<T>* temp = top;
//         top = top->next;
//         delete temp; 
//     }

//     ~Stack(){
//         while(top != nullptr) pop();
//     }

//     void Print(){
//         ListNode<T>* p = this->top;
//         cout << "Stack: ";
//         while(p != nullptr){
//             cout << p->data << " "; 
//             p = p->next;
//         }
//         cout << endl;
//     }
    
// };

// //��ת�ַ���
// void strReverse(char* str){
//     //��������Ĺ����Ƿ�תһ���ַ���
//     //ʵ�ֵķ�ʽ���������ǻὫ�ַ�����ÿһ���ַ����ε�ѹ��һ��ջ��Ȼ�����ǽ��Ὣ���ջ�е��ַ����ε���������ԭ�����ַ�����
//     stack<char> S;
    
//     char* temp = str;
//     while(*temp != '\0'){
//         S.push(*temp);
//         temp++;
//     }

//     temp = str;
//     while(*temp != '\0'){
//         *temp = S.top();
//         S.pop();
//         temp++;
//     }
// }

// //�������ƥ����
// void checkBalance(char* str){
//     char* temp = str;
//     stack<char> S;

//     while(*temp != '\0'){
//         if(*temp == '(' || *temp == '[' || *temp == '{'){
//             S.push(*temp);
//         }
//         else if(*temp == ')'){
//             if(!S.empty() && S.top() != '('){
//                 cout << "error" << endl;
//                 return;
//             }
//             else{
//                 S.pop();
//             }
//         }
//         else if(*temp == ']'){
//             if(!S.empty() && S.top() != '['){
//                 cout << "error" << endl;
//                 return;
//             }
//             else{
//                 S.pop();
//             }
//         }
//         else if(*temp == '}'){
//             if(!S.empty() && S.top() != '{'){
//                 cout << "error" << endl;
//                 return;
//             }
//             else{
//                 S.pop();
//             }
//         }

//         temp++;
//     }

//     if(S.empty())
//         cout << "������ƥ���" << endl;
//     else 
//         cout << "error" << endl;
// }

//��һ����׺���ʽת��Ϊһ����׺���ʽ
// void change(char* str){
//     //ע���ٶ�����Ϸ���������ֻ�мӼ��˳�
//     char postfix[50] = "";
//     stack<char> S;
//     int cnt = 0;    //��¼��׺���ʽ��λ��

//     char* temp = str;
//     while(*temp != '\0'){
//         if(*temp == '+' || *temp == '-' || *temp == '*' || *temp == '/'){
//             if(S.empty()) {
//                 S.push(*temp);
//                 temp++;
//                 continue;
//             }

//             //����ıȽ������ǽ�Ϊ�鷳�ģ��⻹ֻ�ǿ������ֲ�����������£�Ҳ��ʹ��һЩ��NB�����ݽṹ�����������Ǹ�����ʵ�������Ĺ���
//             //������temp���߼���ѹջ
//             if(*temp == '+' || *temp == '-'){
//                 //ȫ����ջ
//                 while(!S.empty()){
//                     postfix[cnt] = S.top();
//                     S.pop();
//                     cnt++;
//                 }
//                 //��ջ��֮��Ҫ����ѹջ
//                 S.push(*temp);
//             }
//             else if(*temp == '*' || *temp == '/'){
//                 if(S.top() == '+' || S.top() == '-'){
//                     S.push(*temp);
//                 }
//                 else{
//                     //ֻҪ���ǼӼ���Ҫһֱ��ջ
//                     while(S.top() != '+' && S.top() != '-'){
//                         postfix[cnt] = S.top();
//                         S.pop();
//                         cnt++;
//                     }
//                 }
//             }

//         }
//         else{
//             postfix[cnt] = *temp;
//             cnt++;
//         }

//         temp++;
//     } 
    
//     while(!S.empty()){
//         postfix[cnt] = S.top();
//         S.pop();
//         cnt++;
//     }

//     cout << "��׺���ʽ��" << endl;
//     cout << postfix << endl;
// }
// //˵ʵ������Ĵ�����ʷ

//���д�ø���һ�㣬���ҿ��Դ�������ŵ����
bool IsPrior(char op1, char op2){
    //��������жϲ�����op1�Ƿ������ڲ�����op2�������ǷǷ�����
    if(op1 == '+' || op1 == '-')    
        return false;
    else{
        if(op2 == '+' || op2 == '-')    
            return true;
        else    
            return false;
    }
}
void In2Post(char* str){
    char postfix[50] = "";
    int cnt = 0;

    char* cur = str;
    stack<char> S;

    while(*cur != '\0'){
        if(*cur == '+' || *cur == '-' || *cur == '*' || *cur == '/'){
            while(!S.empty() && S.top() != '(' && !IsPrior(*cur, S.top())){
                //����Ҫһֱ��ջ��ֱ���������������������һ�ֳ��֣�1. �ǿ�ջ��2. �����˿����ţ�3. ���������������ջ���Ĳ�����
                postfix[cnt] = S.top();
                S.pop();
                cnt++;
            }

            S.push(*cur);
        }
        else if(*cur == '('){
            S.push(*cur);
        }
        else if(*cur == ')'){
            while(S.top() != '('){
                postfix[cnt] = S.top();
                S.pop();
                cnt++;
            }
            S.pop();    //��������һ��
        }
        else{
            postfix[cnt] = *cur;
            cnt++;
        }
        cur++;
    }

    //���Ҫ���ǰ�ջ��ʣ�µĶ���������
    while(!S.empty()){
        postfix[cnt] = S.top();
        S.pop();
        cnt++;
    }
    cout << postfix << endl;
}



int main(){
    // {
    // int len = 0;
    // cout << "������Ҫ������ڴ泤��" << endl;
    // cin >> len;
    // vector<int> my_vec(len);
    // int size = 0; 
    // cout << "������Ҫ��������ݸ���" << endl;
    // cin >> size;

    // for(int i = 0; i < size; i++){
    //     int data = 0;
    //     cin >> data;
    //     my_vec.push(data);
    // }

    // my_vec.Print();

    // cout << my_vec.IsEmpty() << endl;

    // my_vec.pop();
    // }

    // {

    // int size = 0;
    // cout << "������ջ��Ԫ�ظ�����" << endl;
    // cin >> size;

    // Stack<int> my_sta;          //??????????????????????????????????????????????????????????�Ҿ��������Ǻܹ���ģ���һ����my_sta�����һ�����ž��ܲ�������
    // for(int i = 0; i < size; i++){
    //     int data = 0;
    //     cin >> data;
        
    //     my_sta.push(data);
    //     my_sta.Print();
    // }


    // }

    // char str[50] = "";
    // cout << "������һ���ַ���XD" << endl;
    // cin >> str;

    // strReverse(str);
    // cout << "��ת����ַ���: " << str << endl;


    // char str[20] = "";
    // cout << "������ֻ�����������ŵ��ַ���" << endl;
    // cin >> str;
    // checkBalance(str);

    char str[50] = "";
    cout << "������һ����׺���ʽXD" << endl;
    cin >> str;
    In2Post(str);




    system("pause");
    return 0;
}