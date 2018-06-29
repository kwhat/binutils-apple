
#include <mach/mach_time.h>

kern_return_t mach_timebase_info(mach_timebase_info_t info) {
   info->numer = 1;
   info->denom = 1;
   
   return 0;
}
