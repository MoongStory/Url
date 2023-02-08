#include "URL.h"

#include <algorithm>	// std::transform 사용을 위해 필요.

const std::string MOONG::Url::getProtocol(const std::string url)
{
	std::string output = url;

	const char* separator_0 = "://";

	size_t position = output.find(separator_0);
	if(position != std::string::npos)
	{
		output = output.substr(0, position);
	}
	else
	{
		return "";
	}

	return output;
}

const std::string MOONG::Url::getDomainName(const std::string url)
{
	std::string output = url;

	const char* separator_0 = "://";
	const char* separator_1 = ":";
	const char* separator_2 = "/";
	const char* separator_3 = "#";

	size_t position = output.find(separator_0);
	if (position != std::string::npos)
	{
		output = output.substr(position + strlen(separator_0));
	}

	position = output.find(separator_1);
	if (position != std::string::npos)
	{
		output = output.substr(0, position);
	}

	position = output.find(separator_2);
	if (position != std::string::npos)
	{
		output = output.substr(0, position);
	}

	position = output.find(separator_3);
	if (position != std::string::npos)
	{
		output = output.substr(0, position);
	}

	return output;
}

const int MOONG::Url::getPort(const std::string url, std::string& output)
{
	output = url;

	std::transform(output.begin(), output.end(), output.begin(), ::tolower);

	bool is_https = output.find("https") != std::string::npos ? true : false;

	output = url;

	const char* separator_0 = "://";
	const char* separator_1 = ":";
	const char* separator_2 = "/";

	size_t position = output.find(separator_0);
	if (position != std::string::npos)
	{
		output = output.substr(position + strlen(separator_0));
	}

	position = output.find(separator_1);
	if (position != std::string::npos)
	{
		output = output.substr(position + strlen(separator_1));
	}
	else
	{
		if (is_https)
		{
			output = "443";	// https 기본 포트
		}
		else
		{
			output = "80";	// http 기본 포트
		}

		return MOONG::URL::RETURN::FAILURE::PORT_NOT_FOUND;
	}

	position = output.find(separator_2);
	if (position != std::string::npos)
	{
		output = output.substr(0, position);
	}

	return MOONG::URL::RETURN::SUCCESS;
}

const int MOONG::Url::getPort(const std::string url)
{
	std::string port;
	MOONG::Url::getPort(url, port);

	return atoi(port.c_str());
}

const std::string MOONG::Url::getPathToTheFile(const std::string url)
{
	std::string output = url;

	const char* separator_0 = "://";
	const char* separator_1 = "/";
	const char* separator_2 = "?";
	const char* separator_3 = "#";

	size_t position = output.find(separator_0);
	if(position != std::string::npos)
	{
		output = output.substr(position + strlen(separator_0));
	}

	position = output.find(separator_1);
	if(position != std::string::npos)
	{
		output = output.substr(position + strlen(separator_1));
	}
	else
	{
		return "";
	}

	if(output.length() <= 0)
	{
		return "";
	}

	position = output.find(separator_2);
	if (position != std::string::npos)
	{
		output = output.substr(0, position);
	}

	position = output.find(separator_3);
	if (position != std::string::npos)
	{
		output = output.substr(0, position);
	}

	return output;
}

const std::string MOONG::Url::getParameters(const std::string url)
{
	std::string output = url;

	const char* separator_0 = "?";
	const char* separator_1 = "#";

	size_t position = output.find(separator_0);
	if(position != std::string::npos)
	{
		output = output.substr(position + strlen(separator_0));
	}
	else
	{
		return "";
	}

	position = output.find(separator_1);
	if(position != std::string::npos)
	{
		output = output.substr(0, position);
	}

	return output;
}

const std::string MOONG::Url::getAnchor(std::string url)
{
	std::string output = url;

	const char* separator_0 = "#";

	size_t position = output.find(separator_0);
	if(position != std::string::npos)
	{
		output = output.substr(position + strlen(separator_0));
	}
	else
	{
		return "";
	}

	return output;
}

const std::string MOONG::Url::encodeURI(const std::string& decoded)
{
	return encodeURI_(decoded);
}

const std::string MOONG::Url::decodeURI(const std::string& encoded)
{
	return decodeURI_(encoded);
}

const std::string MOONG::Url::encodeURIComponent(const std::string& decoded)
{
	return encodeURI_(decoded, true);
}

const std::string MOONG::Url::decodeURIComponent(const std::string& encoded)
{
	return decodeURI_(encoded);
}

const char MOONG::Url::from_hex(const char ch)
{
	return isdigit(ch) ? ch - '0' : toupper(ch) - 'A' + 10;
}

const char MOONG::Url::to_hex(const char code)
{
	static const char hex[] = "0123456789ABCDEF";

	return hex[code & 15];
}

const std::string MOONG::Url::encodeURI_(const std::string& decoded, const bool use_component/* = false*/)
{
	std::string encode_uri;

	std::string exception_characters;
	exception_characters += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	exception_characters += "abcdefghijklmnopqrstuvwxyz";
	exception_characters += "0123456789";
	exception_characters += "-_.!~*'()";
	if (false == use_component)
	{
		exception_characters += ";/?:@&=+$,#";
	}

	for (size_t i = 0; i < decoded.length(); ++i) {
		if (exception_characters.find(decoded.at(i)) != std::string::npos)
		{
			encode_uri += decoded.at(i);
		}
		else if (decoded.at(i) == ' ')
		{
			encode_uri += '+';
		}
		else
		{
			encode_uri += '%';
			encode_uri += to_hex(decoded.at(i) >> 4);
			encode_uri += to_hex(decoded.at(i) & 15);
		}
	}

	return encode_uri;
}

const std::string MOONG::Url::decodeURI_(const std::string& encoded)
{
	std::string decode_uri;

	for (size_t i = 0; i < encoded.length(); ++i) {
		if (encoded.at(i) == '%')
		{
			if (encoded.at(i + 1) && encoded.at(i + 2))
			{
				decode_uri += from_hex(encoded.at(i + 1)) << 4 | from_hex(encoded.at(i + 2));
				i += 2;
			}
		}
		else if (encoded.at(i) == '+')
		{
			decode_uri += ' ';
		}
		else
		{
			decode_uri += encoded.at(i);
		}
	}

	return decode_uri;
}
