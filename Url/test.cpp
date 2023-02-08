#include <iostream>

#include "Url.h"

#include "../../ConvertDataType/ConvertDataType/ConvertDataType.h"

int main()
{
	const std::string url_address("https://www.example.com/path/to/myfile.html?key1=value1&key2=value2#SomewhereInTheDocument«—±€¨Í¨÷¨›¨›¨Ì");

	printf("address\n\t[%s]\n\n", url_address.c_str());

	printf("protocol\n\t[%s]\n", MOONG::Url::getProtocol(url_address).c_str());

	printf("domain_name\n\t[%s]\n", MOONG::Url::getDomainName(url_address).c_str());

	std::string port;
	MOONG::Url::getPort(url_address, port);
	printf("port str\n\t[%s]\n", port.c_str());
	printf("port int\n\t[%d]\n", MOONG::Url::getPort(url_address));

	printf("path to the file\n\t[%s]\n", MOONG::Url::getPathToTheFile(url_address).c_str());
	
	printf("parameters\n\t[%s]\n", MOONG::Url::getParameters(url_address).c_str());

	printf("anchor\n\t[%s]\n\n", MOONG::Url::getAnchor(url_address).c_str());

	std::string encoded_uri = MOONG::Url::encodeURI("https://mozilla.org/?x=¨Í¨÷¨›¨›¨Ì");
	printf("encodeURI\n\t[%s]\n", encoded_uri.c_str());
	printf("decodeURI\n\t[%s]\n\n", MOONG::Url::decodeURI(encoded_uri).c_str());

	encoded_uri = MOONG::Url::encodeURIComponent(MOONG::ConvertDataType::string_to_utf8(url_address));
	printf("encodeURIComponent\n\t[%s]\n", encoded_uri.c_str());
	printf("decodeURIComponent\n\t[%s]\n", MOONG::ConvertDataType::utf8_to_string(MOONG::Url::decodeURIComponent(encoded_uri)).c_str());

	return 0;
}