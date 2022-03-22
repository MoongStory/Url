#include <iostream>

#include "Url.h"

int main()
{
	const std::string url_address("http://www.example.com:80/path/to/myfile.html?key1=value1&key2=value2#SomewhereInTheDocument");

	printf("address\n\t[%s]\n\n", url_address.c_str());

	MOONG::URL::Url url;

	std::string protocol;
	url.getProtocol(url_address, protocol);
	printf("protocol\n\t[%s]\n", protocol.c_str());

	std::string domain_name;
	url.getDomainName(url_address, domain_name);
	printf("domain_name\n\t[%s]\n", domain_name.c_str());

	std::string port_str;
	int port_int = 0;
	url.getPort(url_address, port_str);
	printf("port str\n\t[%s]\n", port_str.c_str());
	url.getPort(url_address, &port_int);
	printf("port int\n\t[%d]\n", port_int);

	std::string path_to_the_file;
	url.getPathToTheFile(url_address, path_to_the_file);
	printf("path to the file\n\t[%s]\n", path_to_the_file.c_str());

	std::string parameters;
	url.getParameters(url_address, parameters);
	printf("parameters\n\t[%s]\n", parameters.c_str());

	std::string anchor;
	url.getAnchor(url_address, anchor);
	printf("anchor\n\t[%s]\n", anchor.c_str());

	return 0;
}