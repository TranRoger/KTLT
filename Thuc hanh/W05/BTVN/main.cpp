#include "Cau01.h"
#include "Cau02.h"
#include "Cau03.h"

int main() {
    // cau 1
    cout << "Cau 1: " << endl;
    int n, m; 
    cout << "Nhap n va m: ";
    cin >> n >> m;
    int **maTran = createMatrix(n, m);
    tinhDuongCheo(maTran, n, m);
    inMaTran(congMaTran(maTran, maTran, n, m), n, m);
    int tong = tongMaTran(maTran, n, m);
    if (isPrime(tong)) cout << "Tong ma tran la mot so nguyen to." << endl;
    if (isPerfect(tong)) cout << "Tong ma tran la mot so hoan hao" << endl;
    int **nho = thuNho(maTran, n, m);
    cout << "Ma tran thu nho: " << endl;
    inMaTran(nho, n - 1, m - 1);
    cout << endl << endl;

    //cau 2
    cout << "Cau 2: " << endl;
    int n1, m1;
    int **arr2 = taoMang2Chieu(n1, m1);
    Node *head = taoList(arr2, n1, m1);
    head->inList();
    head->sort();
    head->inList();
    ghiFile(head, "data.txt");
    int size = 0, dem = 0;
    int *doc = docFile("data.txt", size);
    for (int i = 0; i < size; i++) {
        if (fibonacci(0, 1, doc[i])) {
            dem++;
        }
    }
    cout << "Co " << dem << " so trong mang 1 chieu co trong day fibonacci" << endl;
    cout << endl << endl;

    // cau 3
    cout << "Cau 3: " << endl;
    StudentList ll2;
    docFile(ll2, "data2.txt");
    cout << "Danh sach: " << endl;
    ll2.inDs();
    ll2.sort();
    cout << "Danh sach sau khi sap xep: " << endl;
    ll2.inDs();
    StudentList hs = hsg(ll2);
    cout << "Danh sach hoc sinh diem trung binh tren 8 va khong co mon nao duoi 7: " << endl;
    hs.inDs();
    
    system("pause");
    return 0;
}