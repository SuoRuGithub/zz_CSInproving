#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//�������
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

class Solution_1{
public:
    //��֮ǰһ���������ݹ�ķ�����˵��ʵ�����ݹ�����TM��д��ֻҪ��������
    void getResult(TreeNode* root, vector<int>& res){
        //���ȱ�����������Ȼ����ڵ㣬Ȼ��������
        
        if(root == nullptr) return;

        getResult(root->left, res);


        getResult(root->right, res);

        res.push_back(root->val);

    }


    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        getResult(root, res);
        return res;
    }
};

class Solution_2{
public:
    // vector<int> postorderTraversal(TreeNode* root){
    //     //��ʵ�����ķ���Ҳ�����Ƶģ�����������ֻ���һ�û�з�������֮��������԰���
    //     TreeNode* node = root;
    //     vector<int> res;
    //     stack<TreeNode*> s;

    //     while(!s.empty() || node != nullptr){   //��ʵ������Ҳ�𽥶��ˣ�֮����node != nullptr��Ϊ�˵�һ�ν�ѭ���ܽ�ȥ��֮��ֻҪs���ǿյģ�node = node->right�Ͳ�����nullptr;
    //         while(node != nullptr){
    //             s.emplace(node);
    //             node = node->left;             
    //         }

    //         node = s.top();
    //         s.pop();
    //         res.push_back(node->val);
            
    //         node = s.top();
    //         node = node->right;

    //     }

    //     return res;
    // }

    //����һ�β��ᣬ�����ˣ�Ҳ��������޴����˵�������
    //��ʵ�����֮ǰ���е㲻һ����Ҳ��������Ҫһ�������ڡ�ǰ�����Ķ���

    vector<int> postorderTraversal(TreeNode* root){
        TreeNode* node;
        TreeNode* prev;
        vector<int> res;
        stack<TreeNode*> s;

        while(node != nullptr || !s.empty()){
            //���ȣ����ǻ���һֱ�����ߵ�ĩ��
            //Ȼ��������Ҫ�ж����ĩ����û�������������Ҫ
            //û�У�ֱ�ӷŽ����������������Ҫע�����һֱ�������ߵ�֮ǰ�Ѿ��ߵ��ĵط�

            while(node != nullptr){
                s.emplace(node);
                node = node->left;
            }

            node = s.top();
            s.pop();

            if(node->right == nullptr || node->right == prev){          //������������Ǹ�ʲô�õģ�
                res.push_back(node->val);
                prev = node;
                node = nullptr;
            }
            else{
                s.push(node);
                node = node->right;
            }
        }

        return res;
    }



};