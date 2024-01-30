#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//后序遍历
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
    //和之前一样，先来递归的方法，说句实话，递归是真TM好写，只要你明白了
    void getResult(TreeNode* root, vector<int>& res){
        //首先遍历左子树，然后根节点，然后右子树
        
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
    //     //其实迭代的方法也是类似的，我相信现在只是我还没有发现它们之间的类似性罢了
    //     TreeNode* node = root;
    //     vector<int> res;
    //     stack<TreeNode*> s;

    //     while(!s.empty() || node != nullptr){   //其实现在我也逐渐懂了，之所以node != nullptr是为了第一次进循环能进去，之后，只要s不是空的，node = node->right就不会是nullptr;
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

    //我又一次不会，放弃了，也许这就是愚蠢的人的宿命吧
    //其实后序和之前的有点不一样，也许我们需要一个类似于“前驱”的东西

    vector<int> postorderTraversal(TreeNode* root){
        TreeNode* node;
        TreeNode* prev;
        vector<int> res;
        stack<TreeNode*> s;

        while(node != nullptr || !s.empty()){
            //首先，我们还是一直向左，走到末端
            //然后，我们需要判断这个末端有没有右树，这很重要
            //没有，直接放进结果，或许我们需要注意的是一直向左不能走到之前已经走到的地方

            while(node != nullptr){
                s.emplace(node);
                node = node->left;
            }

            node = s.top();
            s.pop();

            if(node->right == nullptr || node->right == prev){          //后面这个条件是干什么用的？
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