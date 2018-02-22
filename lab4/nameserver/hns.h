#ifndef HNS_H
#define HNS_H

#include "nameserverinterface.h"

#include <vector>

class HNS : public NameServerInterface
{
  public:
    //HNS(uint s);
    HNS(size_t);
    void insert(const HostName &, const IPAddress &);
    bool remove(const HostName&);
    IPAddress lookup(const HostName&) const;
  private:
    std::vector<std::vector<std::pair<HostName, IPAddress>>> hns;
    size_t size;
    size_t myHash(const HostName &name) const;
  protected:
};

#endif