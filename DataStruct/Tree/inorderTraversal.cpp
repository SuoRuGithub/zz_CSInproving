#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

class Solution_1 {
public:
    //��֮ǰһ���������ݹ�ķ���
    void getResult(TreeNode* root, vector<int>& res){
        //���ȱ�����������Ȼ����ڵ㣬Ȼ��������
        
        if(root == nullptr) return;

        getResult(root->left, res);

        res.push_back(root->val);

        getResult(root->right, res);


    }


    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        getResult(root, res);
        return res;
    }
};

class Solution_2{
public:
    //�ڶ��������ǵ���  ���˺þã������ˣ��Ҿ���ɵ�ƣ�ͷ�꣬û��
    // vector<int> inorderTraversal(TreeNode* root){
    //     TreeNode* node = root;

    //     stack<TreeNode*> s;

    //     vector<int> res;

    //     while(node->left != nullptr){
    //             s.emplace(node->left);
    //     }

    //     while(!s.empty()){
    //         while(node->left != nullptr){
    //             s.emplace(node->left);
    //         }

    //         node = s.top();
    //         s.pop();

    //         res.push_back(node->val);

    //         node = s.top();
    //         s.pop();
    //         res.push_back(node->val);

    //         node = node->right;
    //     }
    //     return res;
    // }

    vector<int> inorderTraversal(TreeNode* root){
        vector<int> res;
        stack<TreeNode*> s;
        
        while(root != nullptr || !s.empty()){   //����ѭ����������ʲô��ջ�ǿյģ�����rootҲ�ǿյģ�Ϊʲô����
            //������Ҳ�뵽�ˣ�һ·�����ߵ���β
            while(root != nullptr){ 
                s.emplace(root);
                root = root->left;
            }

            //Ϊʲô���˿��԰Ѵ���д����ô��ࣿ
            root = s.top(); //ȡջ��Ԫ�أ�Ҳ��������ĩ�˵ص�Ԫ��
            s.pop();    //��ջ
            res.push_back(root->val);   //���Res
            root = root->right; //����������û���뵽�����������������û�������Ļ����´�ѭ���ͻ���ȡһ��ջ����Ԫ�أ�Ҳ���Ƿ����˸����������������ô�����������������
            //what god damn code
        }
    }


};

int main(){



    system("pause");
    return 0;
}