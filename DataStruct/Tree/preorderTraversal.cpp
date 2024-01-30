#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//前序遍历
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        // 首先我们使用递归方法来实现一下
        vector<int> vec;    //用来存放结果

        //首先我们把根节点（如果非空）放在vec中，然后把左树的结果续在vec后面，再把右树的结果续上
        //跳出循环的条件应该是左右都是空
        
        if(root != nullptr){
            vec.push_back(root->val);

            if(root->left != nullptr){
                vector<int> lvec = preorderTraversal(root->left);
                vec.insert(vec.end(), lvec.begin(), lvec.end());
            }
            if(root->right != nullptr){
                vector<int> rvec = preorderTraversal(root->right);
                vec.insert(vec.end(), rvec.begin(), rvec.end());
            }
        }
        else if(root == nullptr) return vec;
    }
};

class Solution_2{
public:
    //这次我们还是使用递归的方法来解决，但是这次我们的代码会更加简洁
    //我们之前的代码有一个很大的问题就是总是在不断的申请vector，而且一次又一次地执行追加操作
    //我们如果想解决这个问题，直接在一个vector中存放我们最终的结果，我们可以尝试自己重新写一个函数，可以传vector的引用（这样简单一点），一直在一个vector中进行操作
    void getResult(TreeNode* root, vector<int>& res){
        if(root == nullptr) return;
        res.push_back(root->val);
        getResult(root->left, res);
        getResult(root->right, res);
    }

    vector<int> preorderTranversal(TreeNode* root){
        vector<int> res;

        getResult(root, res);   //我希望传进去这个树的根和res，然后把结果存在res里面

        return res;
    }

    //复杂度分析？

};

class Solution_3{
public:
    vector<int> preorderTraversal(TreeNode* root) {
        //这次我们试着用迭代的方法完成

        stack<TreeNode*> s; //这里我们使用了栈的数据结构，为什么？
        s.emplace(root);    
        vector<int> res;
        while (!s.empty()) {    //跳出循环的条件是s为空，此时整个二叉树已经遍历完成了
            //每次我们都从s中取出一个结点，如果不空就存在res里
            const auto node = s.top();
            s.pop();
            if (node != nullptr) {
                res.emplace_back(node->val);
                
                //这两行很有意思，我们把根的数据存在res之后，先把右树的根压栈进s，然后把左树的根压栈进s
                //really fun
                s.emplace(node->right);
                s.emplace(node->left);
            }
        }
        return res;
    }
};

//！！！！！！！！！！！！！！！！！！！
//来看看一个有趣的东西：Morris 遍历，这个方法可以在线性时间里占用常数空间进行前序遍历
//我们想想，为什么之前我们的空间复杂度是O(n)？因为递归隐式地，迭代显示地，都调用了栈，目的是什么呢？目的是为了让我们能够在左树遍历完成之后找到找到右树的办法
//但这样也太浪费了！
//事实上，我们的TreeNode本身就有两个TreeNode指针，我们为什么不想着用这两个空闲的指针找到“回去的线索呢”？

