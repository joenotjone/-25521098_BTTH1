#include <iostream>
#include <limits>
using namespace std;

class date {
private:
    int ngay;
    int thang;
    int nam;        //dinh nghia ngay, thang, nam

public:
    date(int ng, int th, int nm) {
        ngay = ng;
        thang = th;
        nam = nm;
    }

    void print() const
    {cout << ngay << "/" << thang << "/" << nam;} //xac dinh kieu ouput

    // Tinh nam nhuan
    static bool namNhuan(int year)
    {return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);}

    //Xac dinh so ngay trong thang
    static int ngayTrongThang(int month, int year)
    {
        switch (month)
        {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;//thang 1,3,5,7,8,10,12 co 31 ngay
            case 4: case 6: case 9: case 11: return 30;//thang 4,6,9,11 co 30 ngay
            case 2: return namNhuan(year) ? 29 : 28;//thang 2 co 28 ngay, 29 neu la nam nhuan
            default: return 0; //neu ko thuoc cac truong hop tren thi tra ve invalid
        }
    }

    // ham kiem tra
    static bool kiemTra(int d, int m, int y)
    {
        if (y < 0 || m < 1 || m > 12 || d < 1) return false;
        return d <= ngayTrongThang(m, y);
    }

    // ham tinh ngay hom sau
    date ngayMai() const
    {
        int d = ngay, m = thang, y = nam;
        d++; //+1 vao ngay
        if (d > ngayTrongThang(m, y))
        {
            d = 1;
            m++; //neu het ngay trong thang thi dat ngay = 1, +1 vao thang
            if (m > 12)
            {m = 1; y++;} //neu het thang thi dat thang = 1, +1 vao nam
        }
        return date(d, m, y);
    }
};
int main() {
    int day, month, year;

    cout << "Nhap ngay / thang / nam: ";
    while (!(cin >> day >> month >> year) || !date::kiemTra(day, month, year)) //nhap ngay, thang, nam va kiem tra
    {
        cout << "ERROR! Vui long nhap ngay hop le (1-"
             << date::ngayTrongThang(month, year)
             << ") cho thang " << month << ": ";         //ERROR! Vui long nhap ngay hop le (1 - *ngay toi da trong thang*) cho thang *thang hien tai*
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    date homNay(day, month, year);
    date homSau = homNay.ngayMai();

    cout << "Ngay hom nay: "; homNay.print(); cout << endl;
    cout << "Ngay mai: "; homSau.print(); cout << endl;

    return 0;
}
