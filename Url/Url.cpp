#include "URL.h"

int MOONG::URL::Url::getProtocol(const std::string url, std::string& output) const
{
	output.clear();

	const char* separator_0 = "://";

	size_t position = url.find(separator_0);
	if(position != std::string::npos)
	{
		output = url.substr(0, position);
	}
	else
	{
		return MOONG::URL::RETURN::FAILURE::PROTOCOL_NOT_FOUND;
	}

	return MOONG::URL::RETURN::SUCCESS;
}

int MOONG::URL::Url::getDomainName(std::string url, std::string& output) const
{
	output.clear();

	const char* separator_0 = "://";
	const char* separator_1 = ":";
	const char* separator_2 = "/";

	size_t position = url.find(separator_0);
	if(position != std::string::npos)
	{
		url = url.substr(position + strlen(separator_0));
	}

	position = url.find(separator_1);
	if(position != std::string::npos)
	{
		url = url.substr(0, position);
	}

	position = url.find(separator_2);
	if(position != std::string::npos)
	{
		url = url.substr(0, position);
	}

	output = url;

	return MOONG::URL::RETURN::SUCCESS;
}

int MOONG::URL::Url::getPort(std::string url, std::string& output) const
{
	output.clear();

	const char* separator_0 = "://";
	const char* separator_1 = ":";
	const char* separator_2 = "/";

	size_t position = url.find(separator_0);
	if(position != std::string::npos)
	{
		url = url.substr(position + strlen(separator_0));
	}

	position = url.find(separator_1);
	if(position != std::string::npos)
	{
		url = url.substr(position + strlen(separator_1));
	}
	else
	{
		return MOONG::URL::RETURN::FAILURE::PORT_NOT_FOUND;
	}

	position = url.find(separator_2);
	if(position != std::string::npos)
	{
		url = url.substr(0, position);
	}

	output = url;

	return MOONG::URL::RETURN::SUCCESS;
}

int MOONG::URL::Url::getPort(std::string url, int* output) const
{
	std::string port;

	int return_value = this->getPort(url, port);

	if(return_value != MOONG::URL::RETURN::SUCCESS)
	{
		*output = -1;	// 포트가 0인 경우가 있을수도 있으므로 -1로 초기화한다.
	}
	else
	{
		*output = atoi(port.c_str());
	}

	return return_value;
}

int MOONG::URL::Url::getPathToTheFile(std::string url, std::string& output) const
{
	output.clear();

	const char* separator_0 = "://";
	const char* separator_1 = "/";
	const char* separator_2 = "?";

	size_t position = url.find(separator_0);
	if(position != std::string::npos)
	{
		url = url.substr(position + strlen(separator_0));
	}

	position = url.find(separator_1);
	if(position != std::string::npos)
	{
		url = url.substr(position + strlen(separator_1));
	}
	else
	{
		return MOONG::URL::RETURN::FAILURE::PATH_TO_THE_FILE_NOT_FOUND;
	}

	if(url.length() <= 0)
	{
		return MOONG::URL::RETURN::FAILURE::PATH_TO_THE_FILE_NOT_FOUND;
	}

	position = url.find(separator_2);
	if(position != std::string::npos)
	{
		url = url.substr(0, position);
	}

	output = url;

	return MOONG::URL::RETURN::SUCCESS;
}

int MOONG::URL::Url::getParameters(std::string url, std::string& output) const
{
	output.clear();

	const char* separator_0 = "?";
	const char* separator_1 = "#";

	size_t position = url.find(separator_0);
	if(position != std::string::npos)
	{
		url = url.substr(position + strlen(separator_0));
	}
	else
	{
		return MOONG::URL::RETURN::FAILURE::PARAMETERS_NOT_FOUND;
	}

	position = url.find(separator_1);
	if(position != std::string::npos)
	{
		url = url.substr(0, position);
	}

	output = url;

	return MOONG::URL::RETURN::SUCCESS;
}

int MOONG::URL::Url::getAnchor(std::string url, std::string& output) const
{
	output.clear();

	const char* separator_0 = "#";

	size_t position = url.find(separator_0);
	if(position != std::string::npos)
	{
		url = url.substr(position + strlen(separator_0));
	}
	else
	{
		return MOONG::URL::RETURN::FAILURE::ANCHOR_NOT_FOUND;
	}

	output = url;

	return MOONG::URL::RETURN::SUCCESS;
}
