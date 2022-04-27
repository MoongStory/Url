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
				static const int PROTOCOL_NOT_FOUND = 1;
				static const int PORT_NOT_FOUND = 2;
				static const int PARAMETERS_NOT_FOUND = 3;
				static const int ANCHOR_NOT_FOUND = 4;
				static const int PATH_TO_THE_FILE_NOT_FOUND = 5;
			}
		}

		class Url
		{
		public:
			// return
			//		RETURN::SUCCESS
			//		RETURN::FAILURE::PROTOCOL_NOT_FOUND
			static int getProtocol(const std::string url, std::string& output);

			// return
			//		RETURN::SUCCESS
			static int getDomainName(std::string url, std::string& output);

			// return
			//		RETURN::SUCCESS
			//		RETURN::FAILURE::PORT_NOT_FOUND
			static int getPort(std::string url, std::string& output);
			static int getPort(std::string url, int* output);

			// return
			//		RETURN::SUCCESS
			//		RETURN::FAILURE::PATH_TO_THE_FILE_NOT_FOUND
			static int getPathToTheFile(std::string url, std::string& output);

			// return
			//		RETURN::SUCCESS
			//		RETURN::FAILURE::PARAMETERS_NOT_FOUND
			static int getParameters(std::string url, std::string& output);

			// return
			//		RETURN::SUCCESS
			//		RETURN::FAILURE::ANCHOR_NOT_FOUND
			static int getAnchor(std::string url, std::string& output);
		};
	}
}

#endif _URL_H_