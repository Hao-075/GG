#include <iostream>
using namespace std;

struct Node {
    string maHS;
    float diem;
    Node *next;
};

// ===== TẠO NODE =====
Node* makeNode(string ma, float d){
    Node* newNode = new Node();
    newNode->maHS = ma;
    newNode->diem = d;
    newNode->next = NULL;
    return newNode;
}

// ===== THÊM =====

// Thêm đầu (DÙNG CHÍNH)
void pushFront(Node *&head, string ma, float d){
    Node *newNode = makeNode(ma, d);
    newNode->next = head;
    head = newNode;
}

// Thêm cuối
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

// Thêm giữa (vị trí k)
void insert(Node *&head, int k, string ma, float d){
    int n = 0;
    Node *tmp = head;
    while(tmp != NULL){
        n++;
        tmp = tmp->next;
    }

    if(k < 1 || k > n + 1) return;

    if(k == 1){
        pushFront(head, ma, d);
        return;
    }

    Node *temp = head;
    for(int i = 1; i <= k - 2; i++){
        temp = temp->next;
    }

    Node *newNode = makeNode(ma, d);
    newNode->next = temp->next;
    temp->next = newNode;
}

// ===== XÓA =====

// Xóa đầu
void popFront(Node *&head){
    if(head == NULL) return;
    Node *temp = head;
    head = head->next;
    delete temp;
}

// Xóa cuối
void popBack(Node *&head){
    if(head == NULL) return;

    if(head->next == NULL){
        delete head;
        head = NULL;
        return;
    }

    Node *temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }

    Node *last = temp->next;
    temp->next = NULL;
    delete last;
}

// Xóa giữa (vị trí k)
void erase(Node *&head, int k){
    if(head == NULL) return;

    int n = 0;
    Node *tmp = head;
    while(tmp != NULL){
        n++;
        tmp = tmp->next;
    }

    if(k < 1 || k > n) return;

    if(k == 1){
        popFront(head);
        return;
    }

    Node *temp = head;
    for(int i = 1; i <= k - 2; i++){
        temp = temp->next;
    }

    Node *del = temp->next;
    temp->next = del->next;
    delete del;
}

// Xóa theo mã HS (đề yêu cầu)
void deleteByMa(Node *&head, string ma){
    if(head == NULL) return;

    if(head->maHS == ma){
        popFront(head);
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

// ===== KHÁC =====

// In danh sách
void duyet(Node *head){
    while(head != NULL){
        cout << head->maHS << " - " << head->diem << endl;
        head = head->next;
    }
}

// Đếm điểm thấp nhất
int countMin(Node *head){
    if(head == NULL) return 0;

    float minDiem = head->diem;
    Node *temp = head;

    while(temp != NULL){
        if(temp->diem < minDiem){
            minDiem = temp->diem;
        }
        temp = temp->next;
    }

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

// Xóa điểm < 5
void deleteLessThan5(Node *&head){
    while(head != NULL && head->diem < 5){
        popFront(head);
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

// ===== MAIN =====

int main(){
    Node *head = NULL;

    // Tạo danh sách (THÊM ĐẦU)
    pushFront(head, "HS01", 8.5);
    pushFront(head, "HS02", 4.0);
    pushFront(head, "HS03", 6.5);
    pushFront(head, "HS04", 4.0);
    pushFront(head, "HS05", 9.0);

    cout << "Danh sach ban dau:\n";
    duyet(head);

    cout << "\nSo mon diem thap nhat: " << countMin(head) << endl;

    deleteLessThan5(head);

    cout << "\nSau khi xoa diem < 5:\n";
    duyet(head);

    // ===== TEST thêm/xóa chuẩn DSLK =====
    pushBack(head, "HS06", 7.0);
    insert(head, 2, "HS07", 5.5);
    popFront(head);
    popBack(head);
    erase(head, 2);

    cout << "\nSau khi test them/xoa day du:\n";
    duyet(head);

    return 0;
}
