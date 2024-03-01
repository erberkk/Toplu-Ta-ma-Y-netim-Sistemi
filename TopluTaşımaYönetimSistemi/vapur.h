#ifndef VAPUR_H
#define VAPUR_H

#include "tasit.h"

class Vapur : public Tasit {
public:
    explicit Vapur(string _tasitId = " ", string _hatIsmi = " ", string _seferSaati = " ", string _seferBitisSaati = " ", string _ucret = " ", string _konduktorBilgileri =" ", string _kalkisDuragi = " ", string _varisDuragi = " ", string _durak1= " ",string _durak2= " ", string _durak3= " ", string _durak4= " ");
    ~Vapur();
    
    void dosyaOkuVapur();
    void kaydetVapur();
	string getvapurUcret() const;
	
	int getV3() const;
	void dijkstraAlgoritmasi()const;
	void hesaplaVeYazdirMesafeSuresi() const;
	
private:

	string dosyaadiVapur;
	string vapurUcret;
	
	static const int V3 = 9;
	const string ilceIsimleri[V3] = {"Kadikoy", "Moda", "Buyukada", "Heybeliada", "Eminonu", "Kinaliada", "Besiktas", "Bostanci", "Burgazada"};
    int guzergahMesafeleri[V3 - 1][V3 - 1];
    
    
	int graph[V3][V3];	
    int minDistance(int dist[], bool sptSet[]) const;
    void printSolution(int dist[]) const;
};

#endif

