#include <iostream>
#include <string>
#include "IpCalc.h"

/*
 * Algorithm :
 * Get host IP and cidr
 * Convert in unsigned integer 32
 * To find network address : just make AND operation between IP and Mask
 * To find brodacast address :just make OR operation between IP and wildcard/Mask
 * To find first address : just add 1 to network address (of course)
 * To find last address : just substract 1 from broadcast address
 * To find number of hosts : 2^(32-cidr)-2
 * check if other address is in the same network
 */


int main(int argc, char **argv) {

	std::string ip="0";
	std::string cidr="0";

	std::string ip_bis="0";
	std::string cidr_bis="0";

	switch (argc) {
		case 3:
			ip = argv[1];
			cidr= argv[2];
			break;
		case 5:
			ip = argv[1];
			cidr = argv[2];
			ip_bis = argv[3];
			cidr_bis = argv[4];
			break;
		default : 
			std::cout << "Expected parameters:  adr1 mask1 [adr2 mask2]  " <<std::endl;
			return 0;
	}

       

		ipv4 ipv_bis(ip_bis, cidr_bis);

		// std::cout << "Entrez l'adresse IP du hôte : " <<std::endl;
		// std::cin >> ip;

		// std::cout << "Entrez le CIDR : " <<std::endl;
		// std::cin >> cidr;

		// std::cout << "Adresse IP: "<< ip<<std::endl;

		ipv4 ipv(ip, cidr);  

        std::cout << "-" << ip <<"-" << cidr <<std::endl;
		
		std::cout << "Masque    : "<<  ipv.getMask()<<std::endl;
		
		std::cout << "Adresse Réseau   : "<<  ipv.getNetworkAddress()<<std::endl;

		std::cout << "Adresse Diffusion: "<< ipv.getBroadcastAddress()<<std::endl;

		std::cout << "1ère Adresse IP  : "<< ipv.getFirstAddress()<<std::endl;

		std::cout << "Dernière Adresse IP: "<< ipv.getLastAddress()<<std::endl;

		std::cout << "Nombre hôtes : "<< ipv.getNbHost()<<std::endl;

		if (ip_bis=="0") return 0;

		if(ipv.getNetworkAddress()==ipv_bis.getNetworkAddress()) {
			std::cout<<"Les deux adresses sont dans le même réseau"<<std::endl;
		}
		else std::cout<<"Les deux adresses ne sont pas dans le même réseau"<<std::endl;

    return 0;
}