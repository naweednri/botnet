#pragma once
#ifndef HELPER_H
#define HELPER_H

#include <ctime>
#include <string>
#include <sstream>
#include <fstream>

namespace Helper
{

	template <typename T>
	std::string ToString(const T&);


	//** warning
	//	DateTime struct used deprecated type of datetime.
	//	it need to be updated.

	struct DateTime
	{
		int D, m, y, M, H, S;
		DateTime()
		{
			
			time_t ms;
			time(&ms);
			struct tm* info = localtime(&ms);
			D = info->tm_mday;
			m = info->tm_mon + 1; // need to add 1 since january is represented 0
			y = 1900 + info->tm_year; // reference year since C came in the 70s and locatime returns time from that particular day until present day
			M = info->tm_min;
			H = info->tm_hour;
			S = info->tm_sec;
		}
		DateTime(int D, int m, int y, int H, int M, int S);
		DateTime(int D,int m,int y): D(D),m(m),y(y), H(0), M(0), S(0)
		{}
		DateTime Now() const;

		std::string GetDateString() const;
		std::string GetTimeString(const std::string& sep = ":") const;
		std::string GetDateTimeString(const std::string& sep = ":") const;
	};
}

template <typename T>
std::string Helper::ToString(const T& e)
{
	std::ostringstream s;
	return std::string("test");
}



#endif