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

      // Phép tính trả về một đối tượng PhanSo mới
    PhanSo cong(PhanSo b) {
        PhanSo kq;
        kq.tu = this->tu * b.mau + b.tu * this->mau;
        kq.mau = this->mau * b.mau;
        kq.rutGon();
        return kq;
    }
    PhanSo tru(PhanSo b) {
        PhanSo kq;
        kq.tu = this->tu * b.mau - b.tu * this->mau;
        kq.mau = this->mau * b.mau;
        kq.rutGon();
        return kq;
    }
    PhanSo nhan(PhanSo b) {
        PhanSo kq;
        kq.tu = this->tu * b.tu;
        kq.mau = this->mau * b.mau;
        kq.rutGon();
        return kq;
    }
    PhanSo chia(PhanSo b) {
        PhanSo kq;
        kq.tu = this->tu * b.mau;
        kq.mau = this->mau * b.tu;
        kq.rutGon();
        return kq;
    }
    void xuat() {
        if (mau == 1) {
            cout << tu << "/" << mau << endl;
        } else {
            cout << tu << "/" << mau << endl;
        }
    } // Xuất kết quả
};

int main() {
    PhanSo ps1, ps2;
    cout << "Nhap phan so 1:\n"; ps1.nhap();
    cout << "Nhap phan so 2:\n"; ps2.nhap();

    cout << "\nTong: "; ps1.cong(ps2).xuat();
    cout << "\nHieu: "; ps1.tru(ps2).xuat();
    cout << "\nTich: "; ps1.nhan(ps2).xuat();
    cout << "\nThuong: "; ps1.chia(ps2).xuat();
    return 0;
}