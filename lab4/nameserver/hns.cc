#include "nameserverinterface.h"
#include "hns.h"

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/*HNS::HNS(size_t s)
{
    size = s;
    for (int i = 0; i < static_cast<int>(size); i++)
    {
        hns.push_back(vector<pair<HostName, IPAddress>>());
    }
}*/

HNS::HNS(size_t s): size(s), hns(s){}

size_t HNS::myHash(const HostName &name) const
{
    hash<HostName> hash;
    //int h = (hash<string>{}(name)) % size;
    return hash(name)%size;
}

void HNS::insert(const HostName &name, const IPAddress &IP)
{
    hns.at(myHash(name)).push_back(pair<HostName, IPAddress>(name, IP));
    
    /*
    hash<HostName> hashVal;
	size_t s = hashVal(name)%size;
	hns[s].push_back(make_pair(name, IP));
	*/
}

IPAddress HNS::lookup(const HostName &name) const
{
    auto v = &hns.at(myHash(name));
    auto it = find_if(v->begin(), v->end(), [&name](std::pair<HostName, IPAddress> const &elem) {
        return !elem.first.compare(name);
    });
    if (it != v->end())
        return it->second;
    return NON_EXISTING_ADDRESS;

    /*
   	hash<HostName> hashVal;
	size_t s = hashVal(name)%size;
	auto first = find_if(hns[s].begin(), hns[s].end(), 
		[&name](const pair<HostName, IPAddress>& elem) { return elem.first == name; });
	if(first != hns[s].end()){
		return first->second;
	}
	return NON_EXISTING_ADDRESS;
    */
}

bool HNS::remove(const HostName &name)
{
    auto v = &hns.at(myHash(name));
    auto it = find_if(v->begin(), v->end(), [&name](const std::pair<HostName, IPAddress> &elem) {
        return elem.first == name;
    });
    if (it != v->end())
    {
        v->erase(it);
        return true;
    }
    return false;
    
    /*
    hash<HostName> hashVal;
	size_t s = hashVal(name)%size;
	auto first = find_if(hns[s].begin(), hns[s].end(), 
		[&name](const pair<HostName, IPAddress>& elem) { return elem.first == name; });
	if (first != hns[s].end()){
		hns[s].erase(first);
		return true;
	}
	return false;
    */
}