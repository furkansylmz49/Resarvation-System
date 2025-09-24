#include "Hotel.h"

int Hotel::EmployeeMenu(){
    int choice;
    while(true){
        cout<<"===Çalışan İşlemleri==="<<endl;
        cout<<"\t1 -> Oda Ekle"<<endl;
        cout<<"\t2 -> Oda Sil"<<endl;
        cout<<"\t3 -> Müşteri Sayısını Görüntüle"<<endl;
        cout<<"\t4 -> Giriş Menüsüne Dön"<<endl;

        try{
            cout<<"\nLütfen Seçiminizi Giriniz: ";
            cin >> choice;

            if(cin.fail()){
                    cin.clear();
                    cin.ignore(1000, '\n');
                    throw -1;
            }else if(choice>4 || choice<1){
                throw choice;
            }else{
                cout<<"\n\tSeçiminize Yönlendiriliyorsunuz...\n"<<endl;
                return choice;
            }
        }catch(...){
            cout<<"\nLütfen Geçerli Bir Sayı Giriniz (1-2-3-4)\n"<<endl;
        }
    }
}

void Hotel::OdaEkle(){
    int OdaNumarası,fiyat,floor,Tipi,DoluMu;

    cout<<"Lütfen Oda Bilgilerini Giriniz: "<<endl;
    cout<<"Oda Numarası: ";
    cin >> OdaNumarası;

    cout<<"Fiyat: ";
    cin>> fiyat;

    cout<<"Oda Tipi: ";
    cin>> Tipi;
    Type enumTipi = static_cast<Type>(Tipi);

    cout<<"Rezarvasyon Durumu: ";
    cin>>DoluMu;
    RezervasyonDurumu enumDoluMu = static_cast<RezervasyonDurumu>(DoluMu);

    cout<<"Bulunduğu Kat: ";
    cin>>floor;

    if(floor == 1){
        odalar.push_back(make_shared<Floor1>(OdaNumarası,fiyat,enumTipi,enumDoluMu));
        cout<<"\nOda Sisteme Kaydedilmiştir. Ana Menüye Yönlendiriliyorsunuz...\n"<<endl;
    }else if(floor == 2){
        odalar.push_back(make_shared<Floor2>(OdaNumarası,fiyat,enumTipi,enumDoluMu));
        cout<<"\nOda Sisteme Kaydedilmiştir. Ana Menüye Yönlendiriliyorsunuz...\n"<<endl;
    }else if(floor == 3){
        odalar.push_back(make_shared<Floor3>(OdaNumarası,fiyat,enumTipi,enumDoluMu));
        cout<<"\nOda Sisteme Kaydedilmiştir. Ana Menüye Yönlendiriliyorsunuz...\n"<<endl;
    }else{
        cout<<"\nBöyle Bir Kat Bulunmamaktadır. Oda Kayıt Edilmedi. Ana Menüye Yönlendiriliyorsunuz...\n"<<endl;
    }

}

void Hotel::OdaSil(){
    int OdaNumarası;
    bool bulundu;

    cout<<"Silmek İstediğiniz Odanın Oda Numarası: ";
    cin >> OdaNumarası;
    
    bulundu = false;
    for(auto x = odalar.begin(); x != odalar.end(); x++){
        if(OdaNumarası == (*x)->getOdaNumarası()){
            bulundu = true;
            odalar.erase(x);
            cout<<"\n"<<OdaNumarası<<" Numaralı Oda Silinmiştir Ana Menüye Yönlendiriliyorsunuz...\n"<<endl;
            break;
        }
    }
    if(!bulundu){
        cout<<"\nGirmiş Olduğunuz Oda Numarasında bir Oda Bulunanamaıştır."<<endl;
        cout<<"Ana Menüye Yönlendiriliyorsunuz...\n"<<endl;
    }
}

void Hotel::getCustomerCount(){
    cout<<"Oteldeki Toplam Müşteri Sayısı: "<<Hotel::CustomerCount<<"\n"<<endl;
    cout<<"İşlem tamamlandı Ana Menüye Yönlendiriliyorsunuz...\n"<<endl;
}