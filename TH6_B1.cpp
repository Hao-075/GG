#include<iostream>
#include<fstream>
#include<string>
using namespace std;
// Khai bao to chuc du lieu.
struct Word
{
    string english;
    string vietnamese;
};

struct EngVietDict
{
    Word data;
    EngVietDict *left, *right;
};
// a) Them mot phan tu vao cay tu dien.
void insertWord(EngVietDict *&root, Word data) {
    if (root == NULL) {
        root = new EngVietDict;
        root->data = data;
        root->left = root->right = NULL;

    } else if (data.english < root->data.english) {
        insertWord(root->left, data);
    } else if (data.english > root->data.english) {
        insertWord(root->right, data);
    }
}
// b) Doc tu dien tu tep.
void readDictFromFile(EngVietDict *&root, string fileName) {
    ifstream file(fileName);

    if (!file) {
        cout << "Khong mo duoc file!" << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        int pos = line.find(':');
        if (pos == -1) continue;

        string eng = line.substr(0, pos);
        string viet = line.substr(pos + 1);

        Word data = {eng, viet};
        insertWord(root, data);
    }
    file.close();
}
// c) In tu dien.
void printDict(EngVietDict *root) {
    if (root) {
        printDict(root->left);
        cout << root->data.english << " : " << root->data.vietnamese << endl;
        printDict(root->right);
    }
}
// d) Thao tac tra tu.
string findVietnamese(EngVietDict *root, string eng) {
    if (root == NULL) {
        return "";
    }

    if (root->data.english == eng) {
        return root->data.vietnamese;
    }

    if (eng < root->data.english) {
        return findVietnamese(root->left, eng);
    } else {
        return findVietnamese(root->right, eng);
    }
}
// e) Xoa mot tu trong cay tu dien.
EngVietDict *findMin(EngVietDict *root) {
    if (root->left == NULL) {
        return root;
    }
    return findMin(root->left);
}

void deleteWord(EngVietDict *&root, string eng) {
    if (root == NULL) {
        return;
    }
    if (eng < root->data.english) {
        deleteWord(root->left, eng);
    } else if (eng > root->data.english) {
        deleteWord(root->right, eng);
    } else {
        if (root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
        } else if (root->left == NULL) {
            EngVietDict *temp = root;
            root = root->right;
            delete temp;
        } else if (root->right == NULL) {
            EngVietDict *temp = root;
            root = root->left;
            delete temp;
        } else {
            EngVietDict *temp = findMin(root->right);
            root->data = temp->data;
            deleteWord(root->right, temp->data.english);
        }
    }
}
// f) In man hinh tu tieng Anh bat dau bang H va nghia tieng Viet.
void printWordByH(EngVietDict* root) {
    if (root == NULL) return;

    printWordByH(root->left);

    if (!root->data.english.empty() &&
        (root->data.english[0] == 'H' || root->data.english[0] == 'h')) {
        cout << root->data.english << " : " << root->data.vietnamese << endl;
    }

    printWordByH(root->right);
}
// g) Dem so tu sau tu t.
int countAfterAWord(EngVietDict* root, string word){
    if (root == NULL) return 0;

    if (root->data.english > word) {
        return 1 + countAfterAWord(root->left, word)
                 + countAfterAWord(root->right, word);
    } else {
        return countAfterAWord(root->right, word);
    }
}
// h) Luu tu dien.
void saveDictHelper(EngVietDict* root, ofstream &file) {
    if (root == NULL) return;

    saveDictHelper(root->left, file);

    file << root->data.english << ":" << root->data.vietnamese << endl;

    saveDictHelper(root->right, file);
}

void saveDictToFile(EngVietDict* root, string fileName) {
    ofstream file(fileName);

    if (!file) {
        cout << "Khong mo duoc file!" << endl;
        return;
    }

    saveDictHelper(root, file);

    file.close();
}
// Giai phong bo nho.
void freeTree(EngVietDict* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}
// Ham main.
int main()
{
    EngVietDict *root = NULL;
    string eng, viet;

    readDictFromFile(root, "D:\\TH6B1.txt");

    cout << "Dictionary:\n";
    printDict(root);

    cout << "Input an English word: ";
    cin >> eng;

    viet = findVietnamese(root, eng);

    if (viet != "")
        cout << eng << ": " << viet << endl;
    else
        cout << eng << " not found in dictionary." << endl;

    cout << "Nhap tu can xoa: ";
    cin >> eng;
    deleteWord(root, eng);

    cout << "After delete:\n";
    printDict(root);

    saveDictToFile(root, "D:\\TH6B1.txt");

    freeTree(root);

    return 0;
}
