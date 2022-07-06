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
