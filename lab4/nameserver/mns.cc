#include "nameserverinterface.h"
#include "mns.h"

#include <map>
#include <algorithm>

using namespace std;

MNS::MNS() {}

void MNS::insert(const HostName &s, const IPAddress &IP)
{
    mns.insert(std::pair<HostName, IPAddress>(s, IP));
    //mns[s] = IP;
}

IPAddress MNS::lookup(const HostName &name) const
{
    auto it = mns.find(name);
    if(it != mns.end())
        return it->second;
    return NON_EXISTING_ADDRESS;
}

bool MNS::remove(const HostName& name){
    auto it = mns.find(name);
    if(it != mns.end()){
        mns.erase(it);
        return true;
    }
    return false;
}