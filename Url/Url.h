/*******************************************************************************
MIT License

Copyright (c) 2023 Moong

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*******************************************************************************/

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
		static const std::string get_protocol(const std::string url);
		
		static const std::string get_domain_name(const std::string url);
		
		// return
		//		RETURN::SUCCESS
		//		RETURN::FAILURE::PORT_NOT_FOUND
		static const int get_port(const std::string url, std::string& output);

		static const int get_port(const std::string url);

		static const std::string get_path_to_the_file(const std::string url);
		
		static const std::string get_parameters(const std::string url);
		
		static const std::string get_anchor(const std::string url);

		static const std::string encode_uri(const std::string& decoded);
		static const std::string decode_uri(const std::string& encoded);
		static const std::string encode_uri_component(const std::string& decoded);
		static const std::string decode_uri_component(const std::string& encoded);

	private:
		static const char from_hex(const char ch);
		static const char to_hex(const char code);

		static const std::string encode_uri_(const std::string& decoded, const bool use_component = false);
		static const std::string decode_uri_(const std::string& encoded);
	};
}

#endif _URL_H_