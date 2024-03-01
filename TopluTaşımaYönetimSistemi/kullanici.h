#ifndef KULLANICI_H
#define KULLANICI_H

#include <iostream>
#include <string>

class Kullanici {
public:
    Kullanici(double sabitUcret, int sayi);

    double operator*(int sayi) const;  // * (�arpma) operat�r� a��r� y�klenmi�tir

    friend std::istream& operator>>(std::istream& in, Kullanici& t); //>> (input stream) operat�r� i�in bir friend fonksiyon 

    // Kullan�c�dan bilgileri alacak fonksiyon
    static void bilgileriAl(Kullanici& kullanici, const std::string& tasitAdi);

    double ucretHesaplama() const;

    double getSabitUcret() const;
    void setSabitUcret(double sabitUcret);

    int getSayi() const;
    void setSayi(int sayi);

private:
    double sabitUcret;
    int sayi;
};

#endif


