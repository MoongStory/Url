#include <iostream>

#include "Url.h"

#include "../../ConvertDataType/ConvertDataType/ConvertDataType.h"

int main()
{
	const std::string url_address("https://www.example.com/path/to/my file.html?key1=value1&key2=value2#Some where In The Document ÇÑ±Û ¬ê¬Ö¬Ý¬Ý¬í");
	//const std::string url_address("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890-_.!~*'();,/?:@&=+$#");

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

	// https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/encodeURI
	std::string encoded_uri = MOONG::Url::encodeURI(MOONG::ConvertDataType::string_to_utf8(url_address));
	printf("encodeURI\n\t[%s]\n", encoded_uri.c_str());
	printf("decodeURI\n\t[%s]\n\n", MOONG::ConvertDataType::utf8_to_string(MOONG::Url::decodeURI(encoded_uri)).c_str());

	// https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/encodeURIComponent
	encoded_uri = MOONG::Url::encodeURIComponent(MOONG::ConvertDataType::string_to_utf8(url_address));
	printf("encodeURIComponent\n\t[%s]\n", encoded_uri.c_str());
	printf("decodeURIComponent\n\t[%s]\n", MOONG::ConvertDataType::utf8_to_string(MOONG::Url::decodeURIComponent(encoded_uri)).c_str());

	return 0;
}