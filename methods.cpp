#include "Hotel.h"

int Hotel::CustomerCount = 0;

int Hotel::mainMenu(){
    int choice;
    while(true){
        cout<<"===Hotelimize Hoşgeldiniz==="<<endl;
        cout<<"\t1 -> Müşteri İşlemleri"<<endl;
        cout<<"\t2 -> Çalışan İşlemleri"<<endl;
        cout<<"\t3 -> Çıkış"<<endl;

        try{
            cout<<"\nLütfen Seçiminizi Giriniz: ";
            cin >> choice;

            if(cin.fail()){
                    cin.clear();
                    cin.ignore(1000, '\n');
                    throw -1;
            }else if(choice >3 || choice<1){
                throw choice;
            }else{
                cout<<"\n\tSeçiminize Yönlendiriliyorsunuz...\n"<<endl;
                return choice;
            }
        }catch(...){
            cout<<"\nLütfen Geçerli Bir Sayı Giriniz (1-2-3)\n"<<endl;
        }
    }
}

void Hotel::verify(vector<pair<string,int>> &vector){
    string name;
    int ID, choiceLogin;
    bool bulunduLogin, bulundu;

    while(true){
        cout << "\t1 -> Giriş Yap" << endl;
        cout << "\t2 -> Kayıt Ol" << endl;

        try{
            cout << "\nLütfen Seçiminizi Giriniz: ";
            cin >> choiceLogin;

            if(cin.fail()){
                cin.clear();
                cin.ignore(1000, '\n');
                throw -1;
            } else if(choiceLogin > 2 || choiceLogin < 1){
                throw choiceLogin;
            } else {
                if(choiceLogin == 1){
                    try{
                        cout << "\nLütfen İsminizi İlk Harfini Büyük Yazarak Giriniz: ";
                        cin >> name;
                        cout << "Lütfen ID'nizi Giriniz: ";
                        cin >> ID;

                        if(cin.fail()){
                            cin.clear();
                            cin.ignore(1000, '\n');
                            throw -1;
                        } else {
                            bulunduLogin = false;
                            for(auto &item: vector){
                                if(item.first == name && item.second == ID){
                                    cout << "\nGiriş Başarılı Menüye Yönlendiriliyorsunuz.\n" << endl;
                                    bulunduLogin = true;
                                    break;
                                }
                            }
                            if(!bulunduLogin){
                                cout << "\nGirmiş Olduğunuz Kullanıcı Bilgileri İle Eşleşen Kayıt Bulunamadı Tekrar Deneyiniz.\n" << endl;
                            } else {
                                break;
                            }
                        }
                    } catch(...){
                        cout << "\nGirmiş olduğunuz ID Sayılardan Oluşmalıdır. Tekrar Deneyiniz.\n" << endl;
                    }
                } else if(choiceLogin == 2){
                    try{
                        cout << "\nLütfen İsminizi İlk Harfini Büyük Yazarak Giriniz: ";
                        cin >> name;
                        cout << "Lütfen ID'nizi Giriniz: ";
                        cin >> ID;

                        if(cin.fail()){
                            cin.clear();
                            cin.ignore(1000, '\n');
                            throw -1;
                        } else {
                            bulundu = false;
                            for(auto &item : vector){
                                if(ID == item.second){
                                    bulundu = true;
                                    break;
                                }
                            }
                            if(!bulundu){
                                vector.push_back(make_pair(name,ID));
                                cout << "\nKayıt Başarılı Menüye Yönlendiriliyorsunuz.\n" << endl;
                            } else {
                                cout << "\nBu ID'ye Sistemde Kayıtlıdır. Kaydınız Tamamlanamadı." << endl;
                                cout << "Ana Menüye Yönlendiriliyorsunuz...\n" << endl;
                            }

                            

                        }
                    } catch(...){
                        cout << "\nGirmiş olduğunuz ID Sayılardan Oluşmalıdır. Tekrar Deneyiniz.\n" << endl;
                    }
                }
            }
        } catch(...){
            cout << "\nLütfen Geçerli Bir Sayı Giriniz (1-2)\n" << endl;
        }
    }
}

void Hotel::RoomManagement(){
    int choiceMain,choiceCustomer,choiceEmployee,ID,choiceLogin;
    string name;
    bool bulunduLogin;

    while(true){
        choiceMain = mainMenu();

        switch(choiceMain){
            case 1:
                verify(guest);
            
                while(true){
                    choiceCustomer = CustomerMenu();

                    switch(choiceCustomer){
                        case 1:
                            RezarvasyonYap();
                            break;
                        case 2:
                            RezarvasyonIptal();
                            break;
                        case 3:
                            ListRoom();
                            break;
                        case 4: 
                            cout<<"Ana Menüye Yönlendiriliyorsunuz...\n"<<endl;
                            break;
                    }
                    if(choiceCustomer == 4){break;}
                }

                break;
            case 2:
                verify(employee);

                while(true){
                    choiceEmployee = EmployeeMenu();

                    switch(choiceEmployee){
                        case 1:
                            OdaEkle();
                            break;
                        case 2:
                            OdaSil();
                            break;
                        case 3:
                            getCustomerCount();
                            break;
                        case 4: cout<<"Ana Menüye Yönlendiriliyorsunuz...\n"<<endl; break;
                    }
                    if(choiceEmployee == 4){break;}
                }
                break;
            case 3:
                cout<<"Sistemden Çıkış Yapılıyor. Yine Bekleriz."<<endl;
                break;
        }
        if(choiceMain == 3){break;}
    }
}


        