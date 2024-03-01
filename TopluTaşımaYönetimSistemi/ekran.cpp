#include "ekran.h"
#include "tasit.h" 
#include "tramvay.h"
#include "metro.h"
#include "vapur.h"
#include "otobus.h"
#include "kullanici.h"
#include "konduktor.h"

#include <chrono>
#include <ctime>

using namespace std;
Tramvay tramvay;
Metro metro;
Vapur vapur;
Otobus otobus;
Tasit tasit;

auto now = chrono::system_clock::now();
time_t currentTime =chrono::system_clock::to_time_t(now);

void Ekran::girisEkrani() {
    int tercih;
    cout << "***Toplu Tasima Yonetim Sistemine Hosgeldiniz***" << endl;
        cout << "Guncel Zaman: " << ctime(&currentTime) <<endl;
    cout << " " << endl;
    cout << "1-Admin Paneli" << endl;
    cout << "2-Kullanici Paneli" << endl;
    cout << "3-Cikis" << endl;
    cout << "Lutfen yapmak istediginiz islemi seciniz: " << endl;
    cin >> tercih;
    system("cls");
    girisEkraniTercih(tercih);
}

int Ekran::girisEkraniTercih(int tercih) {
    switch (tercih) {
        case 1:
            adminEkrani();
            break;
        case 2:
            kullaniciEkrani();
            break;
        case 3:
        	cout << "Program sonlandirildi.";
            return 0;
        default:
            girisEkrani();
            break;
    }
}

void Ekran::adminEkrani() {
    /*
    int sifre;
    string kullaniciAdi;
    cout<<"Kullanici Adi: ";
    cin>>kullaniciAdi;
    cout<<"\nSifre: ";
    cin>>sifre; 
    if ( sifre == 123456 && kullaniciAdi == "admin"){ */
    	cout << "Admin Ekranina Hosgeldiniz." << endl;
    cout << " " << endl;
    cout << "1-Sefer Bilgileri" << endl;
    cout << "2-Sefer Ekleme" << endl;
    cout << "3-Sefer Duzenleme" << endl;
    cout << "4-Sefer Silme" << endl;
    cout << "5-Ucretlendirme Bilgileri"<<endl;
    cout << " " << endl;
    int tercih;
    cout << "ISLEM: ";
    cin >> tercih;
    system("cls");
    switch (tercih) {
        case 1:
            seferBilgileri();
            break;
        case 2:
            seferEkleme();
            break;
        case 3:
            seferDuzenleme();
            break;
        case 4:
            seferSilme();
            break;
        case 5: 
			ucretBilgileri(); 
			break;
        default:
            girisEkrani();
    }
	}
	 
	/* else {
		cout<<"Hatali Sifre veya Kullanici Adi!!"<<endl;
		girisEkrani();
	}
	
}*/
    

void Ekran::kullaniciEkrani() {
    int tercih1, tercih2;
    cout << "Kullanici Ekranina Hosgeldiniz." << endl<<endl;

    cout << "1- Tasit Bilgileri"<<endl;
    cout << "2- Ucret Hesaplama  "<<endl;
    cout << "3- Ne ile Ne Surede Giderim?" <<endl;
    cout << "4- Sefer Ara " << endl << endl;
    cout << "Yapmak Istediginiz Islem: ";
    cin >> tercih1;
    system ("cls");
    if (tercih1 == 1){
    cout << "1-Metro" << endl;
    cout << "2-Tramvay" << endl;
    cout << "3-Otobus" << endl;
    cout << "4-Vapur" << endl;
    cout << "Kullanmak Istediginiz Tasit Turunu Seciniz: ";
    cin >> tercih2;
    system("cls");
    switch (tercih2) {
        case 1: 	
			metroBilgileri(); 
		break;
        case 2:
			tramvayBilgileri();
			break;
		case 3:
			otobusBilgileri();
			break;
		case 4:
			vapurBilgileri();
			break;
		default:
			girisEkrani();				
	}
	}
    else if (tercih1 == 2){
    	ucretHesapla();
	}
	else if (tercih1 == 3){
	cout << "Hangi Tasiti Tercih Edeceksiniz?" <<endl;
	cout << "1-Metro" << endl;
    cout << "2-Tramvay" << endl;
    cout << "3-Otobus" << endl;
    cout << "4-Vapur" << endl;
    cout << "Kullanacaginiz Tasit Turunu Seciniz: ";
    cin >> tercih2;
    system("cls");
    switch (tercih2) {
        case 1: 	
			metro.hesaplaVeYazdirMesafeSuresi(); 
		break;
        case 2:
			tramvay.hesaplaVeYazdirMesafeSuresi();
			break;
		case 3:
			otobus.hesaplaVeYazdirMesafeSuresi();
			break;
		case 4:
			vapur.hesaplaVeYazdirMesafeSuresi();
			break;
		default:
			girisEkrani();				
	}
	}
	else if(tercih1 == 4){
		seferAra();
	}
	else {
		cout<<"Hatali Secenek.."<<endl;
		kullaniciEkrani();
	}
	int x;
    cout << "\nAna Menuye Donmek Icin 1'i Tuslayiniz: ";
    cin >> x;
    system ("cls");
    if(x=1){
    	girisEkrani();
	} 
}


