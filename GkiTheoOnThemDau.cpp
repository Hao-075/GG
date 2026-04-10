#include <iostream>
using namespace std;

// Khai báo node
struct Node {
    string maHS;
    float diem;
    Node *next;
};

// T?o node
Node* makeNode(string ma, float d){
    Node* newNode = new Node();
    newNode->maHS = ma;
    newNode->diem = d;
    newNode->next = NULL;
    return newNode;
}

// 1 + 2. Thêm di?m (THÊM Ð?U)
void pushFront(Node *&head, string ma, float d){
    Node *newNode = makeNode(ma, d);
    newNode->next = head;
    head = newNode;
}

// 3. In danh sách
void duyet(Node *head){
    while(head != NULL){
        cout << head->maHS << " - " << head->diem << endl;
        head = head->next;
    }
}

// 4. Ð?m s? môn có di?m th?p nh?t
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

// 5. Xóa các môn có di?m < 5
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

// 6. MAIN
int main(){
    Node *head = NULL;

    // T?o 5 sinh viên (thêm d?u)
    pushFront(head, "HS01", 8.5);
    pushFront(head, "HS02", 4.0);
    pushFront(head, "HS03", 6.5);
    pushFront(head, "HS04", 4.0);
    pushFront(head, "HS05", 9.0);

    cout << "Danh sach ban dau:\n";
    duyet(head);

    cout << "\nSo mon co diem thap nhat: ";
    cout << countMin(head) << endl;

    deleteLessThan5(head);

    cout << "\nDanh sach sau khi xoa diem < 5:\n";
    duyet(head);

    return 0;
}
