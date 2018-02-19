#include "nameserverinterface.h"
#include "umns.h"

#include <unordered_map>
#include <algorithm>

using namespace std;

UMNS::UMNS() {}

void UMNS::insert(const HostName &s, const IPAddress &IP)
{
    umns.insert(std::pair<HostName, IPAddress>(s, IP));
    //umns[s] = IP;
}

IPAddress UMNS::lookup(const HostName &name) const
{
    auto it = umns.find(name);
    if(it != umns.end())
        return it->second;
    return NON_EXISTING_ADDRESS;
}

bool UMNS::remove(const HostName& name){
    auto it = umns.find(name);
    if(it != umns.end()){
        umns.erase(it);
        return true;
    }
    return false;
}