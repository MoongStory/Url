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
			const int SUCCESS = 0;

			namespace FAILURE
			{
				const int PROTOCOL_NOT_FOUND = 1;
				const int PORT_NOT_FOUND = 2;
				const int PARAMETERS_NOT_FOUND = 3;
				const int ANCHOR_NOT_FOUND = 4;
				const int PATH_TO_THE_FILE_NOT_FOUND = 5;
			}
		}

		class Url
		{
		public:
			// return
			//		RETURN::SUCCESS
			//		RETURN::FAILURE::PROTOCOL_NOT_FOUND
			int getProtocol(const std::string url, std::string& output) const;

			// return
			//		RETURN::SUCCESS
			int getDomainName(std::string url, std::string& output) const;

			// return
			//		RETURN::SUCCESS
			//		RETURN::FAILURE::PORT_NOT_FOUND
			int getPort(std::string url, std::string& output) const;
			int getPort(std::string url, int* output) const;

			// return
			//		RETURN::SUCCESS
			//		RETURN::FAILURE::PATH_TO_THE_FILE_NOT_FOUND
			int getPathToTheFile(std::string url, std::string& output) const;

			// return
			//		RETURN::SUCCESS
			//		RETURN::FAILURE::PARAMETERS_NOT_FOUND
			int getParameters(std::string url, std::string& output) const;

			// return
			//		RETURN::SUCCESS
			//		RETURN::FAILURE::ANCHOR_NOT_FOUND
			int getAnchor(std::string url, std::string& output) const;
		};
	}
}

#endif _URL_H_