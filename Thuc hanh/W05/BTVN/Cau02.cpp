#include "header.h"

void Node::themCuoi(int *mang, const int &m) {
    Node *p = this;
    while (p->next != nullptr) {
        p = p->next;
    }
    p->next = new Node(mang, m);
}

void Node::inList() {
    Node *p = this;
    while (p) {
        for (int i = 0; i < arrSize; i++) {
            cout << p->ptr[i] << " ";
        }
        cout << endl;
        p = p->next;
    }
}

void Node::sort() {
    Node *p = this;
    while (p) {
        sapXep(p->ptr, p->arrSize);
    }
}

int **taoMang2Chieu(int &n, int &m) {
    srand(time(NULL));
    n = rand() % 10;
    m = rand() % 10;

    int **mang = new int*[n];
    for (int i = 0; i < n; i++) {
        mang[i] = new int[m];
        for (int j = 0; j < m; j++) {
            mang[i][j] = rand() % 100;
        }
    }
    return mang;
}

Node *taoList(int **mang, const int &n, const int &m) {
    Node *head = new Node(mang[0], m);
    for (int i = 1; i < n; i++) {
        head->themCuoi(mang[i], m);
    }
}

void sapXep(int *&mang, const int &n) {
    for (int i = 0; i < n; i++) {
        bool chanLe = (mang[i] & 1);
        int viTri = i;
        for (int j = i + 1; j < n; j++) {
            if (!chanLe && mang[viTri] > mang[j]) {
                viTri = j;
            }
            else if (chanLe && mang[viTri] < mang[j]) {
                viTri = j;
            }
        }
        swap(mang[viTri], mang[i]);
    }
}

int tongMang(int *mang, const int &n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        tong += mang[i];
    }
    return tong;
}

void ghiFile(Node *head, string tenFile) {
    ofstream fout;
    fout.open(tenFile, ios::out);
    if (!fout.good()) {
        cout << "Khong the mo file." << endl;
        return;
    }
    Node *p = head;
    while (p) {
        int tong = tongMang(p->ptr, p->arrSize);
        fout << tong;
        if (p->next != nullptr) {
            fout << " ";
        }
        p = p->next;
    }
    fout.close();
}

int* docFile(string tenFile, int &i) {
    ifstream fin;
    fin.open(tenFile, ios::in);
    if (!fin.good()) {
        cout << "Khong the mo file." << endl;
        return;
    }
    int mang[1000];
    while (!fin.eof()) {
        fin >> mang[i];
        i++;
    }
    fin.close();
    int *traVe = new int[i];
    for (int j = 0; j < i; j++) {
        traVe[j] = mang[j];
    }
    return traVe;
}

bool fibonacci(const int &a, const int &b, const int &so) {
    if (so == a || so == b) return true;
    return fibonacci(b, a + b, so);
}