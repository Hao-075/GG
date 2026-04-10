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

void init(List &l) {
    l.head = l.tail = NULL;
}

// Tao node moi
Node* createNode(string ma, float d) {
    Node* p = new Node;
    p->data.maMon = ma;
    p->data.diem = d;
    p->next = NULL;
    return p;
}

// 2. them dau ds
void addHead(List &l, Node* p) {
    if (l.head == NULL) {
        l.head = l.tail = p;
    } else {
        p->next = l.head;
        l.head = p;
    }
}

// 3. In Diem
void printList(List l) {
    for (Node* p = l.head; p != NULL; p = p->next) {
        cout << setw(10) << p->data.maMon
             << setw(10) << p->data.diem<<endl;
    }
}


//4.dem
int demso(List &l){
    float min=10;
    int dem=0;
    for (Node* i = l.head; i != NULL; i = i->next){
        if(min>i->data.diem) {
			min=i->data.diem;}
	}
    for (Node* i = l.head; i != NULL; i = i->next){
        if(min==i->data.diem) {
			dem++;}
	}

    return dem;
}
//5.xoa
void deleteWeak(List &l) {
  
    while (l.head != NULL && l.head->data.diem < 5.0) {
        Node* temp = l.head;
        l.head = l.head->next;
        delete temp;
    }
    if (l.head == NULL) { l.tail = NULL; return; }
    Node* p = l.head;
    while (p->next != NULL) {
        if (p->next->data.diem < 5.0) {
            Node* temp = p->next;
            p->next = temp->next;
            if (temp == l.tail) l.tail = p; 
            delete temp;
        } else {
            p = p->next;
        }
    }
}
int main() {
    List l;
    init(l);

    // Them mau
    addHead(l, createNode("01", 7.0));
    addHead(l, createNode("02",  3.0));
    addHead(l, createNode("03",  9.0));
    addHead(l, createNode("04", 3.0));
    addHead(l, createNode("05", 9.5));

    cout << "Danh sach vua nhap :\n";
    printList(l);
    cout<<"co "<<demso(l)<<" mon diem thap nhat"<<endl;
    cout<<"danh sach sau khi xoa mon co diem < 5"<< endl;
    deleteWeak(l);
    printList(l);

    return 0;
}
