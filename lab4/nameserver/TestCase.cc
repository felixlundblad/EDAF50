#include "mns.h"
#include "VNS.h"
#include <iostream>

using namespace std;


//_________________________________________________________________________________
// Map
bool MNStestInsert(MNS &server){
    cout << "Testing insert():" << endl;
    server.insert("Stig", 123456);
    cout << "Stig, 123456 should have been inserted" << endl;
    return true;    
}

bool MNStestLookup(MNS &server){
        cout << "Testing lookup():" << endl;
    if(server.lookup("Stig") == 123456){
        cout << "Stig was found correctly." << endl;
        return true;
    }
    else{
        cout << "Error: Stig was not found." << endl;
        return false;
    }
}

bool MNStestRemove(MNS &server){
    bool sucess = true;
    cout << "Testing remove():" << endl;
    server.insert("Helena", 987543);
    server.remove("Stig");
    if(!server.lookup("Stig")) {
        cout << "Stig was removed correctly" << endl;
    }
    else {
        cout << "Error: Stig was not removed correctly" << endl;
        sucess = false;
    }
    if(server.lookup("Helena")){
        cout << "Helena is still there, as expected" << endl;
    }else {
        cout << "Error: Helena is not there" << endl;
        sucess = false;
    }
        if(sucess)return true;
        return false;
}

bool MNStest(){
    MNS server;
    MNStestInsert(server);
    MNStestLookup(server);
    MNStestRemove(server);
    return true;
}


//________________________________________________________________________________
// Vector

bool VNStestInsert(VNS &server){
    cout << "Testing insert():" << endl;
    server.insert("Stig", 123456);
    cout << "Stig, 123456 should have been inserted" << endl;
    return true;
}

bool VNStestLookup(VNS &server){
    cout << "Testing lookup():" << endl;
    if(server.lookup("Stig") == 123456){
        cout << "Stig was found correctly." << endl;
        return true;
    }
    else{
        cout << "Error: Stig was not found." << endl;
        return false;
    }
}

bool VNStestRemove(VNS &server){
    cout << "Testing remove():" << endl;
    server.insert("Helena", 987543);
    server.remove("Stig");
    if(!server.lookup("Stig")) {
        cout << "Stig was removed correctly" << endl;
        return true;
    }
    else {
        cout << "Error: Stig was not removed correctly" << endl;
        return false;
    }
    if(server.lookup("Helena")){
        cout << "Helena is still there, as expected" << endl;
    }else {
        cout << "Error: Helena is not there" << endl;
    }
}

bool VNStest(){
    VNS server;
    return VNStestInsert(server) && VNStestLookup(server) && VNStestRemove(server);
}


//_________________________________________________________________________________
// Main
int main(){
    MNStest();
    //VNStest();
}