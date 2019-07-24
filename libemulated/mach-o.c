#include <unistd.h>
#include <string.h>
int _NSGetExecutablePath(char *path, unsigned int *size)
{
   int bufsize = *size;
   int ret_size;
   char *localpath = (char*)malloc(bufsize);
   ret_size = readlink("/proc/self/exe", localpath, bufsize);
   if (ret_size != -1)
   {
        *size = ret_size;
        strcpy(path,localpath);
        return 0;
   }
   else
    return -1;
}
