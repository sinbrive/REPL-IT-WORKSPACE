#ifndef IpCalc_h
#define IpCalc_h

class ipv4 {

	public:
		ipv4(std::string ip, std::string cid);

		uint32_t getMaskInt();

		std::string getNetworkAddress();

		std::string getMask();

		std::string getBroadcastAddress() ;

		std::string getFirstAddress() ;

		std::string getLastAddress();

		uint32_t stringToUint(std::string str);

		std::string UintToString(const uint32_t str);


		int getNbHost();

	private:
		std::string IPv4;
		std::string cidr;

};
#endif