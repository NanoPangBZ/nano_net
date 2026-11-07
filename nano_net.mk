NANO_NET_ROOT_DIR := ${FRAMEWORK_ROOT_DIR}/nano_net

#nano_net源文件列表
SRC += $(NANO_NET_ROOT_DIR)/nano_net.c
SRC += $(NANO_NET_ROOT_DIR)/private/nano_net_port.c
SRC += $(NANO_NET_ROOT_DIR)/private/nano_net_packager.c
SRC += $(NANO_NET_ROOT_DIR)/private/nano_net_cfg_static_check.c
SRC += $(NANO_NET_ROOT_DIR)/private/lib/nano_net_crc16.c
SRC += $(NANO_NET_ROOT_DIR)/private/lib/nano_net_list.c
SRC += $(NANO_NET_ROOT_DIR)/private/lib/nano_net_ringbuf.c
SRC += $(NANO_NET_ROOT_DIR)/private/ll_depend/nano_net_ll_heap.c
SRC += $(NANO_NET_ROOT_DIR)/private/ll_depend/nano_net_ll_systime.c
SRC += $(NANO_NET_ROOT_DIR)/private/package/nano_net_default_packager.c
