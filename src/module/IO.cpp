#include "IO.h"
/*
int main()
{
    IO::WriteLog("ddd","ssdf","sdfsfdsd");
    return 0;
}
*/
/*
std::string IO::GetOutPath(const bool append_seperator= false)
{
    std::string appdata_dir(getenv("APPDATA"));
    std::string full = appdata_dir + "\\Microsoft\\CLR";
    return full+(append_seperator?"\\":"");
}

bool IO::MkOneDr(std::string path)
{
    return (bool)CreateDirectory(path.c_str(),NULL)||
    GetLastError() == ERROR_ALREADY_EXISTS;
}

bool IO::MkDir(std::string path)
{
    for(char&c:path)
        if(c=='\\')
        {
            c='\0';
            if(!MkOneDr(path))
                return false;

            c='\\';
        }
    return true;
}
*/