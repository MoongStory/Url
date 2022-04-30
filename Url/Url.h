// https://github.com/MoongStory/Url

#if _MSC_VER > 1000
	#pragma once
#endif

#ifndef _URL_H_
#define _URL_H_

#include <iostream>

namespace MOONG
{
	namespace URL
	{
		namespace RETURN
		{
			static const int SUCCESS = 0;
			
			namespace FAILURE
			{
				static const int PORT_NOT_FOUND = 1;
			}
		}
	}
	
	class Url
	{
	public:
		static const std::string getProtocol(const std::string url);
		
		static const std::string getDomainName(const std::string url);
		
		// return
		//		RETURN::SUCCESS
		//		RETURN::FAILURE::PORT_NOT_FOUND
		static const int getPort(const std::string url, std::string& output);

		static const int getPort(const std::string url);

		static const std::string getPathToTheFile(const std::string url);
		
		static const std::string getParameters(const std::string url);
		
		static const std::string getAnchor(const std::string url);
	};
}

#endif _URL_H_