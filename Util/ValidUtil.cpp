#include "ValidUtil.h"

#include <winsock2.h>
#include <ws2tcpip.h>
#include <string>

#pragma comment(lib, "ws2_32.lib")

bool isValidIPv4(const std::string& ip) {
	sockaddr_in addr;
	return InetPton(AF_INET, ip.c_str(), &addr.sin_addr) == 1;
}

int ValidUtil::IsValidIp(const std::string & ipaddress)
{
	if (!isValidIPv4(ipaddress)) {
		return 0;
	}
	sockaddr_in addr;
	InetPton(AF_INET, ipaddress.c_str(), &addr.sin_addr);
	unsigned char firstOctet = *(unsigned char*)&addr.sin_addr.S_un.S_addr;
	if (firstOctet >= 224 && firstOctet <= 239) {
		return 2;
	}
	return 1;
}
