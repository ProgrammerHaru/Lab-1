#include <iostream>
using namespace std;
class Ngay{
    private:
        int d, m, y;
    public:
        void nhap(){
            cout << "Nhap ngay: ";
            cin >> d;
            cout << "Nhap thang: ";
            cin >> m;
            cout << "Nhap nam: ";
            cin >> y;
        } // input ngày, tháng, năm từ người dùng
    bool namNhuan(int year){
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    } // Kiểm tra năm nhuận theo quy tắc chuẩn
    int soNgayTrongThang(int month, int year){
        switch (month){
            case 4: case 6: case 9: case 11:
                return 30;
            case 2: return namNhuan(year) ? 29 : 28;
            default: return 31;
        }
    } // Xác định số ngày trong tháng, xử lý năm nhuận
    void NgayKeTiep(){
        d++;
        if (d > soNgayTrongThang(m, y)){
            d = 1;
            m++;
            if (m > 12){
                m = 1;
                y++;
            }
        }
    } // Tính ngày kế tiếp và chuyển tháng, năm
void Xuat(){
    printf("%02d/%02d/%04d\n", d, m, y); // In định dạng theo dd/mm/yyyy
}
};
int main(){
    Ngay n;
    n.nhap();
    n.NgayKeTiep();
    cout << "Ngay ke tiep la: ";
    n.Xuat();
    return 0;
}