#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//ǰ�����
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
        // ��������ʹ�õݹ鷽����ʵ��һ��
        vector<int> vec;    //������Ž��

        //�������ǰѸ��ڵ㣨����ǿգ�����vec�У�Ȼ��������Ľ������vec���棬�ٰ������Ľ������
        //����ѭ��������Ӧ�������Ҷ��ǿ�
        
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
    //������ǻ���ʹ�õݹ�ķ��������������������ǵĴ������Ӽ��
    //����֮ǰ�Ĵ�����һ���ܴ��������������ڲ��ϵ�����vector������һ����һ�ε�ִ��׷�Ӳ���
    //�����������������⣬ֱ����һ��vector�д���������յĽ�������ǿ��Գ����Լ�����дһ�����������Դ�vector�����ã�������һ�㣩��һֱ��һ��vector�н��в���
    void getResult(TreeNode* root, vector<int>& res){
        if(root == nullptr) return;
        res.push_back(root->val);
        getResult(root->left, res);
        getResult(root->right, res);
    }

    vector<int> preorderTranversal(TreeNode* root){
        vector<int> res;

        getResult(root, res);   //��ϣ������ȥ������ĸ���res��Ȼ��ѽ������res����

        return res;
    }

    //���Ӷȷ�����

};

class Solution_3{
public:
    vector<int> preorderTraversal(TreeNode* root) {
        //������������õ����ķ������

        stack<TreeNode*> s; //��������ʹ����ջ�����ݽṹ��Ϊʲô��
        s.emplace(root);    
        vector<int> res;
        while (!s.empty()) {    //����ѭ����������sΪ�գ���ʱ�����������Ѿ����������
            //ÿ�����Ƕ���s��ȡ��һ����㣬������վʹ���res��
            const auto node = s.top();
            s.pop();
            if (node != nullptr) {
                res.emplace_back(node->val);
                
                //�����к�����˼�����ǰѸ������ݴ���res֮���Ȱ������ĸ�ѹջ��s��Ȼ��������ĸ�ѹջ��s
                //really fun
                s.emplace(node->right);
                s.emplace(node->left);
            }
        }
        return res;
    }
};

//��������������������������������������
//������һ����Ȥ�Ķ�����Morris �����������������������ʱ����ռ�ó����ռ����ǰ�����
//�������룬Ϊʲô֮ǰ���ǵĿռ临�Ӷ���O(n)����Ϊ�ݹ���ʽ�أ�������ʾ�أ���������ջ��Ŀ����ʲô�أ�Ŀ����Ϊ���������ܹ��������������֮���ҵ��ҵ������İ취
//������Ҳ̫�˷��ˣ�
//��ʵ�ϣ����ǵ�TreeNode�����������TreeNodeָ�룬����Ϊʲô�����������������е�ָ���ҵ�����ȥ�������ء���

