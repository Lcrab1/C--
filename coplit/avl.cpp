#include <iostream>
using namespace std;
// AVL树节点
struct Node {
    int key;
    int height;
    Node* left;
    Node* right;

    Node(int k) : key(k), height(1), left(nullptr), right(nullptr) {}
};

// 获取节点的高度
int getHeight(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

// 获取节点的平衡因子
int getBalanceFactor(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

// 更新节点的高度
void updateHeight(Node* node) {
    node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
}

// 右旋操作
Node* rotateRight(Node* node) {
    Node* newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;
    updateHeight(node);
    updateHeight(newRoot);
    return newRoot;
}

// 左旋操作
Node* rotateLeft(Node* node) {
    Node* newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = node;
    updateHeight(node);
    updateHeight(newRoot);
    return newRoot;
}

// 插入节点
Node* insertNode(Node* root, int key) {
    if (root == nullptr) {
        return new Node(key);
    }
    if (key < root->key) {
        root->left = insertNode(root->left, key);
    } else if (key > root->key) {
        root->right = insertNode(root->right, key);
    } else {
        return root; // 重复的节点，不进行插入
    }

    updateHeight(root);

    int balanceFactor = getBalanceFactor(root);

    // 左子树高度大于右子树
    if (balanceFactor > 1) {
        // 左子树的左子树高度大于等于左子树的右子树高度，进行右旋操作
        if (key < root->left->key) {
            return rotateRight(root);
        }
        // 左子树的右子树高度大于左子树的左子树高度，先进行左旋操作，再进行右旋操作
        else if (key > root->left->key) {
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }
    }

    // 右子树高度大于左子树
    if (balanceFactor < -1) {
        // 右子树的右子树高度大于等于右子树的左子树高度，进行左旋操作
        if (key > root->right->key) {
            return rotateLeft(root);
        }
        // 右子树的左子树高度大于右子树的右子树高度，先进行右旋操作，再进行左旋操作
        else if (key < root->right->key) {
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }
    }

    return root;
}

// 中序遍历
void inorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->key << " ";
    inorderTraversal(root->right);
}
 

int main() {
    Node* root = nullptr;

    // 插入节点
    root = insertNode(root, 21);
    root = insertNode(root, 12);
    root = insertNode(root, 34);
    root = insertNode(root, 65);
    root = insertNode(root, 10);
    root = insertNode(root, 12);
    root = insertNode(root, 8);
    root = insertNode(root, 6);
    // 中序遍历
    cout << "中序遍历: ";
    inorderTraversal(root);
    cout << endl;
    system("pause");
    return 0;
}
