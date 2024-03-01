#ifndef TASIT_H
#define TASIT_H
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

class Tasit {
public:
    friend ostream& operator<<(ostream& os, const Tasit& tasit);
    friend istream& operator>>(istream& is, Tasit& tasit);
    
	explicit Tasit(string _tasitId = " ", string _hatIsmi = " ", string _seferSaati = " ", string _seferBitisSaati = " ", string _ucret = " ", string _konduktorBilgileri =" ", string _kalkisDuragi = " ", string _varisDuragi = " ", string _durak1= " ",string _durak2= " ", string _durak3= " ", string _durak4= " ");
    ~Tasit();

    void tasitGuncelle(int satirNo);
    void tasitSil(int satirNo);
	void tasitEkle();
	void bilgileriGoster() const ;
	void tasitAra(const string& kalkisDuragi, const string& varisDuragi)const;
	void ortalamaUcretHesapla(int ortUcret);  
	void ortalamaUcretHesapla(double ortUcret);

	void dijkstraAlgoritmasi()const;
	int getV() const; 
	
    void dosyaOku();
    void kaydet();
    
    void settasitId(string _tasitId);
    void sethatIsmi(string _hatIsmi);
    void setseferSaati(string _seferSaati);
    void setseferBitisSaati(string _seferBitisSaati);
    void setucret(string _ucret);
    void setkonduktorBilgileri(string _konduktorBilgileri);
    void setkalkisDuragi(string _kalkisDuragi);
    void setvarisDuragi(string _varisDuragi);
    
    string gettasitId()const;
    string gethatIsmi()const;
    string getseferSaati()const;
    string getseferBitisSaati()const;
    string getucret()const;
    string getkonduktorBilgileri()const;
    string getkalkisDuragi()const;
    string getvarisDuragi()const;
    int getTasitSayisi() const;

	void setdurak1(string _durak1);
	void setdurak2(string _durak2);
	void setdurak3(string _durak3);
	void setdurak4(string _durak4);
	
	static int ucretTotal(int ucret);
	
	string getdurak1() const;
	string getdurak2() const;
	string getdurak3() const;
	string getdurak4() const;
	
	bool konduktorSaatAraligiKontrol(const string& konduktorBilgisi, const string& seferSaati, const string& seferBitisSaati) const;
	bool kontrolKonduktorVeSaat(const string& konduktorBilgisi, const string& seferSaati, const string& seferBitisSaati) const;
	
	bool isValidTimeFormat(const std::string& timeStr);
protected:
	
	static const int MAX_TASIT_BILGISI = 100; 
	string tasitBilgileri[MAX_TASIT_BILGISI];
	int tasitSayisi=0;
    string dosyaAdi;
    
    static const int V = 9;
	string dosyaadiMetro;
	string metroUcret;
	const string ilceIsimleri[V] = {"Besiktas", "Kadikoy", "Sisli", "Uskudar", "Fatih", "Esenler", "Beylikduzu", "Sariyer", "Kartal"};
	
    mutable int guzergahMesafeleri[V - 1][V - 1]; //V degeri const olmasina ragmen degistirmek istedigimiz icin mutable atandi
    
	int graph[V][V];	
    int minDistance(int dist[], bool sptSet[]) const;
    void printSolution(int dist[]) const;
    
    double stringToDouble(const string& str) const; 
	   
    string seferSaati;
    string seferBitisSaati;
    string tasitId;
    string hatIsmi;
    string ucret;
    string konduktorBilgileri;
    string kalkisDuragi;
    string varisDuragi;
    
    string durak1;
	string durak2;
	string durak3;
	string durak4;
};
#endif

