#include "nano_net_internal_cfg.h"

/**
 * @brief 编译器静态检查
*/

#ifdef NANO_NET_MAX_ROUTE_FORWARD_CNT
    #if NANO_NET_MAX_ROUTE_FORWARD_CNT > 17
        #error "NANO_NET_MAX_ROUTE_FORWARD_CNT must be less than 18"
    #endif
#endif
