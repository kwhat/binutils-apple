
#include <stddef.h>
#include <stdint.h>
#include <sys/time.h>

uint64_t  mach_absolute_time(void) {
  uint64_t time = 0;
  
  struct timeval tv;
  if (gettimeofday(&tv,NULL) == 0) {
    time = ((uint64_t) tv.tv_sec << 32)  | tv.tv_usec;
  }
  
  return time;
}
