#include "vapur.h"

using namespace std;
Vapur :: Vapur (string _tasitId, string _hatIsmi, string _seferSaati, string _seferBitisSaati, string _ucret, string _konduktorBilgileri, string _kalkisDuragi, string _varisDuragi, string _durak1, string _durak2, string _durak3, string _durak4)
	: Tasit (_tasitId, _hatIsmi, _seferSaati, _seferBitisSaati, _ucret, _konduktorBilgileri,"Kadikoy", _varisDuragi, _durak1, _durak2, _durak3, _durak4) {
		
	dosyaAdi = "vapur.txt";
    dosyaOkuVapur();
	vapurUcret = "20";
	
	int tempGraph[V3][V3] = {{0, 3, 0, 0, 0, 0, 0, 10, 0},
                            {3, 0, 7, 0, 0, 0, 0, 10, 4},
                            {0, 7, 0, 6, 0, 2, 0, 0, 2},
                            {0, 0, 6, 0, 8, 13, 0, 0, 3},
                            {0, 0, 0, 8, 0, 9, 0, 0, 0},
                            {0, 0, 2, 13, 9, 0, 4, 0, 5},
                            {0, 0, 0, 0, 0, 4, 0, 2, 5},
                            {10, 10, 0, 0, 0, 0, 2, 0, 8},
                            {0, 4, 2, 3, 0, 5, 5, 6, 0}};

    for (int i = 0; i < V3; ++i) {
        for (int j = 0; j < V; ++j) {
            graph[i][j] = tempGraph[i][j];
        }
    }
}
	
Vapur:: ~Vapur() {
	kaydetVapur();
}	

void Vapur::kaydetVapur() {
    ofstream dosya(dosyaAdi.c_str());

    if (dosya.is_open()) {
        for (int i = 0; i < tasitSayisi; ++i) {
            dosya << tasitBilgileri[i] << "\n";
        }
        dosya.close();
    }
    else {
        cerr << "Dosya acilamadi: " << dosyaAdi << std::endl;
    }
}

void Vapur::dosyaOkuVapur() {
    ifstream dosya(dosyaAdi.c_str());

    if (dosya.is_open()) {
        string satir;
        while (getline(dosya, satir) && tasitSayisi < MAX_TASIT_BILGISI) {
            tasitBilgileri[tasitSayisi++] = satir;
        }
        dosya.close();
    }
}

string Vapur :: getvapurUcret () const{
return vapurUcret;
}

void Vapur::printSolution(int dist[]) const {
    cout << "Bolge Adi \t\t\t     Mesafe (km)" << endl<<endl;
    for (int i = 0; i < V3; i++)
        cout << ilceIsimleri[i] << " \t\t\t\t" << dist[i] << endl;
}


void Vapur::dijkstraAlgoritmasi() const {
    int dist[V3];
    bool sptSet[V3];

    for (int i = 0; i < V3; i++) {
        dist[i] = numeric_limits<int>::max();
        sptSet[i] = false;
    }

    dist[0] = 0;

    for (int count = 0; count < V3 - 1; count++) {
        int u = minDistance(dist, sptSet);

        sptSet[u] = true;

        for (int v = 0; v < V3; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != numeric_limits<int>::max() && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist);
}

int Vapur::getV3() const {
    return V3;
}

int Vapur::minDistance(int dist[], bool sptSet[]) const {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V3 ;v++)
        if (!sptSet[v] && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}



void Vapur::hesaplaVeYazdirMesafeSuresi() const {
    string kalkis = "Kadikoy";
	string varis;
    cout << "Dikkat! Vapurlarin kalkis istasyonu Kadikoy'de bulunmaktadir." <<endl<<endl;
    cout << "Vapur ile gidebileceginiz konumlar: Moda, Buyukada, Heybeliada, Eminonu, Kinaliada, Besiktas, Bostanci, Burgazada" <<endl<<endl;
    cout << "Varis duragini seciniz: ";
    
    cin >> varis;
    
 
    int kalkisIndex = -1 ,varisIndex = -1; // ilk basta indeksleri -1'e esitliyoruz, gecerli bir indeks degeri olmadigini belirtmek icin
    for (int i = 0; i < V3; ++i) {
        if (ilceIsimleri[i] == kalkis) {
            kalkisIndex = i;
        }							  // diziyi bastan konrtol ederek durak ismi kalkis ile eslesirse kalkisIndeks'e atiyor.
        if (ilceIsimleri[i] == varis) {
            varisIndex = i;
        }
    }
    
  
    if ( varisIndex == -1) {	//kalkis veya varis duragi bulamaz ve indeks -1 olarak kalirsa hata veriyor.
        cerr << "Hatali giris! Lutfen gecerli durak isimleri giriniz." << endl;
        return;
    }
    
    int mesafe = guzergahMesafeleri[kalkisIndex][varisIndex];
    int dist[V3];
    bool sptSet[V3];

    for (int i = 0; i < V3; i++) {
        dist[i] = numeric_limits<int>::max();
        sptSet[i] = false;
    }
	//dist baslangicta her bir dugumun kalkis noktasindan uzakligini saklar, sptSet ise belirli bir dugumun yol agacina dahil olup olmadigini belirtir
	
	
    dist[kalkisIndex] = 0; //baslangicta dist dizisi 0'a esitlenir

    for (int count = 0; count < V3 - 1; count++) { 
        int u = minDistance(dist, sptSet);

        sptSet[u] = true;

        for (int v = 0; v < V3; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != numeric_limits<int>::max() && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    int mesafe3 = dist[varisIndex];
    string onerilenHat;
    
    switch(mesafe3){
    	case 3:
    		onerilenHat = "V3";
    		break;
    	case 9:
			onerilenHat = "V1";
			break;
		case 10:
			onerilenHat = "V2";
			break;
		case 18:
			onerilenHat = "V2";
			break;
		case 11:
			onerilenHat	= "V1";
			break;
		case 12:
			onerilenHat = "V3";
			break;
		case 7:
			onerilenHat = "V1";
			break;			
		default:
			cout<< "Baslangic Noktasindasiniz..";
			break;
	}

    cout << "\nKalkis: " << kalkis << "\nVaris: " << varis << "\nMesafe Suresi: " << dist[varisIndex] << " km" << endl;
    cout << "Onerilen Hat: " << onerilenHat << endl;
    cout << "Ucret: " << vapurUcret << "TL" <<endl;
    cout << "Tahmini Seyahat Suresi: " << dist[varisIndex]*1.75 << " dk" << endl<<endl;
        if (onerilenHat == "V1"){
    	cout << "Bu Hatla Gidilebilecek Duraklar: Kadikoy, Buyukada, Burgazada, Kinaliada."<<endl<<endl;
	}
	else if (onerilenHat == "V2"){
		cout << "Bu Hatla Gidilebilecek Duraklar: Kadikoy, Eminonu, Heybeliada, Burgazada. "<<endl<<endl;
	}
	else {
		cout << "Bu Hatla Gidilebilecek Duraklar: Kadikoy, Moda, Bostanci, Besiktas."<<endl<<endl;		
	}
    
}
