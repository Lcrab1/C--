#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *buildTree(const std::vector<int> &values)
{
    if (values.empty())
        return nullptr;

    TreeNode *root = new TreeNode(values[0]);
    std::queue<TreeNode *> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < values.size())
    {
        TreeNode *current = q.front();
        q.pop();

        if (values[i] != NULL)
        {
            current->left = new TreeNode(values[i]);
            q.push(current->left);
        }
        i++;

        if (i < values.size() && values[i] != NULL)
        {
            current->right = new TreeNode(values[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

unordered_map<TreeNode *, TreeNode *> ancestor;
unordered_map<TreeNode *, int> depthMap;
TreeNode *m_p = nullptr;
TreeNode *m_q = nullptr;

void dfs(TreeNode *anc, TreeNode *child, int depth)
{
    if (child == nullptr)
        return;
    ancestor[child] = anc;
    depthMap[child] = depth;
    dfs(child, child->left, depth + 1);
    dfs(child, child->right, depth + 1);
}
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    m_p = p;
    m_q = q;
    dfs(nullptr, root, 0);
    int pd = depthMap[p];
    int qd = depthMap[q];
    if (pd > qd)
    {
        while (pd != qd)
        {
            p = ancestor[p];
            pd--;
        }
    }
    else if (pd < qd)
    {
        while (qd != pd)
        {
            q = ancestor[q];
            qd--;
        }
    }
    while (p != q)
    {
        p = ancestor[p];
        q = ancestor[q];
    }
    return p;
}

int main()
{
    std::vector<int> values = {3, 5, 1, 6, 2, 0, 8, NULL, NULL, 7, 4, NULL, NULL};
    TreeNode *root = buildTree(values);
    TreeNode *p = root->left;
    TreeNode *q = root->left->right->right;
    TreeNode *res = lowestCommonAncestor(root, p, q);
    system("pause");
}