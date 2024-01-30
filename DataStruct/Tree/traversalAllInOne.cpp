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

//�Ҵ����Ͽ����̳̣����ǿ�����ͳһһ�µ�����д��
//������Ҫ���С���ǡ�

vector<int> traversal(TreeNode* root){
    vector<int> res;
    stack<TreeNode*> s;
    TreeNode* node = root;

    if(root) s.push(root);  //����Ϊ�˱�֤S���ǿյģ����Խ�ѭ����
    while(!s.empty()){
        node = s.top();
        //node��ջ���Ľ�㣬������Ҫ�����ж�
        //���node����null���������Ǿ͵ð��� �� �� null �� ��˳��ѽ��ѹջ
        //Ϊʲô��������������ʹ��null����һ����ǣ�һ����������null��˵����ߵ��������ˣ����ǽ�������Ҫ���м�Ľ��
        //Ϊʲônull�������ǰ���أ���ʵ��������ͱ���˸�����һ��Ҫ�ж�����û����������Ȼ������ظ�����Ĳ�����

        if(node != nullptr){

            

            s.pop();

            //���������ǰ��� �� �� null �� ��˳���ŵ�
            //�ĳ� �� �� �� �ͱ����ǰ�� ��ǰ������򵥵ģ�������������Ҫ��null���б�ǣ�
            //�ĳ� �� null �� �� �ͱ���˺���

            if(node->right) s.push(node->right);
            
            s.push(node);

            s.push(nullptr);

            if(node->left)  s.push(node->left);
        }   
        else{
            s.pop();    //�����ս��
            node = s.top();
            res.push_back(node->val);
            s.pop();

            //Ϊʲô����������ֻ�ǰ����ó������أ�
            //��Ϊ���ҡ��ֱ���ˡ���Ĭ���С������Ĺ��¿�ʼ��
        }

        return res;
    }
}