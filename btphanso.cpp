#include <iostream>
#include <numeric>
#include <limits>
using namespace std;

class phanSo {
private:
    int tuSo;
    int mauSo;

    void toiGian()
    {
        int ucll = std::gcd(tuSo, mauSo);
        tuSo /= ucll;//tu so toi gian = tuSo / uoc chung lon nhat,
        mauSo /= ucll;//mau so toi gian = mauSo / uoc chung lon nhat
    }
public:
    phanSo(int tu, int mau)
    {
        tuSo = tu;
        mauSo = mau;
        toiGian();
    }

    void print() const//ham print
    {
        if (tuSo == 0) {cout<<"0";}//neu tu so = 0 -> ps toi gian = 0
        else if (tuSo!=0 && mauSo==1) {cout<<tuSo;}//neu tu so != 0 va mau so = 1 -> ps toi gian = tu so
        else cout << tuSo << "/" << mauSo;//binh thuong thi in ra theo format tu so / mau so
    }

};
int main()
{
    int t1, m1;

    cout<<"Nhap tu so: ";                                                          //VD: Nhap tu so: 1 -> chap nhan
    while (!(cin>>t1))                                                             //    Nhap tu so: p[ew -> ko chap nhan
    {                                                                              //    Vui long nhap mot so tu nhien
        cout<<"ERROR! Vui long nhap mot so tu nhien \n"<<"Nhap tu so: ";           //    Nhap tu so: ...
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout<<"Nhap mau so: ";
    while (!(cin>>m1) || m1==0)
    {
        cout<<"ERROR! Vui long nhap mot so tu nhien khac 0 \n"<<"Nhap mau so: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    phanSo p1(t1, m1);
    cout << "Phan so toi gian: "; p1.print();//dua gia tri vao class phanso, phan so se duoc toi gian va in ra theo format tuong ung

    return 0;
}








