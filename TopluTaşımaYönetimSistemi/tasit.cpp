#include "tasit.h"
#include "tramvay.h"
#include "metro.h"
#include "vapur.h"
#include "otobus.h"


using namespace std;

Tasit::Tasit(string _tasitId, string _hatIsmi, string _seferSaati, string _seferBitisSaati, string _ucret, string _konduktorBilgileri, string _kalkisDuragi, string _varisDuragi, string _durak1, string _durak2, string _durak3, string _durak4) {
    
    settasitId(tasitId);
    sethatIsmi(hatIsmi);
    setseferSaati(seferSaati);
    setseferBitisSaati(seferBitisSaati);
    setucret(ucret);
    setkonduktorBilgileri(konduktorBilgileri);
    setkalkisDuragi(kalkisDuragi);
    setvarisDuragi(varisDuragi);
    
    setdurak1 (durak1);
	setdurak2 (durak2);
	setdurak3 (durak3);
	setdurak4 (durak4);
    
    
	dosyaAdi = "tasit_bilgileri.txt";
    tasitSayisi = 0;
    dosyaOku();
    
    
}

Tasit::~Tasit() {
    kaydet();
}


ostream& operator<<(ostream& os, const Tasit& tasit) {
    os << "Tasit ID: " << tasit.gettasitId() << "\n";
    os << "Hat Ismi: " << tasit.gethatIsmi() << "\n";
    os << "Sefer Saati: " << tasit.getseferSaati() << "\n";
    os << "Sefer Bitis Saati: " << tasit.getseferBitisSaati() << "\n";
    os << "Ucret" << tasit.getucret() << "\n";
    os << "Konduktor Bilgileri: " << tasit.getkonduktorBilgileri() << "\n";
    os << "Kalkis Duragi: " << tasit.getkalkisDuragi() << "\n";
    os << "Varis Duragi: " << tasit.getvarisDuragi() << "\n";
    os << "Durak1: " << tasit.getdurak1() << "\n";
    os << "Durak2: " << tasit.getdurak2() << "\n";
    os << "Durak3: " << tasit.getdurak3() << "\n";
    os << "Durak4: " << tasit.getdurak4() << "\n";
    return os;
}

istream& operator>>(istream& is, Tasit& tasit) {
    cout << "Tasit ID: ";
    is >> tasit.tasitId;
    
    cout << "Hat Ismi: ";
    is >> tasit.hatIsmi;
    
    cout << "Sefer Saati: ";
    is >> tasit.seferSaati;
    
    cout << "Ucret: ";
    is >> tasit.ucret;
    
    cout << "Konduktor Bilgileri: ";
    is >> tasit.konduktorBilgileri;
    
    cout << "Kalkis Duragi: ";
    is >> tasit.konduktorBilgileri;
    
    cout << "Varis Duragi: ";
    is >> tasit.varisDuragi;
    
    cout << "Durak1: ";
    is >> tasit.durak1;
    
    cout << "Durak2: ";
    is >> tasit.durak2;
    
    cout << "Durak3: ";
    is >> tasit.durak3;
    
    cout << "Durak4: ";
    is >> tasit.durak4;
    return is;
}

void Tasit :: settasitId(string _tasitId){
	tasitId = _tasitId;
}

void Tasit :: sethatIsmi(string _hatIsmi){
	hatIsmi = _hatIsmi;
}

void Tasit :: setseferSaati(string _seferSaati){
	seferSaati = _seferSaati;
}

void Tasit :: setseferBitisSaati(string _seferBitisSaati){
	seferBitisSaati = _seferBitisSaati;
}

void Tasit :: setucret(string _ucret){
	ucret = _ucret;
}

void Tasit :: setkonduktorBilgileri(string _konduktorBilgileri){
	konduktorBilgileri = _konduktorBilgileri;
}

void Tasit :: setkalkisDuragi(string _kalkisDuragi){
	kalkisDuragi = _kalkisDuragi;
}

void Tasit :: setvarisDuragi(string _varisDuragi){
	varisDuragi = _varisDuragi;
}

void Tasit :: setdurak1 (string _durak1){
		durak1 = _durak1;
	}
	
void Tasit :: setdurak2 (string _durak2){
		durak2 = _durak2;
	}
	
void Tasit :: setdurak3 (string _durak3){
		durak3 = _durak3;
	}
	
void Tasit :: setdurak4 (string _durak4){
		durak4 = _durak4;
	}
	
string Tasit :: getkonduktorBilgileri()const{
	return konduktorBilgileri;
}

