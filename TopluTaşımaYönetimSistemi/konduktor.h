#ifndef KONDUKTOR_H
#define KONDUKTOR_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

class Konduktor{
public:
		
	Konduktor(string _konduktorIsim = " ", string _baslangicSaat = " ", string _bitisSaat = " ");
	~Konduktor();

    void konduktorSil(int satirNo);
	void konduktorEkle();
	void konduktorGoster() const ;
	
	bool zamanCakismasi(const Konduktor& s1, const Konduktor& s2);
	bool soforUygunMu(const vector<Konduktor>& shiftler, string konduktor, string baslangicSaat, string bitisSaat);
	
	void setkonduktor(string _konduktor);
	void setbaslangicSaat(string _baslangicSaat);
	void setbitisSaat(string _bitisSaat);
	
	string getkonduktor()const;
    string getbaslangicSaat() const;
    string getbitisSaat()const; 
    
    void dosyaOku();
    void kaydet();
	
private:
	static const int MAX_KONDUKTOR_BILGISI = 100; 
	string konduktorBilgileri[MAX_KONDUKTOR_BILGISI];
	int konduktorSayisi=0;
    string dosyaAdi;
    
    
	string konduktor;
	string baslangicSaat;
	string bitisSaat;
};
#endif


