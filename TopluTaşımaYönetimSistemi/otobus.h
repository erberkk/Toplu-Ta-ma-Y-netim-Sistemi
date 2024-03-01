#ifndef OTOBUS_H
#define OTOBUS_H

#include "tasit.h"

class Otobus : public Tasit {
public:
    explicit Otobus(string _tasitId = " ", string _hatIsmi = " ", string _seferSaati = " ", string _seferBitisSaati = " ", string _ucret = " ", string _konduktorBilgileri =" ", string _kalkisDuragi = " ", string _varisDuragi = " ", string _durak1= " ",string _durak2= " ", string _durak3= " ", string _durak4= " ");
    ~Otobus();
    
    void dosyaOkuOtobus();
    void kaydetOtobus();

	string getotobusUcret() const;
	
	int getV4() const;
	void dijkstraAlgoritmasi()const;
	void hesaplaVeYazdirMesafeSuresi() const;

private:
	string dosyaadiOtobus;
	string otobusUcret;
	
	static const int V4 = 9;

	const string ilceIsimleri[V4] = {"Kavacik", "Bulgurlu", "Nakkastepe", "Kadikoy", "Icadiye", "Atasehir", "Suadiye", "Erenkoy", "Cengelkoy"};
	
    int guzergahMesafeleri[V4 - 1][V4 - 1];
    
    
	int graph[V4][V4];	
    int minDistance(int dist[], bool sptSet[]) const;
    void printSolution(int dist[]) const;
};

#endif

