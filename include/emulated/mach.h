#include <mach/mach.h>

char *mach_error_string(mach_error_t error_value);

mach_port_t mach_host_self(void);

kern_return_t host_info(host_t host, host_flavor_t flavor, host_info_t host_info_out, mach_msg_type_number_t *host_info_outCnt);

kern_return_t mach_port_deallocate(ipc_space_t task, mach_port_name_t name);
