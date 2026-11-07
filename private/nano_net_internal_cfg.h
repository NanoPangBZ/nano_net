#pragma once

#if defined(__has_include)
#  if __has_include("nano_net_cfg.h")
#    include "nano_net_cfg.h"
#  else
#    include "nano_net_cfg_example.h"
#  endif
#else
/* armcc 等：由工程保证提供 nano_net_cfg.h，或改用编译选项指定 */
#  include "nano_net_cfg.h"
#endif

