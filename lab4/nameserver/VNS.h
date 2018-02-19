#ifndef VNS_H
#define VNS_H

#include "nameserverinterface.h"

#include <vector>

class VNS : public NameServerInterface
{
  public:
    VNS();
    void insert(const HostName &, const IPAddress &);
    bool remove(const HostName&);
    IPAddress lookup(const HostName&) const;
  private:
    std::vector<std::pair<HostName, IPAddress>> vns;
  protected:
};

#endif