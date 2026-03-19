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

    void xuat() {
        cout << tu << "/" << mau;
    }

    // Trả về giá trị thực để so sánh
    double giaTri() {
        return (double)tu / mau;
    }

    // So sánh đối tượng ps1 với đối tượng ps2
    bool lonHon(PhanSo ps2) {
        return this->tu * ps2.mau > ps2.tu * this->mau;
    }
};

int main() {
    PhanSo ps1, ps2;

    cout << "Nhap phan so thu nhat:\n";
    ps1.nhap();
    
    cout << "Nhap phan so thu hai:\n";
    ps2.nhap();

    cout << "\nPhan so lon nhat la: ";
    if (ps1.lonHon(ps2)) {
        ps1.xuat();
    } else {
        ps2.xuat();
    }

    cout << endl;
    return 0;
}