#include "URL.h"

int MOONG::Url::getProtocol(const std::string url, std::string& output)
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

int MOONG::Url::getDomainName(std::string url, std::string& output)
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

int MOONG::Url::getPort(std::string url, std::string& output)
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

int MOONG::Url::getPort(std::string url, int* output)
{
	std::string port;

	int return_value = MOONG::Url::getPort(url, port);

	if(return_value != MOONG::URL::RETURN::SUCCESS)
	{
		*output = -1;	// ��Ʈ�� 0�� ��찡 �������� �����Ƿ� -1�� �ʱ�ȭ�Ѵ�.
	}
	else
	{
		*output = atoi(port.c_str());
	}

	return return_value;
}

int MOONG::Url::getPathToTheFile(std::string url, std::string& output)
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

int MOONG::Url::getParameters(std::string url, std::string& output)
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

int MOONG::Url::getAnchor(std::string url, std::string& output)
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
