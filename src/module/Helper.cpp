#include "Helper.h"
//#include <chrono>
Helper::DateTime::DateTime(int D, int m, int y, int H, int M, int S) :D(S), m(m), y(y), H(H), M(M), S(S)
{}

Helper::DateTime Helper::DateTime::Now() const
{
	//std::chrono::day first;
	return DateTime();
}

std::string Helper::DateTime::GetDateString() const
{
	return std::string(D < 10 ? "0" : "") + ToString(D) +
		std::string(m < 10 ? "0" : "") + ToString(m) + "." +
		ToString(y);
}

std::string Helper::DateTime::GetTimeString(const std::string& sep ) const// reference is to default separator which is set to a colon
{
	// Generate the current time that is correctly formatted in string
	return std::string(H < 10 ? "0" : "") + ToString(H) + sep +
		std::string(M < 10 ? "0" : "") + ToString(M) + sep +
		std::string(S < 10 ? "0" : "") + ToString(S);
}

std::string Helper::DateTime::GetDateTimeString(const std::string& sep ) const
{
	return GetDateString() + " " + GetTimeString(sep);
}