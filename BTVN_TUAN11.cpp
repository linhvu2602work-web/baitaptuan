#include <iostream>
using namespace std;
struct Node {
    char data;
    Node* left;
    Node* right;
};
Node* taoNode(char x) {
    Node* p = new Node;
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}
Node* cayDayDu() {
    Node* A = taoNode('A');
    Node* B = taoNode('B');
    Node* C = taoNode('C');
    Node* D = taoNode('D');
    Node* E = taoNode('E');
    Node* F = taoNode('F');
    Node* G = taoNode('G');
    A->left = B;
    A->right = C;
    B->left = D;
    B->right = E;
    C->left = F;
    C->right = G;
    return A;
} 
Node* cayLechTrai() {
    Node* A = taoNode('A');
    Node* B = taoNode('B');
    Node* C = taoNode('C');
    Node* D = taoNode('D');
    A->left = B;
    B->left = C;
    C->left = D;
    return A;
}
Node* cayLechPhai() {
    Node* A = taoNode('A');
    Node* B = taoNode('B');
    Node* C = taoNode('C');
    Node* D = taoNode('D');
    A->right = B;
    B->right = C;
    C->right = D;
    return A;
}
Node* cayZigZag() {
    Node* A = taoNode('A');
    Node* B = taoNode('B');
    Node* C = taoNode('C');
    Node* D = taoNode('D');
    A->left = B;
    B->right = C;
    C->left = D;
    return A;
}
Node* cayBieuThuc() {
    Node* chia = taoNode('/');
    Node* cong = taoNode('+');
    Node* d = taoNode('d');

    Node* nhan = taoNode('*');
    Node* c = taoNode('c');

    Node* a = taoNode('a');
    Node* b = taoNode('b');

    chia->left = cong;
    chia->right = d;

    cong->left = nhan;
    cong->right = c;

    nhan->left = a;
    nhan->right = b;

    return chia;
}
void duyetTruoc(Node* root) {
    if(root != NULL) {
        cout << root->data << " ";
        duyetTruoc(root->left);
        duyetTruoc(root->right);
    }
}
void duyetGiua(Node* root) {
    if(root != NULL) {
        duyetGiua(root->left);
        cout << root->data << " ";
        duyetGiua(root->right);
    }
}
void duyetSau(Node* root) {
    if(root != NULL) {
        duyetSau(root->left);
        duyetSau(root->right);
        cout << root->data << " ";
    }
}
void truoc(Node* root) {
    if(root != NULL) {
        cout << root->data;
        truoc(root->left);
        truoc(root->right);
    }
}
void giua(Node* root) {
    if(root != NULL) {
        if(root->left != NULL)
            cout << "(";
        giua(root->left);
        cout << root->data;
        giua(root->right);
        if(root->right != NULL)
            cout << ")";
    }
}
void sau(Node* root) {
    if(root != NULL) {
        sau(root->left);
        sau(root->right);
        cout << root->data;
    }
}
int main() {
    // CAY DAY DU
    cout << "CAY DAY DU\n";
    Node* daydu = cayDayDu();
    cout << "Duyet truoc : ";
    duyetTruoc(daydu);
    cout << "\nDuyet giua  : ";
    duyetGiua(daydu);
    cout << "\nDuyet sau   : ";
    duyetSau(daydu);
    cout << "\n\n";
   
    // CAY LECH TRAI
    cout << "CAY LECH TRAI\n";
    Node* trai = cayLechTrai();
    cout << "Duyet truoc : ";
    duyetTruoc(trai);
    cout << "\nDuyet giua  : ";
    duyetGiua(trai);
    cout << "\nDuyet sau   : ";
    duyetSau(trai);
    cout << "\n\n";
    
    // CAY LECH PHAI
    cout << "CAY LECH PHAI\n";
    Node* phai = cayLechPhai();
    cout << "Duyet truoc : ";
    duyetTruoc(phai);
    cout << "\nDuyet giua  : ";
    duyetGiua(phai);
    cout << "\nDuyet sau   : ";
    duyetSau(phai);
    cout << "\n\n";
    
    // CAY ZIGZAG
    
    cout << "CAY ZIGZAc\n";
    Node* zigzag = cayZigZag();
    cout << "Duyet truoc : ";
    duyetTruoc(zigzag);
    cout << "\nDuyet giua  : ";
    duyetGiua(zigzag);
    cout << "\nDuyet sau   : ";
    duyetSau(zigzag);
    cout << "\n\n";
    
    // CAY BIEU THUC
    cout << "CAY BIEU THUC\n";
    Node* bt = cayBieuThuc();
    cout << "Tien to : ";
    truoc(bt);
    cout << "\nTrung to  : ";
    giua(bt);
    cout << "\nHau to : ";
    sau(bt);
    cout << "\n";
    return 0;
}
