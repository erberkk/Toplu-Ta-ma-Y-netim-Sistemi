#include "metro.h"

using namespace std;

Metro :: Metro (string _tasitId, string _hatIsmi, string _seferSaati, string _seferBitisSaati, string _ucret, string _konduktorBilgileri, string _kalkisDuragi, string _varisDuragi, string _durak1, string _durak2, string _durak3, string _durak4)
	: Tasit (_tasitId, _hatIsmi, _seferSaati, _seferBitisSaati, _ucret, _konduktorBilgileri, "Uskudar" , _varisDuragi, _durak1, _durak2, _durak3, _durak4) {
		
	dosyaAdi = "metro.txt";
    dosyaOkuMetro();
    metroUcret ="13.5";
	
	int tempGraph[V1][V1] =
							{{0, 2, 6, 10, 0, 0, 0, 0, 0,0},
                            {2, 0, 0, 5, 0, 0, 0, 2, 0,0},
                            {6, 0, 0, 8, 0, 0, 0, 0, 4,5},
                            {10, 5, 8, 0, 10, 15, 0, 0, 0,0},
                            {0, 0, 0, 10, 0, 6, 2, 0, 0,2},
                            {0, 0, 0, 15, 6, 0, 6, 7, 0,0},
                            {0, 0, 0, 0, 2, 6, 0, 0, 3,0},
                            {0, 2, 0, 0, 7, 0, 0, 0, 0,1},
                            {0, 0, 4, 0, 0, 0, 3, 0, 0,0},
							{0, 0, 5, 0, 2, 0, 0, 1, 0,0}};

    for (int i = 0; i < V1; ++i) {
        for (int j = 0; j < V1; ++j) {
            graph[i][j] = tempGraph[i][j];
        }
    }    
}
	
Metro:: ~Metro() {
	kaydetMetro();
}	

void Metro::kaydetMetro() {
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

void Metro::dosyaOkuMetro() {
    ifstream dosya(dosyaAdi.c_str());

    if (dosya.is_open()) {
        string satir;
        while (getline(dosya, satir) && tasitSayisi < MAX_TASIT_BILGISI) {
            tasitBilgileri[tasitSayisi++] = satir;
        }
        dosya.close();
    }
}

string Metro::getmetroUcreti()const{
	
return metroUcret;

}


void Metro::printSolution(int dist[]) const {
    cout << "Bolge Adi \t\t\t     Mesafe (km)" << endl<<endl;
    for (int i = 0; i < V1; i++)
        cout << ilceIsimleri[i] << " \t\t\t\t" << dist[i] << endl;
}


void Metro::dijkstraAlgoritmasi() const {
    int dist[V1]; //her bir bolgeye olan min mesafeyi tutuyo
    bool sptSet[V1]; //secilen bolge seti

    for (int i = 0; i < V1; i++) {
        dist[i] = numeric_limits<int>::max(); // sonsuz mesafe yap
        sptSet[i] = false;  // henuz secilmedigi icin false olarak set et
    }

    dist[0] = 0; // baslangic bolgesine olan mesafeyi 0 yap

    for (int count = 0; count < V1 - 1; count++) {
        int u = minDistance(dist, sptSet); // min mesafeye sahip bolgeyi sec

        sptSet[u] = true; // artik secildigi icin bolgeyi ekle

        for (int v = 0; v < V1; v++) { //secilen bolgeden diger yerlere mesafeyi guncelle
            if (!sptSet[v] && graph[u][v] && dist[u] != numeric_limits<int>::max() && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist);
}

int Metro::getV1() const {
    return V1;
}

int Metro::minDistance(int dist[], bool sptSet[]) const {
    int min = INT_MAX, min_index;
	// henuz secilmemis bolge icinde min mesafeye sahip bolgeyi bul
    for (int v = 0; v < V1; v++)
        if (!sptSet[v] && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index; // min mesafeye sahip olan indexi dondur
}

void Metro::hesaplaVeYazdirMesafeSuresi() const {
    string kalkis = "Uskudar";
	string varis;
    cout << "Dikkat! Metro kalkis istasyonumuz Uskudar'da bulunmaktadir." <<endl<<endl;
    cout << "Metro ile gidebileceginiz duraklar: Kadikoy, Yildiz, Yenikapi, Kucukyali, Bostanci, Haciosman, Acibadem, Bakirkoy" <<endl<<endl;
    cout << "Varis duragini seciniz: ";
    
    cin >> varis;
    
 
    int kalkisIndex = -1 ,varisIndex = -1; // ilk basta indeksleri -1'e esitliyoruz, gecerli bir indeks degeri olmadigini belirtmek icin
    for (int i = 0; i < V1; ++i) {
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
    
    int dist[V1];
    bool sptSet[V1];

    for (int i = 0; i < V1; i++) {
        dist[i] = numeric_limits<int>::max();
        sptSet[i] = false;
    }
	//dist baslangicta her bir dugumun kalkis noktasindan uzakligini saklar, sptSet ise belirli bir dugumun yol agacina dahil olup olmadigini belirtir
	
	
    dist[kalkisIndex] = 0; //baslangicta dist dizisi 0'a esitlenir

    for (int count = 0; count < V1 - 1; count++) { 
        int u = minDistance(dist, sptSet);

        sptSet[u] = true;

        for (int v = 0; v < V1; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != numeric_limits<int>::max() && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    int mesafe = dist[varisIndex];
    string onerilenHat;
    
    switch(mesafe){
    	case 2:
    		onerilenHat = "M1";
    		break;
    	case 4:
			onerilenHat = "M3";
			break;
		case 11:
			onerilenHat = "M2";
			break;
		case 7:
			onerilenHat = "M1";
			break;
		case 17:
			onerilenHat	= "M2";
			break;
		case 6:
			onerilenHat = "M3";
			break;
		case 10:
			onerilenHat = "M2";
			break;
		case 13:
			onerilenHat = "M3";
			break;			
		default:
			cout<< "Baslangic Noktasindasiniz..";
			break;
	}

    cout << "\nKalkis: " << kalkis << "\nVaris: " << varis << "\nMesafe: " << dist[varisIndex] << " km" << endl;
    cout << "Onerilen Hat: " << onerilenHat << endl;
    cout << "Ucret: " << metroUcret << "TL"  <<endl;
    cout << "Tahmini Seyahat Suresi: " << dist[varisIndex] * 1.5 << " dk" << endl<<endl;

    if (onerilenHat == "M1"){
    	cout << "Bu Hatla Gidilebilecek Duraklar: Uskudar, Kadikoy, Yildiz, Yenikapi ."<<endl<<endl;
	}
	else if (onerilenHat == "M2"){
		cout << "Bu Hatla Gidilebilecek Duraklar: Uskudar, Kucukyali, Bostanci, Bakirkoy. "<<endl<<endl;
	}
	else {
		cout << "Bu Hatla Gidilebilecek Duraklar: Uskudar, Acibadem, Haciosman , Yildiz."<<endl<<endl;		
	}
    
}



