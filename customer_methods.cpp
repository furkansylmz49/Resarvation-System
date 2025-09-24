#include "Hotel.h"

int Hotel::CustomerMenu(){
    int choice;
    while(true){
        cout<<"===Müşteri İşlemleri==="<<endl;
        cout<<"\t1 -> Rezarvasyon Yap"<<endl;
        cout<<"\t2 -> Rezarvasyon Sil"<<endl;
        cout<<"\t3 -> Tüm Odaları Listele"<<endl;
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

void Hotel::RezarvasyonYap(){
    int OdaNumarası;
    bool bulundu;
    try{
        cout<<"Lütfen Rezerve Etmek İstediğiniz Oda Numarasını Söylermisiniz: ";
        cin >> OdaNumarası;
        
        if(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            throw -1;
        }else{
            bulundu = false;
            for(auto &item : odalar ){
                if(OdaNumarası == item->getOdaNumarası()){
                    bulundu= true;
                    if(item->getDoluMu() == RezervasyonDurumu::BOS){
                        item->setDoluMu(RezervasyonDurumu::DOLU);
                        Hotel::CustomerCount++;
                        cout<<"\nRezarvasyon İşleminiz Başarıyla Tamamlanmıştır. Ana Menüye Yönlendiriliyorsunuz...\n"<<endl;
                    }else{
                        cout<<"\nRezarvasyon Yapmak İstediğiniz Oda Doludur. İşlem Tamamlanamamıştır..."<<endl;
                        cout<<"Ana Menüye Yönlendiriliyorsunuz...\n"<<endl;
                    }
                }
            }
            if(!bulundu){
                cout<<"\nYazdığınız Oda Numarası Hatalı veya Yanlış Olabilir Lütfen Kontrol Ediniz"<<endl;
                cout<<"Ana Menüye Yönlendiriliyorsunuz...\n"<<endl;
            }
        }
        
    }catch(...){
        cout<<"\nGirmiş olduğunuz Oda Numarası Sayılardan Oluşmalıdır. Ana Menüye Yönlendiriliyorsunuz...\n"<<endl;
    }
}

void Hotel::RezarvasyonIptal(){
    int OdaNumarası;
    bool bulundu;
    try{
        cout<<"Lütfen Rezervasyon İptal Etmek İstediğiniz Oda Numarasını Söylermisiniz: ";
        cin >> OdaNumarası;
        
        if(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            throw -1;
        }else{
            bulundu = false;
            for(auto &item : odalar ){
                if(OdaNumarası == item->getOdaNumarası()){
                    bulundu= true;
                    if(item->getDoluMu() == RezervasyonDurumu::DOLU){
                        item->setDoluMu(RezervasyonDurumu::BOS);
                        Hotel::CustomerCount--;
                        cout<<"\nRezarvasyon İptal İşleminiz Başarıyla Tamamlanmıştır. Ana Menüye Yönlendiriliyorsunuz...\n"<<endl;
                    }else{
                        cout<<"\nRezarvasyon İptal Yapmak İstediğiniz Oda Boştur. İşlem Tamamlanamamıştır..."<<endl;
                        cout<<"Ana Menüye Yönlendiriliyorsunuz...\n"<<endl;
                    }
                }
            }
            if(!bulundu){
                cout<<"\nYazdığınız Oda Numarası Hatalı veya Yanlış Olabilir Lütfen Kontrol Ediniz"<<endl;
                cout<<"Ana Menüye Yönlendiriliyorsunuz...\n"<<endl;
            }
        }
        
    }catch(...){
        cout<<"\nGirmiş olduğunuz Oda Numarası Sayılardan Oluşmalıdır. Ana Menüye Yönlendiriliyorsunuz...\n"<<endl;
    }
}

void Hotel::ListRoom(){
    cout<<"Odalar ve Bilgileri:\n"<<endl;
    for(auto &item : odalar){
        item->displayInfo();
    }
    cout<<"\n"<<endl;
}