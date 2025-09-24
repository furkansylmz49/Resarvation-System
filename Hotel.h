#include <memory>
#include <iostream>
#include <vector>
#include <string>
#include "Room.h"
using namespace std;

class Hotel{
    private:
        vector<shared_ptr<Room>> odalar;
        vector<pair<string,int>> guest;
        vector<pair<string,int>> employee;
    public:
        static int CustomerCount;

        void verify(vector<pair<string,int>> &vector);

        int mainMenu();
        int EmployeeMenu();
        int CustomerMenu();

        void RoomManagement();

        void OdaEkle();
        void OdaSil();
        void ListRoom();
        void RezarvasyonYap();
        void RezarvasyonIptal();
        static void getCustomerCount(); 
};