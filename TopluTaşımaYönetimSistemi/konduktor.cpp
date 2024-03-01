#include "konduktor.h"
#include "tasit.h"
#include <fstream>
#include <limits>
using namespace std;

Konduktor::Konduktor(string _konduktor, string _baslangicSaat, string _bitisSaat){
    
	konduktor = _konduktor;
    baslangicSaat = _baslangicSaat;
    bitisSaat = _bitisSaat;
    
	dosyaAdi = "konduktor.txt";
    konduktorSayisi = 0;
    dosyaOku();
}

Konduktor::~Konduktor() {
    kaydet();
}

void Konduktor :: setkonduktor(string _konduktor){
	konduktor = _konduktor;
}
	
string Konduktor :: getkonduktor()const{
	return konduktor;
}

void Konduktor :: setbaslangicSaat(string _baslangicSaat){
	baslangicSaat = _baslangicSaat;
}

string Konduktor :: getbaslangicSaat()const{
	return baslangicSaat;
}

void Konduktor :: setbitisSaat(string _bitisSaat){
	bitisSaat = _bitisSaat;
}

string Konduktor :: getbitisSaat()const{
	return bitisSaat;
}

void Konduktor::kaydet() {
    ofstream dosya(dosyaAdi.c_str());

    if (dosya.is_open()) {
        for (int i = 0; i < konduktorSayisi; ++i) {
            dosya << konduktorBilgileri[i] << "\n";
        }
        dosya.close();
    }
    else {
        cerr << "Dosya acilamadi: " << dosyaAdi << endl;
    }
}

void Konduktor::dosyaOku() {
    ifstream dosya(dosyaAdi.c_str());

    if (dosya.is_open()) {
        string satir;
        while (getline(dosya, satir) && konduktorSayisi < MAX_KONDUKTOR_BILGISI) {
            konduktorBilgileri[konduktorSayisi++] = satir;
        }
        dosya.close();
    }
}

void Konduktor::konduktorGoster() const {
    cout << "Konduktor Bilgileri:\n"<<endl;
    for (int i = 0; i < konduktorSayisi; ++i) {
        cout << i + 1 << ". " << konduktorBilgileri[i] << endl;
    }
    cout << " " << endl;
}

bool Konduktor::zamanCakismasi(const Konduktor& s1, const Konduktor& s2) {
    int s1_baslangic = stoi(s1.baslangicSaat);
    int s1_bitis = stoi(s1.bitisSaat);
    int s2_baslangic = stoi(s2.baslangicSaat);
    int s2_bitis = stoi(s2.bitisSaat);

    return (s1_baslangic < s2_bitis) && (s2_baslangic < s1_bitis);
}


bool Konduktor::soforUygunMu(const vector<Konduktor>& shiftler, string konduktor, string baslangicSaat, string bitisSaat) {
    for (const Konduktor& shift : shiftler) {
        if (zamanCakismasi(shift, {" ", baslangicSaat, bitisSaat})) {
            cout << "Cakisma tespit edildi! Sofor uygun degil.\n";
            return false;
        }
    }
    cout << "Cakisma tespit edilmedi! Sofor uygun.\n";
    return true;
}

void Konduktor::konduktorEkle() {
    vector<Konduktor> shiftler;

    // Örnek shift'leri ekleyelim
    shiftler.push_back(Konduktor{"Ahmet Kara", "08.00", "12.00"});
    shiftler.push_back(Konduktor{"Mehmet Yildiz", "14.00", "18.00"});

    // Yeni bir shift ekleyelim ve þoförün mevcut shift'leriyle çakýþýp çakýþmadýðýný kontrol edelim
    string yeniKonduktor, yeniBaslangicSaat, yeniBitisSaat;

    cout << "Konduktor icin calisma bilgilerini girin:\n";

    cout << "Sofor Ismi: ";
    getline(cin, yeniKonduktor);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Sefer Baslangic saati: ";
    getline(cin, yeniBaslangicSaat);

    cout << "Sefer Bitis saati: ";
    getline(cin, yeniBitisSaat);

    if (soforUygunMu(shiftler, yeniKonduktor, yeniBaslangicSaat, yeniBitisSaat)) {
        // Yeni shift ekleyebiliriz
        shiftler.push_back({yeniKonduktor, yeniBaslangicSaat, yeniBitisSaat});
        cout << "Shift basariyla eklendi.\n";

        // Update konduktorBilgileri array
        konduktorBilgileri[konduktorSayisi++] = yeniKonduktor + " " + yeniBaslangicSaat + " " + yeniBitisSaat;

        // Save to file
        kaydet();
    } else {
        cout << "Soforun mevcut shift'leriyle cakisan bir zaman araligi sectiniz. Baska bir zaman araligi deneyin.\n";
    }
}



