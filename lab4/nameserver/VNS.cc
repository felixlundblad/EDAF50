#include "nameserverinterface.h"
#include "VNS.h"

#include <vector>
#include <algorithm>

using namespace std;

VNS::VNS() {}

void VNS::insert(const HostName &s, const IPAddress &IP)
{
    vns.push_back(std::pair<HostName, IPAddress>(s, IP));
}

IPAddress VNS::lookup(const HostName &name) const
{
    auto it = find_if(vns.begin(), vns.end(), [&name](std::pair<HostName, IPAddress> const &elem) {
        return !elem.first.compare(name);
    });
    if (it != vns.end() && !it->first.compare(name))
        return it->second;
    return NON_EXISTING_ADDRESS;
}

bool VNS::remove(const HostName &name)
{
    auto it = find_if(vns.begin(), vns.end(), [&name](const std::pair<HostName, IPAddress> &elem) {
        return elem.first == name;
    });
    if (it != vns.end())
    {
        vns.erase(it);
        return true;
    }
    return false;
}