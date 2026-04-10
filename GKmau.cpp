#include <iostream>
#include <string>
using namespace std;

struct Node {
    string eng;   // ti?ng Anh
    string vie;   // ti?ng Vi?t
    Node* next;
};

struct List {
    Node* left;
    Node* right;
};
void init(List &l) {
    l.left = l.right = NULL;
}
Node* createNode(string eng, string vie) {
    Node* p = new Node;
    p->eng = eng;
    p->vie = vie;
    p->next = NULL;
    return p;
}
void addTail(List &l, Node* p) {
    if (l.left == NULL) {
        l.left = l.right = p;
    } else {
        l.right->next = p;
        l.right = p;
    }
}
void printList(List l) {
    for (Node* p = l.left; p != NULL; p = p->next) {
        cout << p->eng << " - " << p->vie << endl;
    }
}
Node* findWord(List l, string x) {
    for (Node* p = l.left; p != NULL; p = p->next) {
        if (p->eng == x)
            return p;
    }
    return NULL;
}
void printToHello(List l) {
    for (Node* p = l.left; p != NULL; p = p->next) {
        cout << p->eng << " - " << p->vie << endl;
        if (p->eng == "hello")
            break;
    }
}
void deleteStartC(List &l) {
    // xóa d?u
    while (l.left != NULL && l.left->eng[0] == 'c') {
        Node* temp = l.left;
        l.left = l.left->next;
        delete temp;
    }

    Node* p = l.left;
    while (p != NULL && p->next != NULL) {
        if (p->next->eng[0] == 'c') {
            Node* temp = p->next;
            p->next = temp->next;
            delete temp;
        } else {
            p = p->next;
        }
    }
}
void sortList(List &l) {
    for (Node* i = l.left; i != NULL; i = i->next) {
        for (Node* j = i->next; j != NULL; j = j->next) {
            if (i->eng > j->eng) {
                swap(i->eng, j->eng);
                swap(i->vie, j->vie);
            }
        }
    }
}
int main() {
    List l;
    init(l);

    // T?o 10 t?
    addTail(l, createNode("hello", "xin chao"));
    addTail(l, createNode("cat", "con meo"));
    addTail(l, createNode("dog", "con cho"));
    addTail(l, createNode("apple", "qua tao"));
    addTail(l, createNode("car", "xe hoi"));
    addTail(l, createNode("book", "quyen sach"));
    addTail(l, createNode("computer", "may tinh"));
    addTail(l, createNode("pen", "cay but"));
    addTail(l, createNode("school", "truong hoc"));
    addTail(l, createNode("chair", "cai ghe"));

    // In danh sách
    cout << "Danh sach ban dau:\n";
    printList(l);

    // Tìm t?
    string x;
    cout << "\nNhap tu can tim: ";
    cin >> x;

    Node* kq = findWord(l, x);
    if (kq != NULL)
        cout << "Tim thay: " << kq->eng << " - " << kq->vie << endl;
    else
        cout << "Khong tim thay!\n";

    // In d?n hello
    cout << "\nTu dau den hello:\n";
    printToHello(l);

    // Xóa t? b?t d?u b?ng c
    deleteStartC(l);
    cout << "\nSau khi xoa cac tu bat dau bang 'c':\n";
    printList(l);

    // S?p x?p
    sortList(l);
    cout << "\nSau khi sap xep:\n";
    printList(l);

    return 0;
}
