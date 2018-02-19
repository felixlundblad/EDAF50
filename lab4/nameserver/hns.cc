#include "nameserverinterface.h"
#include "hns.h"

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

HNS::HNS(uint s)
{
    size = s;
    for (int i = 0; i < static_cast<int>(size); i++)
    {
        hns.push_back(vector<pair<HostName, IPAddress>>());
    }
}

uint HNS::myHash(const HostName &name) const
{
    int h = (hash<string>{}(name)) % size;
    return h;
}

void HNS::insert(const HostName &name, const IPAddress &IP)
{
    hns.at(myHash(name)).push_back(pair<HostName, IPAddress>(name, IP));
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
}