#include "URL.h"

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
		output = "";

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

	if(port.length() <= 0)
	{
		return -1;	// ��Ʈ�� 0�� ��찡 �������� �����Ƿ� -1�� �ʱ�ȭ�Ѵ�.
	}
	else
	{
		return atoi(port.c_str());
	}
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
