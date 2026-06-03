#include <iostream>
using namespace std;

// Cấu trúc nút
struct Node {
    int data;
    Node *left;
    Node *right;
};

// Tạo nút mới
Node* createNode(int x) {
    Node* p = new Node;
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

// Thêm nút vào BST
Node* insert(Node* root, int x) {
    if (root == NULL)
        return createNode(x);
    if (x < root->data)
        root->left = insert(root->left, x);
    else if (x > root->data)
        root->right = insert(root->right, x);
    return root;
}

// Tìm kiếm trên BST
Node* searchBST(Node* root, int x) {
    if (root == NULL || root->data == x)
        return root;
    if (x < root->data)
        return searchBST(root->left, x);
    return searchBST(root->right, x);
}

int main() {
    int a[] = {2001, 2002, 2006, 2007, 2003,
               2004, 2005, 2001, 1999, 2004};
    int n = sizeof(a) / sizeof(a[0]);

    // Dựng cây BST
    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        root = insert(root, a[i]);
    }

    // Tìm kiếm năm sinh 2004
    int x = 2004;
    Node* p = searchBST(root, x);
    if (p != NULL)
        cout << "Tim thay nam sinh " << x;
    else
        cout << "Khong tim thay nam sinh " << x;
    return 0;
}
