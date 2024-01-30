#include<iostream>
#include<stdlib.h>

using namespace std;

//链表的基本操作我们已经写了不知道多少遍了，今天我们来整点不一样的
//我打算用把链表封装一下，并且尝试使用模板编程的想法

template <typename T>
struct ListNode{
    T data;
    ListNode* next;
};

template <typename T>
struct LinkList{
private:
    ListNode<T>* L; //all we need is head node, actually
    int len;
public:
    ListNode<T>* GetHead(){
        return this->L;
    }

    LinkList(){
        this->L = new ListNode<T>;
        L->next = NULL;
    }

    LinkList(int num): LinkList() {
        //LinkList();
        
        this->len = num;
        ListNode<T>* Tail = L;
        for(int i = 0; i < num; i++){
            ListNode<T>* p = new ListNode<T>;
            cin >> p->data;
            Tail->next = p;
            Tail = p;
        }
        Tail->next = NULL;
    }

    // ~LinkList(){
    //     ListNode<T>* p = this->L;
    //     while(p != NULL){
    //         delete L;
    //         L = p;
    //         p = p->next;
    //     }
    //     delete L;

    //     L = NULL;
    // } 

    void Print(){
        ListNode<T>* p = L->next;
        for(int i = 0; i < len; p = p->next, i++){
            cout << p->data << " ";
        }
        cout << endl;
    }

    //接下来，我们要反转列表。我们所说的反转，指的是改变链接方式而不是改变数据存储的顺序
    //使用迭代反转：
    void Reverse_1(){
        //我们的想法是使用循环，每次循环走到一个结点我们就改变它的链接方式，让它指向前一个结点，最后我们会处理头结点
        //但是在这个过程中，我们需要记住上一个结点的位置
        
        //在这里，我先假定至少有三个元素
        // ListNode<T>* nex = L->next->next->next;
        // ListNode<T>* pres = L->next->next;
        // ListNode<T>* prev = L->next;
        // prev->next = NULL;
        // while(nex != NULL){
        //     pres->next = prev;

        //     prev = pres;
        //     pres = nex;
        //     nex = nex->next;
        // }

        // pres->next = prev;
        // L->next = pres;

        //我再来学习一下别人的代码
        //这个代码不仅仅简洁，更重要的是人家这个代码完全可以适应空链表和单结点链表的情况
        ListNode<T>* current = this->L->next;
        ListNode<T>* prev = NULL;   //6
        while(current != NULL){
            ListNode<T>* next = current->next;  //人家的next是写在循环里的，因此绝对不会出现段错误
            current->next = prev;
            prev = current;
            current = next;
            //next = next->next;    //多此一举，反而错了
        }

        L->next = prev;

    }

    void Reverse_2(ListNode<T>* p){
        //这次我们会用递归的方法反转一个链表
        //我觉得真正麻烦的地方在于头结点，别的好说
        if(p->next == NULL){
            L->next = p;
            return;
        }       
        Reverse_2(p->next);
        p->next->next = p;
        //完美，收工睡觉！
    }

    void PrintReverse(ListNode<T>* p){  //这里是一个需要注意的地方，我本来想把this->L作为缺省参数，但这被证明是不行的，L不是一个静态成员，因此对于它的访问必须通过实例进行，这里我们还没有实例化任何的对象，编译器也不能知道这个缺省参数到底应该放什么。最后，我只能重新写了一个获取头结点的函数
        //我们这次将使用递归的方法反着打印链表（当然结点是没有反转的）
        // ListNode<T>* q = p->next;
        // if(q != NULL){
        //     PrintReverse(q);
        // }

        // cout << p->data << " ";

        if(p == NULL) return;
        PrintReverse(p->next);
        cout << p->data << " ";
    }
    void PrintNormal(ListNode<T>* p){
        //事实上，我们也可以使用递归的方法正着打印链表
        if(p == NULL) return;
        cout << p->data << " ";
        PrintNormal(p->next);  
    }
    //请你再看一看上面这两个函数！事实上它们唯一的区别就是先递归再打印还是先打印再递归！
    //很妙
    //其实递归并不是像你理解的那样只能“反着来”

};



int main(){
    {
    int len = 0;

    cout << "请输入个数" << endl;
    cin >> len;

    LinkList<int> myList(len);

    myList.Print();

    myList.Reverse_1();
    myList.Print();
    // 很好！一遍成功！

    cout << endl;

    myList.PrintReverse(myList.GetHead()->next); // 芜湖！成功了！！！
    myList.PrintNormal(myList.GetHead()->next);

    myList.Reverse_2(myList.GetHead()->next);
    myList.Print();


    }


    system("pause");
    return 0;    
}