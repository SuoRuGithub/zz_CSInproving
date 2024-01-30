#include<iostream>
#include<stdlib.h>
#include<stack>


using namespace std;

// //使用数组实现，说句实话，我们之前的vector不是完全包括了栈的所有要求了吗
// template <typename T>
// struct vector{
// private:
//     T* start;
//     T* end;
//     int len;    //申请的内存的长度
//     int size;   //存储元素的数目    //其实说句实话，end和size保留一个就可以了
// public:
//     vector(){
//         this->start = nullptr;
//         this->end = nullptr;
//     }
//     vector(int len){    //申请一定长度的内存，但是不放任何东西
//         start = new T[len];
//         end = start - 1;    //对于一个空栈，end应该在start的前一个位置，而元素个数应该是end - start + 1
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
//             for(int i = 0; i < size; i++){  //此时size已经自增过了
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
//             cout << "这是个空栈，不能完成pop操作" << endl;
//             return;   
//         }

//         this->end--;
//         size--;
//     }

//     void read(){
//         return *end;
//     }

//     void Print(){   //这不应该是栈该有的功能，只是单纯为了测试
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

// //接下来我们将要使用链表实现栈的操作
// // template <typename T>
// // struct ListNode{
// //     T data;
// //     ListNode* next;
// //     ListNode* prev;
// // };

// // template <typename T>
// // struct Stack{
// // private:
// //     ListNode<T>* L; //头结点
// //     ListNode<T>* end;
// // public:
// //     Stack(){
// //         L = new ListNode<T>;
// //         end = L;    
// //         L->next = nullptr;
// //         L->prev = nullptr;
// //     }

// //     //注：在这里我将链表的尾部作为"top"，但是将头结点作为栈顶也是完全可以的，甚至更加简单，不再演示。
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
// //     void Print(){   //只用作测试
// //         ListNode<T>* p = L->next;
// //         cout << "Stack: ";
// //         while(p != NULL){
// //             cout << p->data << " ";
// //             p = p->next;
// //         }
// //         cout << endl;
// //     }
// // };

// //之前写的繁琐且麻烦，再来试一试，只用单链表就可以完成操作
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
//         this->top = nullptr;    //这次我们不再设置一个空的头结点，因此一个空链表应该是top指向NULL
//     }

//     void push(T data){
//         ListNode<T>* temp = new ListNode<T>;
//         temp->data = data;

//         //压栈要做的操作：1 新创建一个结点，让它的next指向top； 2 这个新结点就是新的top
//         temp->next = top;
//         top = temp;
//     }

//     void pop(){
//         //弹栈要做的操作 1 让下一个成为top；2 释放原来的空间
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

// //反转字符串
// void strReverse(char* str){
//     //这个函数的功能是反转一个字符串
//     //实现的方式：首先我们会将字符串的每一个字符依次地压进一个栈，然后我们将会将这个栈中的字符依次弹出，存在原来的字符串里
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

// //检查括号匹配性
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
//         cout << "括号是匹配的" << endl;
//     else 
//         cout << "error" << endl;
// }

//将一个中缀表达式转化为一个后缀表达式
// void change(char* str){
//     //注：假定输入合法，操作符只有加减乘除
//     char postfix[50] = "";
//     stack<char> S;
//     int cnt = 0;    //记录后缀表达式的位置

//     char* temp = str;
//     while(*temp != '\0'){
//         if(*temp == '+' || *temp == '-' || *temp == '*' || *temp == '/'){
//             if(S.empty()) {
//                 S.push(*temp);
//                 temp++;
//                 continue;
//             }

//             //这里的比较无疑是较为麻烦的，这还只是考虑四种操作符的情况下，也许使用一些更NB的数据结构，可以让我们更简洁的实现这样的功能
//             //如果如果temp更高级才压栈
//             if(*temp == '+' || *temp == '-'){
//                 //全部弹栈
//                 while(!S.empty()){
//                     postfix[cnt] = S.top();
//                     S.pop();
//                     cnt++;
//                 }
//                 //弹栈完之后不要忘记压栈
//                 S.push(*temp);
//             }
//             else if(*temp == '*' || *temp == '/'){
//                 if(S.top() == '+' || S.top() == '-'){
//                     S.push(*temp);
//                 }
//                 else{
//                     //只要不是加减就要一直弹栈
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

//     cout << "后缀表达式：" << endl;
//     cout << postfix << endl;
// }
// //说实话，你的代码是史

//这次写得更好一点，而且可以处理带括号的情况
bool IsPrior(char op1, char op2){
    //这个函数判断操作符op1是否优先于操作符op2，不考虑非法输入
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
                //我们要一直弹栈，直到下面这三种情况的任意一种出现：1. 是空栈；2. 遇到了开括号；3. 这个操作符优先于栈顶的操作符
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
            S.pop();    //别忘了这一下
        }
        else{
            postfix[cnt] = *cur;
            cnt++;
        }
        cur++;
    }

    //最后不要忘记把栈里剩下的东西弹进来
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
    // cout << "请输入要申请的内存长度" << endl;
    // cin >> len;
    // vector<int> my_vec(len);
    // int size = 0; 
    // cout << "请输入要输入的数据个数" << endl;
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
    // cout << "请输入栈的元素个数：" << endl;
    // cin >> size;

    // Stack<int> my_sta;          //??????????????????????????????????????????????????????????我觉得这里是很诡异的，我一旦在my_sta后面加一个括号就跑不起来了
    // for(int i = 0; i < size; i++){
    //     int data = 0;
    //     cin >> data;
        
    //     my_sta.push(data);
    //     my_sta.Print();
    // }


    // }

    // char str[50] = "";
    // cout << "请输入一个字符串XD" << endl;
    // cin >> str;

    // strReverse(str);
    // cout << "反转后的字符串: " << str << endl;


    // char str[20] = "";
    // cout << "请输入只含有三种括号的字符串" << endl;
    // cin >> str;
    // checkBalance(str);

    char str[50] = "";
    cout << "请输入一个中缀表达式XD" << endl;
    cin >> str;
    In2Post(str);




    system("pause");
    return 0;
}