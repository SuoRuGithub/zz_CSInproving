#include<iostream>
#include<stdlib.h>

using namespace std;

template <typename T>
struct Node{
    T data;
    Node* left;
    Node* right;
    
    bool IsLeaf(){
        if(left == nullptr && right == nullptr) return true;
        else return false;
    }
};

template <typename T>
struct BST{
public:
    Node<T>* root;  //�ҳ����ⲻ̫��

    BST(){
        this->root = nullptr;

    }
    
    ~BST(){;}
    
    void search(T data){
        Node<T>* temp = root;
        //����ѭ�����������������ҵ��ˣ��������ҵ�Ҷ����
        while(!temp->IsLeaf() && temp->data != data){
            if(data > temp->data)
                temp = temp->right;
            else if(data <= temp->data)
                temp = temp->left;
        }

        if(temp->data == data)
            cout << "�ҵ���" << endl;
        else
            cout << "�Ҳ�����" << endl;
    }

    void insert(Node<T>*& sub_root, T data){    //������Ҫ����  //ע�����ﴫ����ָ�������
        

        if(sub_root == nullptr){
            Node<T> *new_node = new Node<T>;
            new_node->data = data;
            new_node->left = nullptr;
            new_node->right = nullptr;
            
            sub_root = new_node;
            return;
        }
        else{
            //��֮ǰд���е����⣬��Ŷ�ǰ��տγ�˵��ʹ�õݹ�������
            if(data <= sub_root->data)
                insert(sub_root->left, data);
            else if(data > sub_root->data)
                insert(sub_root->right, data);
        }
    }

    void remove(T data){
        //ɾ���������֮������������ô��

    }
};





int main(){
    BST<int> my_tree;
    my_tree.insert(my_tree.root, 15);
    my_tree.insert(my_tree.root, 12);
    my_tree.insert(my_tree.root, 20);

    my_tree.search(15);

    system("pause");
    return 0;
}