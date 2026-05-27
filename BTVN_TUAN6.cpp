I. Phân tích giải thuật

Mô tả:
Lưu trữ danh sách file trong thư mục bằng danh sách liên kết đơn
File được sắp xếp theo thời gian

Thực hiện các thao tác:
1. Khai báo cấu trúc
2. Thêm file (copy paste) nhưng vẫn giữ thứ tự thời gian
3. Tính tổng dung lượng
4. Chọn file để backup vào USB 32GB → xóa file nhỏ nhất nếu cần

#include <iostream>
#include <string>
using namespace std;

struct File {
    string name;
    int size;
    long time;
};
struct Node {
    File data;
    Node* next;
};
struct LinkedList {
    Node* head;
};
void init(LinkedList &list) {
    list.head = NULL;
}
void insertFile(LinkedList &list, File f) {
    Node* newNode = new Node{f, NULL};

    if (list.head == NULL || f.time < list.head->data.time) {
        newNode->next = list.head;
        list.head = newNode;
        return;
    }
    Node* cur = list.head;
    while (cur->next != NULL && cur->next->data.time < f.time) {
        cur = cur->next;
    }
    newNode->next = cur->next;
    cur->next = newNode;
}
int totalSize(LinkedList list) {
    int sum = 0;
    Node* cur = list.head;

    while (cur != NULL) {
        sum += cur->data.size;
        cur = cur->next;
    }

    return sum;
}

// tìm file nhỏ nhất
Node* findMin(LinkedList list) {
    Node* minNode = list.head;
    Node* cur = list.head;
    while (cur != NULL) {
        if (cur->data.size < minNode->data.size) {
            minNode = cur;
        }
        cur = cur->next;
    }
    return minNode;
}

// xóa node bất kỳ
void deleteNode(LinkedList &list, Node* target) {
    if (list.head == NULL) return;

    if (list.head == target) {
        Node* temp = list.head;
        list.head = list.head->next;
        delete temp;
        return;
    }

    Node* cur = list.head;
    while (cur->next != target) {
        cur = cur->next;
    }

    Node* temp = cur->next;
    cur->next = temp->next;
    delete temp;
}

// backup
void backupUSB(LinkedList &list, int capacity) {
    while (totalSize(list) > capacity) {
        Node* minNode = findMin(list);
        deleteNode(list, minNode);
    }
}
