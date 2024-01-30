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
    Node<T>* root;  //我承认这不太好

    BST(){
        this->root = nullptr;

    }
    
    ~BST(){;}
    
    void search(T data){
        Node<T>* temp = root;
        //跳出循环的条件：或者是找到了；或者是找到叶子了
        while(!temp->IsLeaf() && temp->data != data){
            if(data > temp->data)
                temp = temp->right;
            else if(data <= temp->data)
                temp = temp->left;
        }

        if(temp->data == data)
            cout << "找到了" << endl;
        else
            cout << "找不到了" << endl;
    }

    void insert(Node<T>*& sub_root, T data){    //我们需要传根  //注意这里传的是指针的引用
        

        if(sub_root == nullptr){
            Node<T> *new_node = new Node<T>;
            new_node->data = data;
            new_node->left = nullptr;
            new_node->right = nullptr;
            
            sub_root = new_node;
            return;
        }
        else{
            //我之前写的有点问题，问哦们按照课程说的使用递归来试试
            if(data <= sub_root->data)
                insert(sub_root->left, data);
            else if(data > sub_root->data)
                insert(sub_root->right, data);
        }
    }

    void remove(T data){
        //删除这个数据之后它的子树怎么办

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