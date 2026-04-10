#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
};

node* makeNode(int x){
    node *newNode = new node();
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void duyet(node *head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int size(node *head){
    int dem = 0;
    while(head != NULL){
        dem++;
        head = head->next;
    }
    return dem;
}

void pushFront(node *&head, int x){
    node *newNode = makeNode(x);
    newNode->next = head;
    head = newNode;
}

void pushBack(node *&head, int x){
    node *newNode = makeNode(x);
    if(head == NULL){
        head = newNode;
        return;
    }
    node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void insert(node *&head, int k, int x){
    int n = size(head);
    if(k < 1 || k > n + 1) return;

    if(k == 1){
        pushFront(head, x);
        return;
    }

    node *temp = head;
    for(int i = 1; i <= k - 2; i++){
        temp = temp->next;
    }

    node *newNode = makeNode(x);
    newNode->next = temp->next;
    temp->next = newNode;
}

void popFront(node *&head){
    if(head == NULL) return;
    node *temp = head;
    head = head->next;
    delete temp;
}

void popBack(node *&head){
    if(head == NULL) return;

    if(head->next == NULL){
        delete head;
        head = NULL;
        return;
    }

    node *temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }

    node *last = temp->next;
    temp->next = NULL;
    delete last;
}

void erase(node *&head, int k){
    int n = size(head);
    if(k < 1 || k > n) return;

    if(k == 1){
        popFront(head);
        return;
    }

    node *temp = head;
    for(int i = 1; i <= k - 2; i++){
        temp = temp->next;
    }

    node *kth = temp->next;
    temp->next = kth->next;
    delete kth;
}

int main(){
    node *head = NULL;
    int choice, x, k;

    while(true){
        cout << "\n===== MENU =====\n";
        cout << "1. Them vao dau\n";
        cout << "2. Them vao cuoi\n";
        cout << "3. Them vao vi tri k\n";
        cout << "4. Xoa dau\n";
        cout << "5. Xoa cuoi\n";
        cout << "6. Xoa vi tri k\n";
        cout << "7. Duyet danh sach\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> choice;

        if(choice == 0) break;

        switch(choice){
            case 1:
                cout << "Nhap x: ";
                cin >> x;
                pushFront(head, x);
                break;
            case 2:
                cout << "Nhap x: ";
                cin >> x;
                pushBack(head, x);
                break;
            case 3:
                cout << "Nhap vi tri k: ";
                cin >> k;
                cout << "Nhap x: ";
                cin >> x;
                insert(head, k, x);
                break;
            case 4:
                popFront(head);
                break;
            case 5:
                popBack(head);
                break;
            case 6:
                cout << "Nhap vi tri k: ";
                cin >> k;
                erase(head, k);
                break;
            case 7:
                duyet(head);
                break;
            default:
                cout << "Lua chon khong hop le!\n";
        }
    }

    return 0;
}
