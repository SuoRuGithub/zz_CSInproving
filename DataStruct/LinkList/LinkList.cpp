#include<iostream>
#include<stdlib.h>

using namespace std;

//����Ļ������������Ѿ�д�˲�֪�����ٱ��ˣ��������������㲻һ����
//�Ҵ����ð������װһ�£����ҳ���ʹ��ģ���̵��뷨

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

    //������������Ҫ��ת�б�������˵�ķ�ת��ָ���Ǹı����ӷ�ʽ�����Ǹı����ݴ洢��˳��
    //ʹ�õ�����ת��
    void Reverse_1(){
        //���ǵ��뷨��ʹ��ѭ����ÿ��ѭ���ߵ�һ��������Ǿ͸ı��������ӷ�ʽ������ָ��ǰһ����㣬������ǻᴦ��ͷ���
        //��������������У�������Ҫ��ס��һ������λ��
        
        //��������ȼٶ�����������Ԫ��
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

        //������ѧϰһ�±��˵Ĵ���
        //������벻������࣬����Ҫ�����˼����������ȫ������Ӧ������͵������������
        ListNode<T>* current = this->L->next;
        ListNode<T>* prev = NULL;   //6
        while(current != NULL){
            ListNode<T>* next = current->next;  //�˼ҵ�next��д��ѭ����ģ���˾��Բ�����ֶδ���
            current->next = prev;
            prev = current;
            current = next;
            //next = next->next;    //���һ�٣���������
        }

        L->next = prev;

    }

    void Reverse_2(ListNode<T>* p){
        //������ǻ��õݹ�ķ�����תһ������
        //�Ҿ��������鷳�ĵط�����ͷ��㣬��ĺ�˵
        if(p->next == NULL){
            L->next = p;
            return;
        }       
        Reverse_2(p->next);
        p->next->next = p;
        //�������չ�˯����
    }

    void PrintReverse(ListNode<T>* p){  //������һ����Ҫע��ĵط����ұ������this->L��Ϊȱʡ���������ⱻ֤���ǲ��еģ�L����һ����̬��Ա����˶������ķ��ʱ���ͨ��ʵ�����У��������ǻ�û��ʵ�����κεĶ��󣬱�����Ҳ����֪�����ȱʡ��������Ӧ�÷�ʲô�������ֻ������д��һ����ȡͷ���ĺ���
        //������ν�ʹ�õݹ�ķ������Ŵ�ӡ������Ȼ�����û�з�ת�ģ�
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
        //��ʵ�ϣ�����Ҳ����ʹ�õݹ�ķ������Ŵ�ӡ����
        if(p == NULL) return;
        cout << p->data << " ";
        PrintNormal(p->next);  
    }
    //�����ٿ�һ��������������������ʵ������Ψһ����������ȵݹ��ٴ�ӡ�����ȴ�ӡ�ٵݹ飡
    //����
    //��ʵ�ݹ鲢����������������ֻ�ܡ���������

};



int main(){
    {
    int len = 0;

    cout << "���������" << endl;
    cin >> len;

    LinkList<int> myList(len);

    myList.Print();

    myList.Reverse_1();
    myList.Print();
    // �ܺã�һ��ɹ���

    cout << endl;

    myList.PrintReverse(myList.GetHead()->next); // �ߺ����ɹ��ˣ�����
    myList.PrintNormal(myList.GetHead()->next);

    myList.Reverse_2(myList.GetHead()->next);
    myList.Print();


    }


    system("pause");
    return 0;    
}