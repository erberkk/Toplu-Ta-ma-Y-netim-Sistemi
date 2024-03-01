#ifndef EKRAN_H
#define EKRAN_H


#include <iostream>
using namespace std;

class Ekran{
public:	
	void girisEkrani();
	int girisEkraniTercih(int tercih);
	
	void adminEkrani();
	void kullaniciEkrani();
	
	void seferBilgileri();
	void seferDuzenleme();
	void seferEkleme();
	void seferSilme();
	void seferAra();

	void ucretBilgileri();
	
	void tasitBilgileri();
	void metroBilgileri();
	void otobusBilgileri();
	void vapurBilgileri();
	void tramvayBilgileri();
	void ucretHesapla();

};

#endif
