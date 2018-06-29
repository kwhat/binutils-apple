/*
#include <mach/mach.h>
#include <mach/mach_error.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
//#include <sys/attr.h>
#include <errno.h>
#include <inttypes.h>

#include <mach/mach_host.h>
#include <mach/host_info.h>
*/

#include <mach/mach.h>

mach_port_t mach_task_self_ = 0;

char *mach_error_string(mach_error_t error_value)
{
  return "Unknown mach error";
}

mach_port_t mach_host_self(void)
{
  return 0;
}

kern_return_t host_info(host_t host, host_flavor_t flavor, host_info_t host_info_out, mach_msg_type_number_t *host_info_outCnt)
{
  if(flavor == HOST_BASIC_INFO) {
    host_basic_info_t      basic_info;

    basic_info = (host_basic_info_t) host_info_out;
    memset(basic_info, 0x00, sizeof(*basic_info));
    basic_info->cpu_type = EMULATED_HOST_CPU_TYPE;
    basic_info->cpu_subtype = EMULATED_HOST_CPU_SUBTYPE;
  }

  return 0;
}

kern_return_t mach_port_deallocate(ipc_space_t task, mach_port_name_t name)
{
  return 0;
}