string Tasit :: getkalkisDuragi()const{
	return kalkisDuragi;
}

string Tasit :: getvarisDuragi()const{
	return varisDuragi;
}

string Tasit :: getdurak1() const {
	return durak1;
}
	
string Tasit :: getdurak2() const {
	return durak2;
}
	
string Tasit :: getdurak3() const {
	return durak3;
}
	
string Tasit :: getdurak4() const {
	return durak4;
}

string Tasit :: gettasitId()const{
	return tasitId;
}

string Tasit :: gethatIsmi()const{
	return hatIsmi;
}

string Tasit :: getseferSaati()const{
	return seferSaati;
}

string Tasit :: getseferBitisSaati()const{
	return seferBitisSaati;
}

string Tasit :: getucret()const{
	return ucret;
}


int Tasit::getTasitSayisi() const {
    return tasitSayisi;
}

void Tasit::kaydet() {
    ofstream dosya(dosyaAdi.c_str()); //ofstream nesnesi olustur dosyaAdindaki dosyayi ac

    if (dosya.is_open()) { //dosyanin acilip acilmadigini kontrol et
        for (int i = 0; i < tasitSayisi; ++i) { //tasitBilgileri dizisindeki her bir elemani dosyaya yaz
            dosya << tasitBilgileri[i] << "\n";
        }
        dosya.close();
    }
    else {
        cerr << "Dosya acilamadi: " << dosyaAdi << std::endl;
    }
}

void Tasit::dosyaOku() {
    ifstream dosya(dosyaAdi.c_str()); //ifstream nesnesi olustur dosyaAdindaki dosyayi ac

    if (dosya.is_open()) {
        string satir;
        while (getline(dosya, satir) && tasitSayisi < MAX_TASIT_BILGISI) { //dosyayi satir satir okur ve tasitBilgilerine ekler, tasit sayisi arttirilir
            tasitBilgileri[tasitSayisi++] = satir;
        }
        dosya.close();
    }
}

void Tasit::bilgileriGoster() const {
    cout << "Tasit Bilgileri:\n"<<endl;
    cout<<  "   ID - HAT -  KONDUKTOR  -          HAT DURAK BILGILERI          - ILK DURAK - SON DURAK - BASLANGIC - BITIS - UCRET" <<endl<<endl;
    for (int i = 0; i < tasitSayisi; ++i) { //her tasitBilgileri elemanini yazdirir
        cout << i + 1 << ". " << tasitBilgileri[i] << endl;
    }
    cout << " " << endl;
}

bool Tasit::isValidTimeFormat(const string& timeStr) {
    stringstream ss(timeStr);
    int hours, minutes;
    char colon;

    if (!(ss >> hours) || !(ss >> colon) || colon != ':' || !(ss >> minutes) || !ss.eof()) {
        cout << "HATA: Saat bicimi gecersiz. Lutfen HH:MM biciminde girin." << endl;
        return false;
    }

    if (hours < 0 || hours > 23 || minutes < 0 || minutes > 59) {
        cout << "HATA: Saat veya dakika degeri gecersiz." << endl;
        return false;
    }

    return true;
}

bool Tasit::kontrolKonduktorVeSaat(const string& konduktorBilgisi, const string& seferSaati, const string& seferBitisSaati) const {
    for (int i = 0; i < tasitSayisi; ++i) {
        size_t found = tasitBilgileri[i].find(konduktorBilgisi); //konduktor bilgilerini tasitBilgileri[i] icinde ara
        if (found != string::npos) { //sefer baslangic ve bitis saatini mevcut seferlerde kontrol et
            size_t saat1Pos = tasitBilgileri[i].find(seferSaati);
            size_t saat2Pos = tasitBilgileri[i].find(seferBitisSaati);
            
            if ((saat1Pos != string::npos && saat1Pos >= string::npos && saat1Pos <= saat2Pos) || //eger belirtilen saatlerde sefer varsa hata ver
                (saat2Pos != string::npos && saat2Pos >= string::npos && saat2Pos >= saat1Pos)) {
                cout << "HATA: Bu konduktorun belirtilen saatler arasinda baska bir seferi bulunmaktadir." << endl;
                return false;
            }
        }
    }
    return true;
}

