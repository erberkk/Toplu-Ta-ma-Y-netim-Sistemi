#include "tramvay.h"

using namespace std;

Tramvay :: Tramvay (string _tasitId, string _hatIsmi, string _seferSaati, string _seferBitisSaati, string _ucret, string _konduktorBilgileri, string _kalkisDuragi, string _varisDuragi, string _durak1, string _durak2, string _durak3, string _durak4)
	: Tasit (_tasitId, _hatIsmi, _seferSaati, _seferBitisSaati, _ucret, _konduktorBilgileri,"Bagcilar", _varisDuragi, _durak1, _durak2, _durak3, _durak4) {
		
	dosyaAdi = "tramvay.txt";
    dosyaOkuTramvay();
    tramvayUcret = "17";
	
	int tempGraph[V2][V2] = 
							{{0, 2, 6, 10, 0, 0, 0, 0, 0},
                            {2, 0, 0, 5, 0, 0, 0, 2, 0},
                            {6, 0, 0, 8, 0, 0, 0, 0, 4},
                            {10, 5, 8, 0, 10, 15, 0, 0, 0},
                            {0, 0, 0, 10, 0, 6, 2, 0, 0},
                            {0, 0, 0, 15, 6, 0, 6, 7, 0},
                            {0, 0, 0, 0, 2, 6, 0, 0, 3},
                            {0, 2, 0, 0, 7, 0, 0, 0, 0},
                            {0, 0, 4, 0, 0, 0, 3, 0, 0}};

    for (int i = 0; i < V2; ++i) {
        for (int j = 0; j < V2; ++j) {
            graph[i][j] = tempGraph[i][j];
        }
    }
}
	
Tramvay:: ~Tramvay() {
	kaydetTramvay();
}	

void Tramvay::kaydetTramvay() {
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

void Tramvay::dosyaOkuTramvay() {
    ifstream dosya(dosyaAdi.c_str());

    if (dosya.is_open()) {
        string satir;
        while (getline(dosya, satir) && tasitSayisi < MAX_TASIT_BILGISI) {
            tasitBilgileri[tasitSayisi++] = satir;
        }
        dosya.close();
    }
}

string Tramvay :: gettramvayUcret () const {
return tramvayUcret;
}

void Tramvay::printSolution(int dist[]) const {
    cout << "Bolge Adi \t\t\t     Mesafe (km)" << endl<<endl;
    for (int i = 0; i < V2; i++)
        cout << ilceIsimleri[i] << " \t\t\t\t" << dist[i] << endl;
}

void Tramvay::dijkstraAlgoritmasi() const {
    int dist[V2];
    bool sptSet[V2];

    for (int i = 0; i < V2; i++) {
        dist[i] = numeric_limits<int>::max();
        sptSet[i] = false;
    }

    dist[0] = 0;

    for (int count = 0; count < V2 - 1; count++) {
        int u = minDistance(dist, sptSet);

        sptSet[u] = true;

        for (int v = 0; v < V2; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != numeric_limits<int>::max() && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist);
}

int Tramvay::getV2() const {
    return V2;
}

int Tramvay::minDistance(int dist[], bool sptSet[]) const {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V2; v++)
        if (!sptSet[v] && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void Tramvay::hesaplaVeYazdirMesafeSuresi() const {

    string kalkis = "Bagcilar";
	string varis;
    cout << "Dikkat! Tramvaylarin kalkis istasyonu Bagcilar'da bulunmaktadir." <<endl<<endl;
    cout << "Tramvay ile gidebileceginiz duraklar: Merter, Sisli, Uskudar, Fatih, Esenler, Beylikduzu, Sariyer, Kartal" <<endl<<endl;
    cout << "Varis duragini seciniz: ";
    
    cin >> varis;
    
 
    int kalkisIndex = -1 ,varisIndex = -1; // ilk basta indeksleri -1'e esitliyoruz, gecerli bir indeks degeri olmadigini belirtmek icin
    for (int i = 0; i < V2; ++i) {
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
    int dist[V2];
    bool sptSet[V2];

    for (int i = 0; i < V2; i++) {
        dist[i] = numeric_limits<int>::max();
        sptSet[i] = false;
    }
	//dist baslangicta her bir dugumun kalkis noktasindan uzakligini saklar, sptSet ise belirli bir dugumun yol agacina dahil olup olmadigini belirtir
	
	
    dist[kalkisIndex] = 0; //baslangicta dist dizisi 0'a esitlenir

    for (int count = 0; count < V2 - 1; count++) { 
        int u = minDistance(dist, sptSet);

        sptSet[u] = true;

        for (int v = 0; v < V2; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != numeric_limits<int>::max() && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    int mesafe2 = dist[varisIndex];
    string onerilenHat;
    
    switch(mesafe2){
    	case 2:
    		onerilenHat = "T1";
    		break;
    	case 4:
			onerilenHat = "T2";
			break;
		case 11:
			onerilenHat = "T1";
			break;
		case 7:
			onerilenHat = "T2";
			break;
		case 17:
			onerilenHat	= "T2";
			break;
		case 6:
			onerilenHat = "T3";
			break;
		case 10:
			onerilenHat = "T3";
			break;
		case 13:
			onerilenHat = "T3";
			break;			
		default:
			cout<< "Baslangic Noktasindasiniz..";
			break;
	}

    cout << "\nKalkis: " << kalkis << "\nVaris: " << varis << "\nMesafe Suresi: " << dist[varisIndex] << " km" << endl;
    cout << "Onerilen Hat: " << onerilenHat << endl;
    cout << "Ucret: " << tramvayUcret << "TL" <<endl;
    cout << "Tahmini Seyahat Suresi: " << dist[varisIndex]*2 << " dk" << endl<<endl;

    if (onerilenHat == "T1"){
    	cout << "Bu Hatla Gidilebilecek Duraklar: Bagcilar, Fatih, Merter, Sariyer."<<endl<<endl;
	}
	else if (onerilenHat == "T2"){
		cout << "Bu Hatla Gidilebilecek Duraklar: Bagcilar, Sariyer, Uskudar, Esenler . "<<endl<<endl;
	}
	else {
		cout << "Bu Hatla Gidilebilecek Duraklar: Bagcilar, Sisli, Beylikduzu, Kartal."<<endl<<endl;		
	}
    

}