void Ekran::seferBilgileri() {
		int tercih;
	cout << "Sefer Bilgileri Ekranina Hosgeldiniz." << endl;
	cout << " " << endl;
    cout << "1-Metro" << endl;
    cout << "2-Tramvay" << endl;
    cout << "3-Otobus" << endl;
    cout << "4-Vapur" << endl;
    cout << "Sefer Bilgilerini Gormek Istediginiz Tasit Turunu Seciniz: ";
    cin >> tercih;
    system("cls");
    switch (tercih) {
        case 1: 
        	int x;
			cout << "\t\t ---METRO ICIN SECENEKLER---" <<endl;
			cout << "1- Hat Bilgilerini Goruntuleme" << endl;
			cout << "2- Metro Duraklari Arasi Uzaklik(Dijkstra Algoritmasi) Goruntuleme "<<endl<<endl;
			cout << "SECIMINIZ: ";
			cin >> x;
			if(x == 1){
				metro.bilgileriGoster();
			}
			else if(x == 2){
				metro.dijkstraAlgoritmasi();
			}
			else{
				cout << "Gecersiz bir deger girdiniz." << endl;
			}
			
		/*	metro.tasitYolculukSuresiHesapla("Kadikoy", "Besiktas"); */
		break;
		
        case 2:
		int y;
			cout << "\t\t ---TRAMVAY ICIN SECENEKLER---" <<endl;
			cout << "1- Hat Bilgilerini Goruntuleme" << endl;
			cout << "2- Tramvay Duraklari Arasi Uzaklik(Dijkstra Algoritmasi) Goruntuleme "<<endl<<endl;
			cout << "SECIMINIZ: ";
			cin >> y;
			if(y == 1){
				tramvay.bilgileriGoster();
			}
			else if(y == 2){
				tramvay.dijkstraAlgoritmasi();
			}
			else{
				cout << "Gecersiz bir deger girdiniz." << endl;
			}
			break;
			
		case 3:
			int z;
			cout << "\t\t ---OTOBUS ICIN SECENEKLER---" <<endl;
			cout << "1- Hat Bilgilerini Goruntuleme" << endl;
			cout << "2- Otobus Duraklari Arasi Uzaklik(Dijkstra Algoritmasi) Goruntuleme "<<endl<<endl;
			cout << "SECIMINIZ: ";
			cin >> z;
			if(z == 1){
				otobus.bilgileriGoster();
			}
			else if(z == 2){
				otobus.dijkstraAlgoritmasi();
			}
			else{
				cout << "Gecersiz bir deger girdiniz." << endl;
			}
			break;
			
		case 4:
			int w;
			cout << "\t\t ---VAPUR ICIN SECENEKLER---" <<endl;
			cout << "1- Hat Bilgilerini Goruntuleme" << endl;
			cout << "2- Vapur Duraklari Arasi Uzaklik(Dijkstra Algoritmasi) Goruntuleme "<<endl<<endl;
			cout << "SECIMINIZ: ";
			cin >> w;
			if(w == 1){
				vapur.bilgileriGoster();
			}
			else if(w == 2){
				vapur.dijkstraAlgoritmasi();
			}
			else{
				cout << "Gecersiz bir deger girdiniz." << endl;
			}
			break;
			
		default:
			girisEkrani();				
	}
	
    int x;
    cout << "\nAna Menuye Donmek Icin 1'i Tuslayiniz: ";
    cin >> x;
    system ("cls");
    if(x=1){
    	girisEkrani();
	} 
}

void Ekran::seferEkleme() {

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
    switch (tercih) {
        case 1: 	
			metro.tasitEkle();
		break;
        case 2:
			tramvay.tasitEkle();
			break;
		case 3:
			otobus.tasitEkle();
			break;
		case 4:
			vapur.tasitEkle();
			break;
		default:
			girisEkrani();				
	}

	int x;
    cout << "\nAna Menuye Donmek Icin 1'i Tuslayiniz: ";
    cin >> x;
    system ("cls");
    if(x=1){
    	girisEkrani();
	} 
}

