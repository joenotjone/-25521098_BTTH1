#include <iostream>
#include <limits>
#include <string>
#include <cctype>
using namespace std;

class ketqua {
private:
    string hoTen;
    double diemToan;
    double diemVan;  //xac dinh kieu du lieu cho ten, diem toan, diem van

    static double diemTrungBinh(double diemToan, double diemVan)
    {return ((diemToan+diemVan)/2.0);}  //ham tinh diem trung binh

    static bool kiemTraTen(const string& name)
    {
    bool coChuCai = false;

    for (char c : name) {
        if (isalpha(c)) {
            coChuCai = true; // co chu cai trong ten
        } else if (!isspace(c)) {
            return false; // khong duoc co ky tu dac biet, cho phep khoang trang
        }
    }
    // Khong duoc de trong ten
    return coChuCai;
    }


public:
    ketqua(string ten, double toan, double van)
    {
        hoTen = ten;
        diemToan = toan;
        diemVan = van;
    }

    void print() const
    {cout << "Ket qua hoc tap: "<<endl;
     cout << "Ho va Ten SV: "<<hoTen<<endl;
     cout << "Diem Toan: "<<diemToan<<endl;
     cout << "Diem Van: "<<diemVan<<endl;
     cout << "Diem Trung Binh: "<< diemTrungBinh(diemToan, diemVan) <<endl;}

    static bool checkName(const string& name)
    {return kiemTraTen(name);}

};
int main() {
    string name; double math, literature;

    cout << "Ho va Ten: ";
    getline(cin, name);//Nhap ten

    // kiem tra ten
    while (!ketqua::checkName(name))
    {
        cout << "ERROR! Ten chi duoc chua chu cai va khoang trang. Vui long nhap lai: ";
        getline(cin, name);
    }

    cout << "Diem Toan: ";
    while (!(cin >> math) || math < 0 || math > 10)
    {
        cout << "ERROR! Vui long nhap diem hop le (0-10): ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //nhap diem toan (0-10)
    }

    cout << "Diem Van: ";
    while (!(cin >> literature) || literature < 0 || literature > 10)
    {
        cout << "ERROR! Vui long nhap diem hop le (0-10): ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //nhap diem van (0-10)
    }

    ketqua kq(name, math, literature);
    kq.print();

    return 0;
}
