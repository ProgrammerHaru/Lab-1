#include <iostream>
#include <cmath> // Để dùng hàm abs()
using namespace std;
class PhanSo {
private:
    int tu, mau;
public:
    void nhap() {
        cout << "Nhap tu so: ";
        cin >> tu;
        do {
            cout << "Nhap mau so: ";
            cin >> mau;
            if (mau == 0) {
                cout << "Loi dinh dang phan so. nhap lai\n";
            }
        } while (mau == 0);
    } // Phương thức nhập có vòng lặp kiểm tra mẫu số
    int timUCLN(int a, int b) {
        a = abs(a);
        b = abs(b);
        while (b != 0) {
            int r = a % b;
            a = b;
            b = r;
        }
        return a;
    } // Thuật toán Euclid tìm UCLN
    void rutGon() {
        int ucln = timUCLN(tu, mau);
        tu /= ucln;
        mau /= ucln;
        if (mau < 0) {
            tu = -tu;
            mau = -mau;
        }
    } // Xử lý dấu trừ để phân số đúng chuẩn định dạng
    void xuat() {
        if (mau == 1) {
            cout << tu << "/" << mau << endl;
        } else {
            cout << tu << "/" << mau << endl;
        }
    } // Xuất kết quả
};
int main() {
    PhanSo ps; // Tạo phân số
    ps.nhap();
    ps.rutGon();
    cout << "Phan so sau khi rut gon la: ";
    ps.xuat();
    return 0;
}