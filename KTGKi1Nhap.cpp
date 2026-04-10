#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Mon {
    string maMon;
    float diem;
};

struct Node {
    Mon data;
    Node* next;
};

struct List {
    Node* head;
    Node* tail;
};

// Khoi tao
void init(List &l) {
    l.head = l.tail = NULL;
}

// Tao node
Node* createNode(string ma, float d) {
    Node* p = new Node;
    p->data.maMon = ma;
    p->data.diem = d;
    p->next = NULL;
    return p;
}

// Them dau
void addHead(List &l, Node* p) {
    if (l.head == NULL) {
        l.head = l.tail = p;
    } else {
        p->next = l.head;
        l.head = p;
    }
}

// In danh sach
void printList(List l) {
    if (l.head == NULL) {
        cout << "Danh sach rong!\n";
        return;
    }
    for (Node* p = l.head; p != NULL; p = p->next) {
        cout << setw(10) << p->data.maMon
             << setw(10) << p->data.diem << endl;
    }
}

// Dem mon co diem thap nhat
int demso(List &l){
    if (l.head == NULL) return 0;

    float min = l.head->data.diem;
    int dem = 0;

    for (Node* i = l.head; i != NULL; i = i->next){
        if(i->data.diem < min) {
            min = i->data.diem;
        }
    }

    for (Node* i = l.head; i != NULL; i = i->next){
        if(i->data.diem == min) {
            dem++;
        }
    }

    return dem;
}

// Xoa mon diem < 5
void deleteWeak(List &l) {

    while (l.head != NULL && l.head->data.diem < 5.0) {
        Node* temp = l.head;
        l.head = l.head->next;
        delete temp;
    }

    if (l.head == NULL) {
        l.tail = NULL;
        return;
    }

    Node* p = l.head;
    while (p->next != NULL) {
        if (p->next->data.diem < 5.0) {
            Node* temp = p->next;
            p->next = temp->next;

            if (temp == l.tail)
                l.tail = p;

            delete temp;
        } else {
            p = p->next;
        }
    }
}

// Nhap danh sach
void nhapDanhSach(List &l) {
    int n;
    cout << "Nhap so mon: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        string ma;
        float diem;

        cout << "\nNhap ma mon: ";
        cin >> ma;
        cout << "Nhap diem: ";
        cin >> diem;

        addHead(l, createNode(ma, diem));
    }
}

// Menu
void menu() {
    cout << "\n===== MENU =====\n";
    cout << "1. Nhap danh sach\n";
    cout << "2. In danh sach\n";
    cout << "3. Dem mon diem thap nhat\n";
    cout << "4. Xoa mon diem < 5\n";
    cout << "0. Thoat\n";
    cout << "Chon: ";
}

// MAIN
int main() {
    List l;
    init(l);

    int chon;

    do {
        menu();
        cin >> chon;

        switch (chon) {
            case 1:
                nhapDanhSach(l);
                break;

            case 2:
                cout << "\nDanh sach:\n";
                printList(l);
                break;

            case 3:
                cout << "\nSo mon co diem thap nhat: "
                     << demso(l) << endl;
                break;

            case 4:
                deleteWeak(l);
                cout << "\nDa xoa cac mon diem < 5\n";
                break;

            case 0:
                cout << "Thoat chuong trinh!\n";
                break;

            default:
                cout << "Nhap sai!\n";
        }

    } while (chon != 0);

    return 0;
}
