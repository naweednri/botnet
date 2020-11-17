#ifndef IO_H
#define IO_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
//#include <windows.h>
#include "Helper.h"


namespace IO
{
    /*
    std::string GetOutPath(const bool append_seperator );
    bool MkOneDr(std::string);
    bool MkDir(std::string);
    */
    template<typename T>
    void WriteLog(const T);
    template<typename T1,typename... T>
    void WriteLog(const T1,T...);
}
template<typename T>
void IO::WriteLog(const T parm)
{
    std::cout<<parm<<std::endl;
}
template<typename T1,typename... T>
void IO::WriteLog(const T1 first,T... parm)
{   
    std::cout<<first<<" ";
    IO::WriteLog(parm...);
}
#endif