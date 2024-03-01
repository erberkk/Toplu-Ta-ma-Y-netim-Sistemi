#ifndef METRO_H
#define METRO_H

#include "tasit.h"

class Metro : public Tasit {
public:
    explicit Metro(string _tasitId = " ", string _hatIsmi = " ", string _seferSaati = " ", string _seferBitisSaati = " ", string _ucret = " ", string _konduktorBilgileri =" ", string _kalkisDuragi = " ", string _varisDuragi = " ", string _durak1= " ",string _durak2= " ", string _durak3= " ", string _durak4= " ");
    ~Metro();
    
    void dosyaOkuMetro();
    void kaydetMetro();
    int getV1() const;
    string getmetroUcreti() const;
    void dijkstraAlgoritmasi()const;
    void hesaplaVeYazdirMesafeSuresi() const;
	
	
private:
	static const int V1 = 10;
	string dosyaadiMetro;
	string metroUcret;
	const string ilceIsimleri[V1] = {"Uskudar", "Kadikoy", "Yildiz", "Yenikapi", "Kucukyali", "Bostanci", "Haciosman", "Acibadem", "Bakirkoy","Merter"};
	
    int guzergahMesafeleri[V1 - 1][V1 - 1]; //-1 olma nedeni bir ilcenin kendine olan mesafeyi otomatik olarak 0 kabul etmesi icin
    
    
	int graph[V1][V1];	
    int minDistance(int dist[], bool sptSet[]) const;
    void printSolution(int dist[]) const;

};

#endif




