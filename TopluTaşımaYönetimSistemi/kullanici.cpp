#include "kullanici.h"

using namespace std;
Kullanici::Kullanici(double sabitUcret, int sayi) : sabitUcret(sabitUcret), sayi(sayi) {}

double Kullanici::operator*(int sayi) const {  
    return sayi * sabitUcret;
}

std::istream& operator>>(std::istream& in, Kullanici& t) {
    in >> t.sayi;
    return in;
}

void Kullanici::bilgileriAl(Kullanici& kullanici, const std::string& tasitAdi) {
    cout << "Kac kez " << tasitAdi << " kullanacaksiniz? ";
    cin >> kullanici;
}

double Kullanici::ucretHesaplama() const {
    return sayi * sabitUcret;
}

double Kullanici::getSabitUcret() const {
    return sabitUcret;
}

void Kullanici::setSabitUcret(double sabitUcret) {
    this->sabitUcret = sabitUcret;
}

int Kullanici::getSayi() const {
    return sayi;
}

void Kullanici::setSayi(int sayi) {
    this->sayi = sayi;
}

