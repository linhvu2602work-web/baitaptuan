#include <iostream>
#include <cstring>
using namespace std;
struct Ngay{
    int d,m,y;
};
struct SinhVien{
    char ma[10], ten[50];
    Ngay ns;
};
struct Node{
    SinhVien data;
    Node *next;
};

//================= TẠO NODE =================
Node* taoNode(SinhVien x){
    Node* p = new Node;
    p->data = x;
    p->next = NULL;
    return p;
}

//================= NHẬP =================
void nhapSV(SinhVien &x){
    cin.ignore();
    cout<<"Ma: ";
    cin.getline(x.ma,10);
    cout<<"Ten: ";
    cin.getline(x.ten,50);
    cout<<"Ngay sinh: ";
    cin>>x.ns.d>>x.ns.m>>x.ns.y;
}

//================= THÊM CUỐI =================
void themCuoi(Node* &head, SinhVien x){
    Node* p = taoNode(x);
    if(head == NULL){
        head = p;
        return;
    }
    Node* q = head;
    while(q->next)
        q = q->next;
    q->next = p;
}

//================= THÊM THEO THỨ TỰ MÃ =================
void themTheoThuTu(Node* &head, SinhVien x){
    Node* p = taoNode(x);
    if(head == NULL || strcmp(x.ma, head->data.ma) < 0){
        p->next = head;
        head = p;
        return;
    }
    Node* q = head;
    while(q->next && strcmp(q->next->data.ma, x.ma) < 0)
        q = q->next;
    p->next = q->next;
    q->next = p;
}

//================= XUẤT =================
void xuat(Node* head){
    while(head){
        cout<<head->data.ma<<" - "
            <<head->data.ten<<" - "
            <<head->data.ns.d<<"/"
            <<head->data.ns.m<<"/"
            <<head->data.ns.y<<endl;
        head = head->next;
    }
}

//================= SO SÁNH NGÀY =================
bool trungNgay(Ngay a, Ngay b){
    return a.d==b.d && a.m==b.m && a.y==b.y;
}
//================= IN SV CÙNG NGÀY SINH =================
void inCungNgay(Node* head, Ngay x){
    bool found = false;
    while(head){
        if(trungNgay(head->data.ns,x)){
            cout<<head->data.ma
                <<" - "
                <<head->data.ten<<endl;
            found = true;
        }
        head = head->next;
    }
    if(!found)
        cout<<"Khong tim thay\n";
}

//================= XÓA SV THEO NGÀY SINH =================
void xoa(Node* &head, Ngay x){
    while(head && trungNgay(head->data.ns,x)){
        Node* t = head;
        head = head->next;
        delete t;
    }
    Node* p = head;
    while(p && p->next){
        if(trungNgay(p->next->data.ns,x)){
            Node* t = p->next;
            p->next = t->next;
            delete t;
        }
        else
            p = p->next;
    }
}

//================= MAIN =================
int main(){

    Node* head = NULL;

    int n;
    cout<<"Nhap so sinh vien: ";
    cin>>n;

    for(int i=0;i<n;i++){
        SinhVien x;

        cout<<"\nNhap sinh vien thu "<<i+1<<endl;
        nhapSV(x);
        // Chọn 1 trong 2 cách thêm:
        // themCuoi(head,x);
        themTheoThuTu(head,x);
    }
    cout<<"\nDanh sach sinh vien:\n";
    xuat(head);

    //----- TÌM SV CÙNG NGÀY SINH -----
    Ngay x;

    cout<<"\nNhap ngay can tim: ";
    cin>>x.d>>x.m>>x.y;

    cout<<"\nSinh vien cung ngay sinh:\n";
    inCungNgay(head,x);

    //----- XÓA SV CÙNG NGÀY SINH -----
    xoa(head,x);

    cout<<"\nDanh sach sau khi xoa:\n";
    xuat(head);

    return 0;
}
