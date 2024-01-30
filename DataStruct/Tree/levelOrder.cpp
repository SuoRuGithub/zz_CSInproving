#include<iostream>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        //我们使用队列来完成层序遍历
        //为什么呢？队列先进先出，我们这里也是先让一层的遍历完再看下一层，而一层当中也是先让左边的遍历完然后再看右边
        vector<vector<int>> res;
        queue<TreeNode*> q;
        TreeNode* node = root;
        if(root){
            q.push(root);
            q.push(nullptr);
        }

        //迭代：
        while(!q.empty()){
            //我觉得我们这次也可以使用null标记一层的结束
            vector<int> level;
            while(q.front() != nullptr){
                node = q.front();
                q.pop();
                level.push_back(node->val);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            q.pop();
            if(!q.empty()) q.push(nullptr);

            res.push_back(level);            
        }

        return res;
        //成功！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
    }
};