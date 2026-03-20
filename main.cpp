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
        tuSo /= ucll;
        mauSo /= ucll;
    }
public:
    phanSo(int tu, int mau)
    {
        tuSo = tu;
        mauSo = mau;
        toiGian();
    }

    void print() const
    {
        if (tuSo == 0) {cout<<"0";}
        else if (tuSo!=0 && mauSo==1) {cout<<tuSo;}
        else cout << tuSo << "/" << mauSo;
    }

};
int main()
{
    int t1, m1;

    cout<<"Nhap tu so: ";
    while (!(cin>>t1))
    {
        cout<<"ERROR! Vui long nhap mot so tu nhien \n"<<"Nhap tu so: ";
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
    cout << "Phan so toi gian: "; p1.print();

    return 0;
}








