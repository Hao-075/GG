#include <iostream>
using namespace std;

struct Node {
    string maHS;
    float diem;
    Node *next;
};
Node* makeNode(string ma, float d){
    Node* newNode = new Node();
    newNode->maHS = ma;
    newNode->diem = d;
    newNode->next = NULL;
    return newNode;
}
void pushBack(Node *&head, string ma, float d){
    Node *newNode = makeNode(ma, d);

    if(head == NULL){
        head = newNode;
        return;
    }

    Node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}
void deleteByMa(Node *&head, string ma){
    if(head == NULL) return;

    // xóa d?u
    if(head->maHS == ma){
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node *temp = head;
    while(temp->next != NULL && temp->next->maHS != ma){
        temp = temp->next;
    }

    if(temp->next != NULL){
        Node *del = temp->next;
        temp->next = del->next;
        delete del;
    }
}
void pushFront(Node *&head, string ma, float d){
    Node *newNode = makeNode(ma, d);
    newNode->next = head;
    head = newNode;
}
void duyet(Node *head){
    while(head != NULL){
        cout << head->maHS << " - " << head->diem << endl;
        head = head->next;
    }
}
int countMin(Node *head){
    if(head == NULL) return 0;

    float minDiem = head->diem;
    Node *temp = head;

    // tìm min
    while(temp != NULL){
        if(temp->diem < minDiem){
            minDiem = temp->diem;
        }
        temp = temp->next;
    }

    // d?m
    int dem = 0;
    temp = head;
    while(temp != NULL){
        if(temp->diem == minDiem){
            dem++;
        }
        temp = temp->next;
    }

    return dem;
}
void deleteLessThan5(Node *&head){
    // xóa d?u
    while(head != NULL && head->diem < 5){
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    Node *temp = head;
    while(temp != NULL && temp->next != NULL){
        if(temp->next->diem < 5){
            Node *del = temp->next;
            temp->next = del->next;
            delete del;
        } else {
            temp = temp->next;
        }
    }
}
int main(){
    Node *head = NULL;

    // T?o danh sách 5 sinh viên
    pushBack(head, "HS01", 8.5);
    pushBack(head, "HS02", 4.0);
    pushBack(head, "HS03", 6.5);
    pushBack(head, "HS04", 4.0);
    pushBack(head, "HS05", 9.0);

    cout << "Danh sach ban dau:\n";
    duyet(head);

    cout << "\nSo mon co diem thap nhat: ";
    cout << countMin(head) << endl;

    deleteLessThan5(head);

    cout << "\nDanh sach sau khi xoa diem < 5:\n";
    duyet(head);

    return 0;
}
