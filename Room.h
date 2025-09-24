#include <memory>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum class Type{CIFT_KISILIK,TEK_KISILIK,SUIT};
enum class RezervasyonDurumu { BOS, DOLU };

struct Room{
    public:
        virtual void displayInfo() const = 0;

        virtual int getOdaNumarası() const = 0;
        virtual RezervasyonDurumu getDoluMu() const = 0;
        virtual void setDoluMu(RezervasyonDurumu durum) = 0;
};

struct Floor1: public Room{ 
    public:
        int OdaNumarası;
        int fiyat; 
        Type OdaTipi; 
        RezervasyonDurumu DoluMu; 

        void displayInfo() const override{
            string tipiStr;

            switch(OdaTipi) {
                case Type::CIFT_KISILIK: tipiStr = "Çift Kişilik"; break;
                case Type::TEK_KISILIK:   tipiStr = "Tek Kişilik"; break;
                case Type::SUIT:          tipiStr = "Suit"; break;
            }

            string durumStr = (DoluMu == RezervasyonDurumu::BOS) ? "Boş" : "Dolu";

            cout<<"Oda Numarası: "<<OdaNumarası
            <<" Fiyat: "<<fiyat
            <<" Oda Tipi: " << tipiStr
            <<" Rezarvasyon Durumu: "<<durumStr
            <<" Bulunduğu Kat: 1"<<endl;
        }

        int getOdaNumarası() const override { return OdaNumarası; }
        RezervasyonDurumu getDoluMu() const override { return DoluMu; }
        void setDoluMu(RezervasyonDurumu durum) override { DoluMu = durum; }

        Floor1(int odaNo, int f, Type tip, RezervasyonDurumu dolu){
            OdaNumarası = odaNo;
            fiyat = f;
            OdaTipi = tip;
            DoluMu = dolu;
        }
};

struct Floor2: public Room{ 
    public:
        int OdaNumarası;
        int fiyat; 
        Type OdaTipi; 
        RezervasyonDurumu DoluMu; 

        void displayInfo() const override{
            string tipiStr;

            switch(OdaTipi) {
                case Type::CIFT_KISILIK: tipiStr = "Çift Kişilik"; break;
                case Type::TEK_KISILIK:   tipiStr = "Tek Kişilik"; break;
                case Type::SUIT:          tipiStr = "Suit"; break;
            }

            string durumStr = (DoluMu == RezervasyonDurumu::BOS) ? "Boş" : "Dolu";

            cout<<"Oda Numarası: "<<OdaNumarası
            <<" Fiyat: "<<fiyat
            <<" Oda Tipi: " << tipiStr
            <<" Rezarvasyon Durumu: "<<durumStr
            <<" Bulunduğu Kat: 1"<<endl;
        }

        int getOdaNumarası() const override { return OdaNumarası; }
        RezervasyonDurumu getDoluMu() const override { return DoluMu; }
        void setDoluMu(RezervasyonDurumu durum) override { DoluMu = durum; }

        Floor2(int odaNo, int f, Type tip, RezervasyonDurumu dolu){
            OdaNumarası = odaNo;
            fiyat = f;
            OdaTipi = tip;
            DoluMu = dolu;
        }
};

struct Floor3: public Room{ 
    public:
        int OdaNumarası;
        int fiyat; 
        Type OdaTipi; 
        RezervasyonDurumu DoluMu; 

        void displayInfo() const override{
            string tipiStr;

            switch(OdaTipi) {
                case Type::CIFT_KISILIK: tipiStr = "Çift Kişilik"; break;
                case Type::TEK_KISILIK:   tipiStr = "Tek Kişilik"; break;
                case Type::SUIT:          tipiStr = "Suit"; break;
            }

            string durumStr = (DoluMu == RezervasyonDurumu::BOS) ? "Boş" : "Dolu";

            cout<<"Oda Numarası: "<<OdaNumarası
            <<" Fiyat: "<<fiyat
            <<" Oda Tipi: " << tipiStr
            <<" Rezarvasyon Durumu: "<<durumStr
            <<" Bulunduğu Kat: 1"<<endl;
        }

        int getOdaNumarası() const override { return OdaNumarası; }
        RezervasyonDurumu getDoluMu() const override { return DoluMu; }
        void setDoluMu(RezervasyonDurumu durum) override { DoluMu = durum; }

        Floor3(int odaNo, int f, Type tip, RezervasyonDurumu dolu){
            OdaNumarası = odaNo;
            fiyat = f;
            OdaTipi = tip;
            DoluMu = dolu;
        }
};