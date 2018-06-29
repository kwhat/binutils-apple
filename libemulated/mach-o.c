#include <unistd.h>

int _NSGetExecutablePath(char *path, unsigned int *size)
{
   int bufsize = *size;
   int ret_size;
   ret_size = readlink("/proc/self/exe", path, bufsize);
   if (ret_size != -1)
   {
        *size = ret_size;
        path[ret_size]=0;
        return 0;
   }
   else
    return -1;
}
