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
        int ucln = std::gcd(tuSo, mauSo);
        tuSo /= ucln; mauSo /= ucln;
    }
public:
    phanSo(int tu, int mau)
    {
        tuSo = tu;
        mauSo = mau;
        toiGian();
    }

    static void nhap(int &t, int &m)
    {
        cout<<"Nhap tu so: ";
        while (!(cin>>t))
        {
            cout<<"ERROR! Vui long nhap mot so tu nhien \n"<<"Nhap tu so: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout<<"Nhap mau so: ";
        while (!(cin>>m) || m==0)
        {
            cout<<"ERROR! Vui long nhap mot so tu nhien khac 0 \n"<<"Nhap mau so: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    void print() const
    {
        if (tuSo == 0) {cout<<"0";}
        else if (mauSo == 0){cout<<"ERROR! Khong the chia het cho 0";}
        else if (tuSo!=0 && mauSo==1) {cout<<tuSo;}
        else cout << tuSo << "/" << mauSo;
    }

    bool operator>(const phanSo& ps2) const
    {return tuSo * ps2.mauSo > ps2.tuSo * mauSo;}

    bool operator==(const phanSo& ps2) const
    {return tuSo == ps2.tuSo && mauSo == ps2.mauSo;}

    phanSo operator+(const phanSo& ps2) const
    {
        int newTuSo = tuSo*ps2.mauSo + ps2.tuSo*mauSo;
        int newMauSo = mauSo*ps2.mauSo;
        return phanSo(newTuSo, newMauSo);
    }
    phanSo operator-(const phanSo& ps2) const
    {
        int newTuSo = tuSo*ps2.mauSo - ps2.tuSo*mauSo;
        int newMauSo = mauSo*ps2.mauSo;
        return phanSo(newTuSo, newMauSo);
    }
    phanSo operator*(const phanSo& ps2) const
    {
        int newTuSo = tuSo*ps2.tuSo;
        int newMauSo = mauSo*ps2.mauSo;
        return phanSo(newTuSo, newMauSo);
    }
    phanSo operator/(const phanSo& ps2) const
    {
        if (ps2.tuSo == 0) {return phanSo(1,0);}
        int newTuSo = tuSo * ps2.mauSo;
        int newMauSo = mauSo * ps2.tuSo;
        return phanSo(newTuSo, newMauSo);
    }

};
int main()
{
    int t1, m1, t2, m2;

    cout<<"Nhap phan so A "<<endl;
    phanSo::nhap(t1, m1);
    cout<<"Nhap phan so B "<<endl;
    phanSo::nhap(t2, m2);

    phanSo p1(t1, m1);
    phanSo p2(t2, m2);

    cout << "Phan so 1 (da toi gian): "; p1.print(); cout << endl;
    cout << "Phan so 2 (da toi gian): "; p2.print(); cout << endl;

    if (p1>p2)
        {cout << "A > B" << endl;}
    else if (p2>p1)
        {cout << "A < B" << endl;}
    else
        {cout << "A = B" << endl;}

    phanSo tong = p1 + p2;
    cout << "Tong: "; tong.print(); cout<<endl;
    phanSo hieu = p1 - p2;
    cout << "Hieu: "; hieu.print(); cout<<endl;
    phanSo tich = p1 * p2;
    cout << "Tich: "; tich.print(); cout<<endl;
    phanSo thuong = p1 / p2;
    cout << "Thuong: "; thuong.print();
    return 0;
}








