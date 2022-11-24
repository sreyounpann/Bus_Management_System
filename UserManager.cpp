//
//  UserManager.cpp
//  BusManagement_v3
//
//  Created by Yeow Pann on 15/11/22.
//


#pragma once
#include <iostream>
#include "User.cpp"
using namespace std;

class UserManager {
private:
    User* users[10];
    int count = 0;
    string username ;
    string password ;
    int loginAttempt = 0;
    const int Count = 5;
public:

    void addUser(User* user) {
        users [count] = new User();
        users[count] = user;
        count++;
    }

    void viewUser() {
        cout << "\n\n\t\t\t\t.......Account Details......\n";
        for (int i = 0; i < count;i++) {
           
            cout <<"\n\t\tUser ID: \t"<<users[i]->getId()<<"\t\tUsername: \t" <<users[i]->getUsername()<<"\t\tPassword: \t"<<users[i]->getPassword()<<"\t\t\n";

        }
    }

    int findUersByName(string username) {
        for (int i = 0; i < count; i++) {
            if (users[i]->getUsername() == username) {
                return i;
            }
            else {
                          
                          cout <<"\n\t\t\t\t>>> DATA NOT FOUND <<<"<< endl;
                          
                      }
        }
        return -1;
    }
    
    int findUserById(int id){
        for(int i = 0; i < count ; i++){
            if (users[i]->getId()==id) {
                return i;
            }
            else {
                          
                          cout <<"\n\t\t\t\t>>> DATA NOT FOUND <<<"<< endl;
                          
                      }
        }
        return -1;
        
    }
    

    void editUserbyId(int id){
        
        int found = findUserById(id);
       
        if(found != -1){
            cout << "\n\t\t\t\tINPUT NEW USER ID: ";
            cin >> id;
            users[found]->setId(id);
            users[found]->outputUser();
            
            cout << "\n\t\t\t\t >>> This User ID has Been Edited <<< "<< endl;
            
        }
        else {
            cout <<"\n\t\t\t\t>>> User No "<<id<<" NOT FOUND <<<"<< endl;
        }
    }

    
    void editUserbyName(string username) {
 

        int found = findUersByName(username);

        if (found != -1) {
           
            cout << "\n\t\t\t\tINSERT  NEW USERNAME: ";
            cin >> username;
            users[found]->setUsername(username);
            users[found]->outputUser();
                        cout<<"\n\n\t\t\t\t >>> This User Name has been Edited <<<" <<endl;

        }
        else {
                        cout <<"\n\t\t\t\t>>> User Name's "<<username<<" NOT FOUND <<<"<< endl;
        }
    }
    
    void deleteUserbyName(string name) {

        int found = findUersByName(name);
        users[found]->outputUser();
        if (found != -1) {
            for (int i = found; i < count; i++) {
                users[i] = users[i + 1];
            }
            count--;
            cout << "\n\n\t\t\t\t>>> This UserName " <<name<<" has been deleted <<<";
            
        }
        else {
            cout <<"\n\t\t\t\t>>> Driver's "<<name<<" NOT FOUND <<<"<< endl;
        }
    }
    void deleteUserbyId(int id){
        int found = findUserById(id);
        users[found]->outputUser();
        if (found != -1){
            for(int i = found; i < count; i++){
                users[i] = users[i+1];
            }
            count--;
            cout << "\n\t\t\t\tSorry,this users has been delete\n";
            
        }
        else {
                       cout <<"\n\t\t\t\t>>> USER NO "<<id<<" NOT FOUND <<<"<< endl;
        }
        
    }

    User* authenticateUser(string username, string password) {
        User* user=nullptr;
        for (int i = 0; i < count; i++) {
            if (users[i]->getUsername() == username && users[i]->getPassword() == password) {
                return users[i];
            }
        }
        return user;
    }
};
