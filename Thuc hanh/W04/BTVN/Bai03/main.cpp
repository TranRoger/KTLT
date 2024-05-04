#include <iostream>
#include "header.h"

using namespace std;

int main() {
    // cau 1
    cout << "Cau 1: " << endl;
    DanhSachLienKet list;
    Node* p = new Node(3);
    list.print();
    cout << endl;

    list.addTail(new Node(7));
    list.addTail(new Node(6));
    list.addTail(new Node(9));
    list.addTail(new Node(2));
    list.addTail(new Node(8));
    list.addTail(new Node(7));
    list.addTail(new Node(8));
    // cau 2
    cout << "Cau 2 \nDanh sach hien tai: ";
    list.print();
    cout << endl;
    cout << "Danh sach sau khi them 3 vao dau:";
    list.addHead(p);
    list.print();
    cout << endl;
    // cau 3
    cout << "Cau 3: Danh sach sau khi them 5 vao cuoi: ";
    list.addTail(new Node(5));
    list.print();
    cout << endl;
    // cau 4
    cout << "Cau 4: Danh sach sau khi them 4 vao vi tri 2: ";
    list.addAtK(new Node(4), 2);
    list.print();
    cout << endl;
    // cau 5
    cout << "Cau 5: Danh sach sau khi xoa vi tri dau: ";
    list.deleteHead();
    list.print();
    cout << endl;
    // cau 6
    cout << "Cau 6: Danh sach sau khi xoa vi tri cuoi: ";
    list.deleteTail();
    list.print();
    cout << endl;
    // cau 7
    cout << "Cau 7: Danh sach sau khi xoa vi tri k: ";
    list.deleteAtK(3);
    list.print();
    cout << endl;
    // cau 8
    cout << "Nut co score lon nhat: " << list.highestScore()->score << endl;
    // cau 9
    cout << "Diem trung binh trong danh sach: " << list.avgScore() << endl;
    // cau 10
    list.sort();
    cout << "Danh sach sau khi sap xep:" << endl;
    list.print();
    cout << endl;

    return 0;
}