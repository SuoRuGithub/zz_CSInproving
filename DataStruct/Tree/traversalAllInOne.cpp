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

//我从网上看来教程，我们可以来统一一下迭代的写法
//我们需要进行“标记”

vector<int> traversal(TreeNode* root){
    vector<int> res;
    stack<TreeNode*> s;
    TreeNode* node = root;

    if(root) s.push(root);  //这是为了保证S不是空的，可以进循环体
    while(!s.empty()){
        node = s.top();
        //node是栈顶的结点，我们需要进行判断
        //如果node不是null，那们我们就得按照 右 根 null 左 的顺序把结点压栈
        //为什么？在这里我们是使用null做了一个标记，一旦我们碰到null就说明左边的树放完了，我们接下来需要放中间的结点
        //为什么null又在左的前面呢？其实接下来左就变成了根，下一步要判断它有没有右子树，然后就是重复上面的步骤了

        if(node != nullptr){

            

            s.pop();

            //这里我们是按照 右 中 null 左 的顺序存放的
            //改成 中 左 右 就变成了前序 （前序是最简单的，我们甚至不需要用null进行标记）
            //改成 中 null 右 左 就变成了后序

            if(node->right) s.push(node->right);
            
            s.push(node);

            s.push(nullptr);

            if(node->left)  s.push(node->left);
        }   
        else{
            s.pop();    //弹出空结点
            node = s.top();
            res.push_back(node->val);
            s.pop();

            //为什么我们在这里只是把中拿出来了呢？
            //因为“右”又变成了“幽默老中”，它的故事开始了
        }

        return res;
    }
}