void Ekran::seferDuzenleme() {
	
	int tercih;
	cout << "Sefer Duzenleme Ekranina Hosgeldiniz." << endl;
	cout << " " << endl;
    cout << "1-Metro" << endl;
    cout << "2-Tramvay" << endl;
    cout << "3-Otobus" << endl;
    cout << "4-Vapur" << endl;
    cout << "Seferini Duzenlemek Istediginiz Tasit Turunu Seciniz: ";
    cin >> tercih;
    system("cls");
    switch (tercih) {
        case 1: 	
			metro.bilgileriGoster();
			cout << " " <<endl;
			int satirNo;
			cout << "Degistirmek istediginiz satir numarasini giriniz: ";
			cin >> satirNo;
    		metro.tasitGuncelle(satirNo);
		break;
        case 2:
			tramvay.bilgileriGoster();
			cout << " " <<endl;
			int satirNo1;
			cout << "Degistirmek istediginiz satir numarasini giriniz: ";
			cin >> satirNo1;
    		tramvay.tasitGuncelle(satirNo1);
			break;
		case 3:
			otobus.bilgileriGoster();
			cout << " " <<endl;
			int satirNo2;
			cout << "Degistirmek istediginiz satir numarasini giriniz: ";
			cin >> satirNo2;
    		otobus.tasitGuncelle(satirNo2);
			break;
		case 4:
			vapur.bilgileriGoster();
			cout << " " <<endl;
			int satirNo3;
			cout << "Degistirmek istediginiz satir numarasini giriniz: ";
			cin >> satirNo3;
    		vapur.tasitGuncelle(satirNo3);
			break;
		default:
			girisEkrani();				
	}
		 int j;
    cout << "\nAna Menuye Donmek Icin 1'i Tuslayiniz: ";
    cin >> j;
    system("cls");
    if(j=1){
    	girisEkrani();
    }
    int x;
    cout << "\nAna Menuye Donmek Icin 1'i Tuslayiniz: ";
    cin >> x;
    system ("cls");
    if(x=1){
    	girisEkrani();
	} 
}

void Ekran::seferSilme() {
	
	int tercih;
	cout << "Sefer Silme Ekranina Hosgeldiniz." << endl;
	cout << " " << endl;
    cout << "1-Metro" << endl;
    cout << "2-Tramvay" << endl;
    cout << "3-Otobus" << endl;
    cout << "4-Vapur" << endl;
    cout << "Seferini Silmek Istediginiz Tasit Turunu Seciniz: ";
    cin >> tercih;
    system("cls");
    switch (tercih) {
        case 1: 	
        	metro.bilgileriGoster();
        	cout << " " <<endl;
			int satirNo1;
			cout << "Silmek istediginiz satir numarasini giriniz: ";
			cin >> satirNo1;
    		metro.tasitSil(satirNo1);
		break;
        case 2:
        	tramvay.bilgileriGoster();
        	cout << " " <<endl;
			int satirNo2;
			cout << "Silmek istediginiz satir numarasini giriniz: ";
			cin >> satirNo2;
    		tramvay.tasitSil(satirNo2);
			break;
		case 3:
        	otobus.bilgileriGoster();
        	cout << " " <<endl;
			int satirNo3;
			cout << "Silmek istediginiz satir numarasini giriniz: ";
			cin >> satirNo3;
    		otobus.tasitSil(satirNo3);
			break;
		case 4:
        	vapur.bilgileriGoster();
        	cout << " " <<endl;
			int satirNo4;
			cout << "Silmek istediginiz satir numarasini giriniz: ";
			cin >> satirNo4;
    		vapur.tasitSil(satirNo4);
			break;
		default:
			girisEkrani();				
	}
	int x;
    cout << "\nAna Menuye Donmek Icin 1'i Tuslayiniz: ";
    cin >> x;
    system ("cls");
    if(x=1){
    	girisEkrani();
	} 
}

