#include "otobus.h"

using namespace std;
Otobus :: Otobus
 (string _tasitId, string _hatIsmi, string _seferSaati, string _seferBitisSaati, string _ucret, string _konduktorBilgileri, string _kalkisDuragi, string _varisDuragi, string _durak1, string _durak2, string _durak3, string _durak4)
	: Tasit (_tasitId, _hatIsmi, _seferSaati, _seferBitisSaati, _ucret, _konduktorBilgileri,"Kavacik", _varisDuragi, _durak1, _durak2, _durak3, _durak4) {
		
	dosyaAdi = "otobus.txt";
    dosyaOkuOtobus();
    otobusUcret = "9";  	
	
	int tempGraph[V4][V4] = {{0, 2, 5, 6, 0, 0, 0, 8, 0},
                            {2, 0, 2, 0, 7, 0, 0, 12, 0},
                            {5, 2, 0, 1, 4, 3, 0, 0, 0},
                            {6, 0, 1, 0, 0, 4, 0, 0, 9},
                            {0, 7, 4, 0, 0, 4, 0, 5, 0},
                            {0, 0, 3, 4, 4, 0, 0, 7, 0},
                            {0, 12, 0, 0, 0, 0, 0, 3, 0},
                            {0, 0, 0, 0, 5, 7, 3, 0, 6},
                            {0, 0, 0, 9, 0, 0, 0, 6, 0}};

    for (int i = 0; i < V4; ++i) {
        for (int j = 0; j < V4; ++j) {
            graph[i][j] = tempGraph[i][j];
        }
    }
}
	
Otobus:: ~Otobus() {
	kaydetOtobus();
}	

void Otobus::kaydetOtobus() {
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

void Otobus::dosyaOkuOtobus() {
    ifstream dosya(dosyaAdi.c_str());

    if (dosya.is_open()) {
        string satir;
        while (getline(dosya, satir) && tasitSayisi < MAX_TASIT_BILGISI) {
            tasitBilgileri[tasitSayisi++] = satir;
        }
        dosya.close();
    }
}

string Otobus :: getotobusUcret() const {
return otobusUcret;
}

void Otobus::printSolution(int dist[]) const {
    cout << "Bolge Adi \t\t\t     Mesafe (km)" << endl<<endl;
    for (int i = 0; i < V4; i++)
        cout << ilceIsimleri[i] << " \t\t\t\t" << dist[i] << endl;
}


void Otobus::dijkstraAlgoritmasi() const {
    int dist[V4];
    bool sptSet[V4];

    for (int i = 0; i < V4; i++) {
        dist[i] = numeric_limits<int>::max();
        sptSet[i] = false;
    }

    dist[0] = 0;

    for (int count = 0; count < V4 - 1; count++) {
        int u = minDistance(dist, sptSet);

        sptSet[u] = true;

        for (int v = 0; v < V4; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != numeric_limits<int>::max() && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist);
}

int Otobus::getV4() const {
    return V4;
}

int Otobus::minDistance(int dist[], bool sptSet[]) const {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V4; v++)
        if (!sptSet[v] && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void Otobus::hesaplaVeYazdirMesafeSuresi() const {
    string kalkis = "Kavacik";
	string varis;
    cout << "Dikkat! Otobuslerin kalkis istasyonu Kavacik'ta bulunmaktadir." <<endl<<endl;
    cout << "Otobus ile gidebileceginiz duraklar: Bulgurlu, Nakkastepe, Kadikoy, Icadiye, Atasehir, Suadiye, Erenkoy, Cengelkoy" <<endl<<endl;
    cout << "Varis duragini seciniz: ";
    
    cin >> varis;
    
 
    int kalkisIndex = -1 ,varisIndex = -1; // ilk basta indeksleri -1'e esitliyoruz, gecerli bir indeks degeri olmadigini belirtmek icin
    for (int i = 0; i < V4; ++i) {
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
    int dist[V4];
    bool sptSet[V4];

    for (int i = 0; i < V4; i++) {
        dist[i] = numeric_limits<int>::max();
        sptSet[i] = false;
    }
	//dist baslangicta her bir dugumun kalkis noktasindan uzakligini saklar, sptSet ise belirli bir dugumun yol agacina dahil olup olmadigini belirtir
	
	
    dist[kalkisIndex] = 0; //baslangicta dist dizisi 0'a esitlenir

    for (int count = 0; count < V4 - 1; count++) { 
        int u = minDistance(dist, sptSet);

        sptSet[u] = true;

        for (int v = 0; v < V4; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != numeric_limits<int>::max() && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    
    int mesafe4 = dist[varisIndex];
    string onerilenHat;
    
    switch(mesafe4){
    	case 2:
    		onerilenHat = "500T";
    		break;
    	case 4:
			onerilenHat = "500T";
			break;
		case 5:
			onerilenHat = "14M";
			break;
		case 8:
			onerilenHat = "500T";
			break;
		case 7:
			onerilenHat	= "16D";
			break;
		case 11:
			onerilenHat = "16D";
			break;
		case 13:
			onerilenHat = "16D";
			break;
		case 15:
			onerilenHat = "14M";
			break;			
		default:
			cout<< "Baslangic Noktasindasiniz..";
			break;
	}

    cout << "\nKalkis: " << kalkis << "\nVaris: " << varis << "\nMesafe Suresi: " << dist[varisIndex] << " km" << endl;
    cout << "Onerilen Hat: " << onerilenHat << endl;
    cout << "Ucret: " << otobusUcret << " TL" <<endl;
    cout << "Tahmini Seyahat Suresi: " << dist[varisIndex]*6 << " dk" << endl<<endl;
    if (onerilenHat == "500T"){
    	cout << "Bu Hatla Gidilebilecek Duraklar: Kavacik, Bulgurlu, Nakkastepe, Icadiye."<<endl<<endl;
	}
	else if (onerilenHat == "14M"){
		cout << "Bu Hatla Gidilebilecek Duraklar: Kavacik, Bulgurlu, Cengelkoy, Kadikoy. "<<endl<<endl;
	}
	else {
		cout << "Bu Hatla Gidilebilecek Duraklar: Kavacik, Suadiye, Erenkoy, Atasehir."<<endl<<endl;		
	}
    
}


