#ifndef TRAMVAY_H
#define TRAMVAY_H

#include "tasit.h"

class Tramvay : public Tasit {
public:
    explicit Tramvay(string _tasitId = " ", string _hatIsmi = " ", string _seferSaati = " ", string _seferBitisSaati = " ", string _ucret = " ", string _konduktorBilgileri =" ", string _kalkisDuragi = " ", string _varisDuragi = " ", string _durak1= " ",string _durak2= " ", string _durak3= " ", string _durak4= " ");
    ~Tramvay();
    
    void dosyaOkuTramvay();
    void kaydetTramvay();
    void dijkstraAlgoritmasi()const;
    string gettramvayUcret() const;
    int getV2() const;
    void hesaplaVeYazdirMesafeSuresi() const;

private:
	static const int V2 = 9;
	string dosyaadiTramvay;
	string tramvayUcret;
	const string ilceIsimleri[V2] = {"Bagcilar", "Merter", "Sisli", "Uskudar", "Fatih", "Esenler", "Beylikduzu", "Sariyer", "Kartal"};
	
    int guzergahMesafeleri[V2 - 1][V2 - 1];
    
    
	int graph[V2][V2];	
    int minDistance(int dist[], bool sptSet[]) const;
    void printSolution(int dist[]) const;
};

#endif

