#include <iostream>
#include <cstring>
using namespace std;


struct Ngay {
    int d, m, y;
};

struct SinhVien {
    char ma[10], ten[50];
    Ngay ns;
};

struct Node {
    SinhVien data;
    Node *next;
};


Node* taoNode(SinhVien x) {
    Node* p = new Node;
    p->data = x;
    p->next = NULL;
    return p;
}

bool trungNgay(Ngay a, Ngay b) {
    return a.d == b.d && a.m == b.m && a.y == b.y;
}

void nhapSV(SinhVien &x) {
    cin.ignore();

    cout << "Ma: ";
    cin.getline(x.ma, 10);

    cout << "Ten: ";
    cin.getline(x.ten, 50);

    cout << "Ngay sinh (d m y): ";
    cin >> x.ns.d >> x.ns.m >> x.ns.y;
}

void xuatDS(Node* head) {
    while(head) {
        cout << head->data.ma << " - "
             << head->data.ten << " - "
             << head->data.ns.d << "/"
             << head->data.ns.m << "/"
             << head->data.ns.y << endl;

        head = head->next;
    }
}


//========================== BÀI 1 ==============================
// Nhập danh sách sinh viên và thêm cuối danh sách


void themCuoi(Node* &head, SinhVien x) {
    Node* p = taoNode(x);

    if(!head) {
        head = p;
        return;
    }

    Node* q = head;
    while(q->next)
        q = q->next;

    q->next = p;
}


//========================== BÀI 2 ==============================
// Thêm sinh viên theo thứ tự mã tăng dần

void themTheoThuTu(Node* &head, SinhVien x) {
    Node* p = taoNode(x);

    if(!head || strcmp(x.ma, head->data.ma) < 0) {
        p->next = head;
        head = p;
        return;
    }

    Node* q = head;

    while(q->next &&
          strcmp(q->next->data.ma, x.ma) < 0)
    {
        q = q->next;
    }

    p->next = q->next;
    q->next = p;
}


//========================== BÀI 3 ==============================
// In sinh viên có cùng ngày sinh

void inCungNgay(Node* head, Ngay x) {
    bool found = false;

    while(head) {
        if(trungNgay(head->data.ns, x)) {
            cout << head->data.ma
                 << " - "
                 << head->data.ten << endl;

            found = true;
        }

        head = head->next;
    }

    if(!found)
        cout << "Khong tim thay!\n";
}

//========================== BÀI 4 ==============================
// Xóa sinh viên có cùng ngày sinh

void xoaTheoNgay(Node* &head, Ngay x) {

    // Xóa ở đầu danh sách
    while(head && trungNgay(head->data.ns, x)) {
        Node* t = head;
        head = head->next;
        delete t;
    }

    // Xóa các node phía sau
    Node* p = head;

    while(p && p->next) {

        if(trungNgay(p->next->data.ns, x)) {
            Node* t = p->next;
            p->next = t->next;
            delete t;
        }
        else {
            p = p->next;
        }
    }
}

//==============================================================
//============================ MAIN =============================
//==============================================================

int main() {

    Node* head = NULL;

    int n;

    cout << "Nhap so luong sinh vien: ";
    cin >> n;

    // ===== Dùng bài 1: thêm cuối =====
    for(int i = 0; i < n; i++) {
        SinhVien x;

        cout << "\nNhap sinh vien thu " << i + 1 << ":\n";
        nhapSV(x);

        themCuoi(head, x);
    }

    cout << "\nDanh sach sinh vien:\n";
    xuatDS(head);

    // ===== Dùng bài 3 =====
    Ngay x;

    cout << "\nNhap ngay can tim (d m y): ";
    cin >> x.d >> x.m >> x.y;

    cout << "\nSinh vien cung ngay sinh:\n";
    inCungNgay(head, x);

    // ===== Dùng bài 4 =====
    cout << "\nXoa sinh vien cung ngay sinh...\n";
    xoaTheoNgay(head, x);

    cout << "\nDanh sach sau khi xoa:\n";
    xuatDS(head);

    return 0;
}
