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
    //和之前一样，先来递归的方法
    void getResult(TreeNode* root, vector<int>& res){
        //首先遍历左子树，然后根节点，然后右子树
        
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
    //第二个方法是迭代  干了好久，放弃了，我就是傻逼，头完，没治
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
        
        while(root != nullptr || !s.empty()){   //跳出循环的条件是什么？栈是空的，而且root也是空的（为什么？）
            //这里我也想到了，一路向左，走到结尾
            while(root != nullptr){ 
                s.emplace(root);
                root = root->left;
            }

            //为什么有人可以把代码写得这么简洁？
            root = s.top(); //取栈顶元素，也就是左树末端地的元素
            s.pop();    //弹栈
            res.push_back(root->val);   //存进Res
            root = root->right; //这个我是真的没有想到啊！！！！！！如果没有右树的话，下次循环就会再取一个栈顶的元素，也就是返回了根；如果有右树，那么接下来的你就明白了
            //what god damn code
        }
    }


};

int main(){



    system("pause");
    return 0;
}