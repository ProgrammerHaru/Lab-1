#include <iostream>
#include <string>
#include <bits/stdc++.h> // Để dùng hàm getline()
#include <iomanip> // Để dùng setprecision
using namespace std;
class Hocsinh{
    private:
        string ten;
        float diemToan, diemVan;
    public:
        void nhap(){
            cout << "nhap ten: ";
            getline(cin, ten);
            cout << "nhap diem toan: ";
            cin >> diemToan;
            cout << "nhap diem van: ";
            cin >> diemVan;
        } // phuong thuc nhap thong tin hoc sinh va diem so
        float tinhDtb(){
            return (diemToan + diemVan) / 2;
        }
        void xuat(){
            cout << "Hoc sinh: " << ten << endl;
            cout << "Diem trung binh: " << fixed << setprecision(2) << tinhDtb() << endl;
        }
};
int main(){
    Hocsinh hs;
    hs.nhap();
    hs.xuat();
    return 0;
}