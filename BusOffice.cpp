//
//  BusOffice.cpp
//  BusManagement_v3
//
//  Created by Yeow Pann on 14/11/22.
//

#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Bus.cpp"
#include "BusDAO.cpp"
using namespace std;

class BusOffice : public BusDao
{
    
    int _BusId;
    
    Bus* buses[100];
    
    int count = 0;
    
public:

    BusOffice(): _BusId(0){}
    BusOffice(int _BusId): _BusId(_BusId){}
    
    void addBus(Bus* bus){
        
        buses[count] = new Bus;
        buses[count] = bus;
        count++;
        
    }
    
    void displayAllBus(){
        
            for(int i = 0; i < count; i++){

                        cout<<"\n\n\nBus no: \t"<<buses[i]-> getBusNumber()<<"\n";
                    for (int i=80;i>0;i--)

                        cout<<'-';

                        cout <<"\nDriver: \t"<<buses[i]-> getDriverName()<<"\t\tArrival time: "

                        <<buses[i]-> getArrivalTime()<<"\tDeparture time: "<<buses[i]->getDepartureTime()

                        <<"\nFrom: \t\t"<<buses[i]->getFrom()<<"\t\tTo: \t\t"<<

                        buses[i]->getTo()<<"\n";
                for (int i=80;i>0;i--)

                    cout<<'-';

                }
        }

    int searchBusById(int busNumber){
        
        
        for(int i = 0; i < count; i++){
            
            if(buses[i]->getBusNumber() == busNumber){
         
                return i;
            }

            
        }
        return -1;
        
    }
    
    int searchBusByName(string driverName){
        
        for(int i = 0; i < count; i++){
            
            if(buses[i]->getDriverName() == driverName){
                buses[i]->outputbeforeedit();
                return i;
            }

        }
        return -1;
        
    }
    
    void modifyBusByID(int busNum){
        
        int found = searchBusById(busNum);
      
        if(found != -1){
            cout << "\n\n\t\t\t\tINPUT NEW BUS ID: ";
            cin >> busNum;
            
            buses[found]->setBusNumber(busNum);
            buses[found]->outputbeforeedit();
         
            
            cout<<"\n\n\t\t\t >>> Bus ID has been Edit <<<" <<endl;
        }
        else {
            
            cout <<"\n\t\t\t\t>>> Bus No "<<busNum<<" NOT FOUND <<<"<< endl;
            
        }
    }
    
    void modifyBusByName(string driverName){
        
       // string dname;
        int found  = searchBusByName(driverName);
   
        if(found != -1){
            cout << "\n\n\t\t\t\tINPUT NEW DRIVER'S NAME: ";
            cin >> driverName;
            buses[found]->setDriverName(driverName);
            buses[found]->outputbeforeedit();
            cout<<"\n\n\t\t\t\t >>> Driver's Name has been Edit <<<" <<endl;
        }
        
        else {

            cout <<"\n\t\t\t\t>>> Driver's "<<driverName<<" NOT FOUND <<<"<< endl;

        }
    }
    
    void deletebusId(int busNumber){
        int found = searchBusById(busNumber);
        buses[found]->outputbefordelete();
        if(found != -1){
            for(int i = 0; i < count; i++){
                buses[i] = buses[i+1];
            }
            count--;
         
            cout << "\n\n\t\t\t\t>>> Bus No " <<busNumber<<" has been deleted <<<";
            
        }
        else {
            cout <<"\n\t\t\t\t>>> Bus No "<<busNumber<<"NOT FOUND <<<"<< endl;
        }
    }
    
    void deletebusName(string driverName){
        
        int found = searchBusByName(driverName);
        buses[found]->outputbefordelete();
        if(found != -1){
           
            for(int i = 0; i < count; i++){
                
                buses[i] = buses[i+1];
                
            }
            count--;
            cout << "\n\n\t\t\t\t>>> Bus Driver's Name " <<driverName<<" has been deleted <<<";
        }
        
        else {
            cout <<"\n\t\t\t\t>>> Driver's "<<driverName<<"NOT FOUND <<<"<< endl;
        }
        
    }
    
    Bus* getBusById(int busNumber){
        Bus* bus = nullptr;
        for (int i = 0; i< count; i++) {
            if (buses[i]->getBusNumber() == busNumber){
                return buses[i]-1;
                
            }
        }
        return bus;
    }
    
    Bus* getBusbyName(string driverName){
        Bus* bus = nullptr;
        for(int i = 0; i < count; i++){
            if(buses[i]->getDriverName() == driverName){
                return buses[i];
                
            }

          
        }
        return bus;
    }

    
    
};