bool Tasit::konduktorSaatAraligiKontrol(const string& konduktorBilgisi, const string& seferSaati, const string& seferBitisSaati) const {
    for (int i = 0; i < tasitSayisi; ++i) {
        size_t found = tasitBilgileri[i].find(konduktorBilgisi);
        if (found != string::npos) {
            size_t saat1Pos = tasitBilgileri[i].find(seferSaati);
            size_t saat2Pos = tasitBilgileri[i].find(seferBitisSaati);
            
            if ((saat1Pos != string::npos && saat1Pos >= string::npos && saat1Pos <= saat2Pos) ||
                (saat2Pos != string::npos && saat2Pos >= string::npos && saat2Pos >= saat1Pos)) {
                cout << "HATA: Sefer Kaydedilemedi. Bu konduktorun belirtilen saat araliginda zaten bir seferi bulunmaktadir." << endl;
                return false;
            }
            
            if ((saat1Pos >= string::npos && saat1Pos <= string::npos) ||
                (saat2Pos >= string::npos && saat2Pos <= string::npos)) {
                cout << "HATA: Sefer Kaydedilemedi. Bu konduktorun belirtilen saat araliginda zaten bir seferi bulunmaktadir." << endl;
                return false;
            }
        }
    }
    return true;
}

void Tasit::tasitEkle() {
    int tercih;
    cout << "Sefer Ekleme Ekranina Hosgeldiniz." << endl;
    cout << " " << endl;
    cout << "1-Metro" << endl;
    cout << "2-Tramvay" << endl;
    cout << "3-Otobus" << endl;
    cout << "4-Vapur" << endl;
    cout << "Sefer Eklemek Istediginiz Tasit Turunu Seciniz: ";
    cin >> tercih;
    system("cls");
    if (tasitSayisi < MAX_TASIT_BILGISI) {

        cout << "Tasit ID: ";
        cin.ignore();
        getline(cin, tasitId);

        cout << "Hat Ismi: ";
        getline(cin, hatIsmi);

        cout << "Konduktor Bilgileri: ";
        getline(cin, konduktorBilgileri);
        
        cout << "Hattin duraklarini yaziniz: " << endl;
        cout << "1. ";
        getline(cin, durak1);

        cout << "2. ";
        getline(cin, durak2);

        cout << "3. ";
        getline(cin, durak3);

        cout << "4. ";
        getline(cin, durak4);

        kalkisDuragi = durak1;
        varisDuragi = durak4;

        cout << "Sefer Saati (HH:MM) : ";
    	getline(cin, seferSaati);
  		if (!isValidTimeFormat(seferSaati)) {
        	return;
    	}

    	cout << "Sefer Bitis Saati (HH:MM) : ";
    	getline(cin, seferBitisSaati);
    	if (!isValidTimeFormat(seferBitisSaati)) {
        	return;
    	}
        
        if (!kontrolKonduktorVeSaat(konduktorBilgileri, seferSaati, seferBitisSaati) ||
        !konduktorSaatAraligiKontrol(konduktorBilgileri, seferSaati, seferBitisSaati)) {
        return;
    }
        
        if (tercih == 1) {
            Metro metro;
            ucret = metro.getmetroUcreti();
        }
        else if (tercih == 2) {
            Tramvay tramvay;
            ucret = tramvay.gettramvayUcret();
        }
        else if (tercih == 3) {
            Otobus otobus;
            ucret = otobus.getotobusUcret();
        }
        else if (tercih == 4) {
            Vapur vapur;
            ucret = vapur.getvapurUcret();
        }
        else {
            cout << "HATALI GIRIS" << endl;
            return; 
        }

        string tasitBilgisi = tasitId + " | " + hatIsmi + " | " + konduktorBilgileri + " || " + durak1 + " - " + durak2 + " - " + durak3 + " - " + durak4 + " || " + kalkisDuragi + " | " + varisDuragi + " | " + seferSaati + " | " + seferBitisSaati + " | " + ucret + " TL";

        tasitBilgileri[tasitSayisi++] = tasitBilgisi;

        kaydet();
        cout << "Tasit bilgisi eklendi." << endl;

    }
    else {
        cout << "Maksimum Tasit bilgisi sayisina ulasildi." << endl;
    }
}


