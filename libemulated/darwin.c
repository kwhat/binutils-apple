
#include <assert.h>
#include <errno.h>
#include <stddef.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <mach/mach.h>

vm_size_t   vm_page_size = 4096; // hardcoded to match expectations of darwin

int getattrlist(const char* a, void* b, void* c, size_t d, unsigned int e)
{
  return ENOTSUP;
}

kern_return_t vm_allocate(vm_map_t target_task, vm_address_t *address, vm_size_t size, int flags)
{
  vm_address_t addr = (vm_address_t) calloc(size, sizeof(char));
  if(addr == 0)
    return 1;

  *address = addr;

  return 0;
}

kern_return_t vm_deallocate(vm_map_t target_task, vm_address_t address, vm_size_t size)
{
  // FIXME It appears that ranlib is leaking memory...
  //free((void *) address);

  return 0;
}

kern_return_t vm_msync(vm_map_t target_task, vm_address_t address, vm_size_t size, vm_sync_t sync_flags)
{
  return 0;
}

kern_return_t host_statistics ( host_t host_priv, host_flavor_t flavor, host_info_t host_info_out, mach_msg_type_number_t *host_info_outCnt)
{
 return ENOTSUP;
}

kern_return_t map_fd(int fd, vm_offset_t offset, vm_offset_t *va, boolean_t findspace, vm_size_t size)
{
  void *addr = mmap(0, size, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FILE, fd, offset);
  if(addr == (void *) -1) {
    return 1;
  }
  
  *va = (vm_offset_t) addr;
  return 0;
}

void __assert_rtn(const char *func, const char *file, int line, const char *msg)
{
    __assert(msg, file, line);
}

int32_t OSAtomicAdd32( int32_t theAmount, volatile int32_t *theValue )
{
   __sync_fetch_and_add(theValue, theAmount);
   return *theValue; 
}
int64_t OSAtomicAdd64(int64_t theAmount, volatile int64_t *theValue) {
   __sync_fetch_and_add(theValue, theAmount);
   return *theValue; 
}
