
#ifndef HAVE_DARWIN
#define HAVE_DARWIN

#include <stddef.h>
#include <stdlib.h>
#include <mach/mach.h>

#ifdef __cplusplus
extern "C" {
#endif

int getattrlist(const char* a, void* b, void* c, size_t d, unsigned int e);

kern_return_t vm_allocate(vm_map_t target_task, vm_address_t *address, vm_size_t size, int flags);

kern_return_t vm_deallocate(vm_map_t target_task, vm_address_t address, vm_size_t size);

kern_return_t vm_msync(vm_map_t target_task, vm_address_t address, vm_size_t size, vm_sync_t sync_flags);

kern_return_t host_statistics ( host_t host_priv, host_flavor_t flavor, host_info_t host_info_out, mach_msg_type_number_t *host_info_outCnt);

kern_return_t map_fd(int fd, vm_offset_t offset, vm_offset_t *va, boolean_t findspace, vm_size_t size);

void __assert_rtn(const char *func, const char *file, int line, const char *msg);

int32_t OSAtomicAdd32( int32_t theAmount, volatile int32_t *theValue );

int64_t OSAtomicAdd64(int64_t theAmount, volatile int64_t *theValue);

#ifdef __cplusplus
}
#endif

#endif /* HAVE_DARWIN */
