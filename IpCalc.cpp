#include <iostream>
#include <string.h>
#include <math.h>       /* pow */
#include <sstream>

#include "IpCalc.h"

// constructor
// input : ip and cidr
// output : none
ipv4::ipv4(std::string ip, std::string cid) {
	IPv4=ip;
	cidr=cid;
}

// convert cidr into mask number 32 bits
// input : cidr 
// output : mask (number)
uint32_t ipv4::getMaskInt() {

	uint32_t m = 0xFFFFFF;
	int n = 32-stoi(cidr);
	for (int i=0; i<n;i++) {
		m= m<<1;
	}
	
	return(m);
}

// find the network address (for display)
// input : ip, cidr
// output : Network address (string)
std::string ipv4::getNetworkAddress() {

	uint32_t ipu=stringToUint(IPv4);
	uint32_t m;

	m=getMaskInt();

	return(UintToString(ipu&m));  // IP & Mask
}

// find the mask address (string)
// input : cidr
// output : mask address (string 255.255.255...)
std::string ipv4::getMask() {
	uint32_t m=getMaskInt();
	
	return(UintToString(m));	
}

// find the broadcast address (string)
// input : ip, cidr
// output : broadcast address (string)
std::string ipv4::getBroadcastAddress() {

	uint32_t ipu=stringToUint(IPv4);
	uint32_t m;

	m=getMaskInt();

	return(UintToString(ipu | ~m)); // IP | ~Mask (=wildcard)
}

// find the first address (string)
// input : ip, cidr
// output : first address (string)
std::string ipv4::getFirstAddress() {

	uint32_t ipN=stringToUint(getNetworkAddress());

	return(UintToString(ipN+1));	// First address = Network @ +1
}

// find the last address (string)
// input : ip, cidr
// output : last address (string)
std::string ipv4::getLastAddress() {
	uint32_t ipB=stringToUint(getBroadcastAddress());
	return(UintToString(ipB-1)); // Last address = Borodcast @ - 1
}

// find possible number of hosts
// input : ip, cidr
// output : first address (string)
int ipv4::getNbHost() {
	
	int icidr = stoi(cidr); //stringToUint("0.0.0."+cidr);
	
	return(pow(2, 32-icidr)-2); // nb hosts = 2^(32-cidr)-2
	
}

// convert string to uint32
// input : string
// output : unsigned int
uint32_t ipv4::stringToUint(std::string str) {
      uint32_t val[4];
			uint32_t uip=0;

		std::stringstream  s(str);
		char ch;
		s >> val[0] >> ch >> val[1] >> ch >> val[2] >> ch >> val[3];

    uip = val[0] << 24;
    uip |= val[1] << 16;
    uip |= val[2] << 8;
    uip |= val[3];

    return(uip);
  }

// convert unint32 into string (for display)
// input : uint32 
// output : string
std::string ipv4::UintToString(const uint32_t ipu) {

    uint32_t ipp=ipu;

    std::stringstream s;

    s << std::to_string((ipp >> 24) & 0xFF ).c_str() << ".";
    s << std::to_string((ipp >> 16) & 0xFF ).c_str() << ".";
    s << std::to_string((ipp >> 8) & 0xFF ).c_str() << ".";
    s << std::to_string((ipp) & 0xFF );

    return (s.str());
}