void Tasit::tasitGuncelle(int satirNo) {
    if (satirNo >= 1 && satirNo <= tasitSayisi) {
    	    	
    			cout << "Tasit ID: ";
    			cin.ignore();
        		getline(cin, tasitId);
        
        		cout << "Hat Ismi: ";
        		getline(cin, hatIsmi);
		
				cout << "Konduktor Bilgileri: ";
        		getline(cin, konduktorBilgileri);
    	
				cout << "1. Durak: ";
				getline (cin, durak1);
		
				cout << "2. Durak: ";
				getline (cin, durak2);
		
				cout << "3. Durak: ";
				getline (cin, durak3);
			
				cout << "4. Durak: ";
				getline (cin, durak4);
		
			     
       			kalkisDuragi = durak1;
 
        		varisDuragi = durak4;
		
        
        		cout << "Sefer Saati: ";
        		getline(cin, seferSaati);
        
				 cout << "Sefer Bitis Saati: ";
       			 getline(cin, seferBitisSaati);
        
        		cout << "Ucret: ";
       		 	getline(cin, ucret);
        
		string tasitBilgisi = tasitId + " | " + hatIsmi + " | " + konduktorBilgileri + " || " + durak1 + " - " + durak2 + " - " + durak3 + " - " + durak4 + " || " + kalkisDuragi + " | " + varisDuragi + " | " + seferSaati + " | " + seferBitisSaati + " | " + ucret + " TL";
        tasitBilgileri[satirNo - 1] = tasitBilgisi;

        kaydet();
        cout << "Tasit Bilgisi Guncellendi." << endl<<endl;
    }
    else {
        cout << "Gecersiz Satir Numarasi." << endl;
    }
}

void Tasit::tasitSil(int satirNo) {
    if (satirNo >= 1 && satirNo <= tasitSayisi) {
        for (int i = satirNo - 1; i < tasitSayisi - 1; ++i) {
            tasitBilgileri[i] = tasitBilgileri[i + 1];
        }
        --tasitSayisi;

        kaydet();

        cout << "Tasit bilgileri basariyla silindi."<<endl<<endl;
    }
    else {
        cerr << "Gecersiz satir numarasi. Lutfen tekrar deneyin.\n";
    }
}

void Tasit::tasitAra(const string& kalkisDuragi, const string& varisDuragi) const {
    bool bulundu = false;

    for (int i = 0; i < tasitSayisi; ++i) {
        // Kalkýþ ve varýþ duraklarýna göre eþleþme kontrolü
        if (tasitBilgileri[i].find(kalkisDuragi) != string::npos &&
            tasitBilgileri[i].find(varisDuragi) != string::npos) {
            cout << tasitBilgileri[i] << endl;
            bulundu = true;
        }
    }

    if (!bulundu) {
        cout << "Aranan tasit bulunamadi.\n";
    }
}


double Tasit::stringToDouble(const std::string& str) const {
    std::istringstream iss(str);
    double result;
    iss >> result;
    if (iss.fail()) {
        std::cerr << "Hata: " << str << " double'a çevrilemedi." << std::endl;
    }
    return result;
}

void Tasit::ortalamaUcretHesapla(double ortUcret) {
	Metro metro;
	Tramvay tramvay;
	Vapur vapur;
	Otobus otobus;
    double ucret1 =  stringToDouble(metro.getmetroUcreti());
    double ucret2 =  stringToDouble(tramvay.gettramvayUcret());
    double ucret3 =  stringToDouble(vapur.getvapurUcret());
    double ucret4 =	 stringToDouble(otobus.getotobusUcret());
	ortUcret = (ucret1 + ucret2 + ucret3 + ucret4)/4.0;
	
	cout<<"Tasitlarin Ortalama Ucreti (Double) ="<<ortUcret<<endl;
}

void Tasit :: ortalamaUcretHesapla (int ortUcret){
	Metro metro;
	Tramvay tramvay;
	Vapur vapur;
	Otobus otobus;
    double ucret1 =  stringToDouble(metro.getmetroUcreti());
    double ucret2 =  stringToDouble(tramvay.gettramvayUcret());
    double ucret3 =  stringToDouble(vapur.getvapurUcret());
    double ucret4 =	 stringToDouble(otobus.getotobusUcret());
	ortUcret = (ucret1 + ucret2 + ucret3 + ucret4)/4;
	
	cout<<"Tasitlarin Ortalama Ucreti (Int)="<<ortUcret<<endl;	
}

void Tasit::printSolution(int dist[]) const {
    cout << "Ilce \t Mesafe" << endl;
    for (int i = 0; i < V; i++)
        cout << ilceIsimleri[i] << " \t\t\t\t" << dist[i] << endl;
}

void Tasit::dijkstraAlgoritmasi() const {
    int dist[V];
    bool sptSet[V];

    for (int i = 0; i < V; i++) {
        dist[i] = numeric_limits<int>::max();
        sptSet[i] = false;
    }

    dist[0] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);

        sptSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != numeric_limits<int>::max() && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist);
}

int Tasit::minDistance(int dist[], bool sptSet[]) const {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (!sptSet[v] && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

int Tasit::getV() const {
    return V;
}