void Ekran::seferAra() {
		cout << "Guncel Zaman: " << ctime(&currentTime) << endl;
    int secim;
    cout << "Arama yapmak istediginiz tasit turunu seciniz:\n";
    cout << "1. Metro\n2. Tramvay\n3. Otobus\n4. Vapur "<<endl<<endl;
    cout << "SECIM: ";
    cin >> secim;

    
    string metroKalkisDuragi = "Uskudar";
    string tramvayKalkisDuragi = "Bagcilar";
    string otobusKalkisDuragi = "Kavacik";
    string vapurKalkisDuragi = "Kadikoy";

    // Kalkis duraklarini ekrana yazdir
    switch (secim) {
        case 1:
            cout << "Kalkis Duragi: " << metroKalkisDuragi << endl;
            cout << "Metro ile gidebileceginiz duraklar: Kadikoy, Yildiz, Yenikapi, Kucukyali, Bostanci, Haciosman, Acibadem, Bakirkoy" <<endl<<endl;
            break;
        case 2:
            cout << "Kalkis Duragi: " << tramvayKalkisDuragi << endl;
            cout << "Tramvay ile gidebileceginiz duraklar: Merter, Sisli, Uskudar, Fatih, Esenler, Beylikduzu, Sariyer, Kartal" <<endl<<endl;
            break;
        case 3:
            cout << "Kalkis Duragi: " << otobusKalkisDuragi << endl;
            cout << "Otobus ile gidebileceginiz duraklar: Bulgurlu, Nakkastepe, Kadikoy, Icadiye, Atasehir, Suadiye, Erenkoy, Cengelkoy" <<endl<<endl;  
            break;
        case 4:
            cout << "Kalkis Duragi: " << vapurKalkisDuragi << endl;
            cout << "Vapur ile gidebileceginiz konumlar: Moda, Buyukada, Heybeliada, Eminonu, Kinaliada, Besiktas, Bostanci, Burgazada" <<endl<<endl;
            break;
        default:
            cout << "Gecersiz secim.\n";
    }
	
    string varisDuragi;
    cout << "Gideceginiz Konum: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, varisDuragi);

    // Kalkis duraklarini baz alarak tasitAra fonksiyonunu çagir
    switch (secim) {
        case 1:
        	cout << "\nSectiginiz konuma giden hatlar ve saatleri listesi: "<<endl<<endl;
            metro.tasitAra(metroKalkisDuragi, varisDuragi);
            break;
        case 2:
        	cout << "\nSectiginiz konuma giden hatlar ve saatleri listesi: "<<endl<<endl;
            tramvay.tasitAra(tramvayKalkisDuragi, varisDuragi);
            break;
        case 3:
        	cout << "\nSectiginiz konuma giden hatlar ve saatleri listesi: "<<endl<<endl;
            otobus.tasitAra(otobusKalkisDuragi, varisDuragi);
            break;
        case 4:
        	cout << "\nSectiginiz konuma giden hatlar ve saatleri listesi: "<<endl<<endl;
            vapur.tasitAra(vapurKalkisDuragi, varisDuragi);
            break;
        default:
            cout << "Gecersiz secim.\n";
    }

}




void Ekran :: ucretBilgileri() {
	Tasit tasit;
	double ortUcret;
	tasit.ortalamaUcretHesapla(ortUcret);
	int ortUcret1;
	tasit.ortalamaUcretHesapla(ortUcret1);
	cout<<"\nMETRO UCRETI: "<<metro.getmetroUcreti()<<endl;
	cout<<"TRAMVAY UCRETI: "<<tramvay.gettramvayUcret()<<endl;
	cout<<"OTOBUS UCRETI: "<<otobus.getotobusUcret()<<endl;
	cout<<"VAPUR UCRETI: "<<vapur.getvapurUcret()<<endl<<endl;
	
	int x;
    cout << "\nAna Menuye Donmek Icin 1'i Tuslayiniz: ";
    cin >> x;
    system ("cls");
    if(x=1){
    	girisEkrani();
	} 
	
}


void Ekran :: metroBilgileri(){
	cout << "Metro Bilgileri" << endl;
	metro.bilgileriGoster();
}

void Ekran :: otobusBilgileri(){
	cout << "Otobus Bilgileri" << endl;
	otobus.bilgileriGoster();
}

void Ekran :: tramvayBilgileri(){
	cout << "Tramvay Bilgileri" << endl;
	tramvay.bilgileriGoster();
}

void Ekran :: vapurBilgileri(){
	cout << "Vapur Bilgilieri" << endl;
	vapur.bilgileriGoster();
}
    
    
void Ekran :: ucretHesapla(){
	double metroUcret = 13.5;
    double tramvayUcret = 17;
    double otobusUcret = 9;
    double vapurUcret = 20;

    Kullanici metro(metroUcret, 0);
    Kullanici tramvay(tramvayUcret, 0);
    Kullanici otobus(otobusUcret, 0);
    Kullanici vapur(vapurUcret, 0);

    Kullanici::bilgileriAl(metro, "metro");
    Kullanici::bilgileriAl(tramvay, "tramvay");
    Kullanici::bilgileriAl(otobus, "otobus");
    Kullanici::bilgileriAl(vapur, "vapur");

    double toplamUcret = metro.ucretHesaplama() +
                         tramvay.ucretHesaplama() +
                         otobus.ucretHesaplama() +
                         vapur.ucretHesaplama();

    cout << "Toplam odemeniz gereken ucret: " << toplamUcret << " TL\n";
    
    int x;
    cout << "\nAna Menuye Donmek Icin 1'i Tuslayiniz: ";
    cin >> x;
    system ("cls");
    if(x=1){
    	girisEkrani();
	} 
}





