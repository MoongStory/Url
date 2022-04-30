#include <iostream>

#include "Url.h"

int main()
{
	const std::string url_address("http://www.example.com:80/path/to/myfile.html?key1=value1&key2=value2#SomewhereInTheDocument");

	printf("address\n\t[%s]\n\n", url_address.c_str());

	printf("protocol\n\t[%s]\n", MOONG::Url::getProtocol(url_address).c_str());

	printf("domain_name\n\t[%s]\n", MOONG::Url::getDomainName(url_address).c_str());

	printf("port str\n\t[%s]\n", MOONG::Url::getPort(url_address).c_str());
	int port_int = 0;
	MOONG::Url::getPort(url_address, &port_int);
	printf("port int\n\t[%d]\n", port_int);

	printf("path to the file\n\t[%s]\n", MOONG::Url::getPathToTheFile(url_address).c_str());
	
	printf("parameters\n\t[%s]\n", MOONG::Url::getParameters(url_address).c_str());

	printf("anchor\n\t[%s]\n", MOONG::Url::getAnchor(url_address).c_str());

	return 0;
}