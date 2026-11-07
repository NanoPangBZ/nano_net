#include "nano_net_packager.h"
#include "./package/nano_net_packager_impl_api_def.h"
#include <string.h>

#include "./package/nano_net_default_packager.h"

#include "ll_depend/nano_net_ll_heap.h"
#define MALLOC(_size)       nano_net_ll_heap_malloc(_size)
#define FREE(_ptr)          nano_net_ll_heap_free(_ptr)

#include "./nano_net_internal_cfg.h"
#define INFO_LOG(...)   NANO_NET_INFO_LOG(__VA_ARGS__)
#define WARN_LOG(...)   NANO_NET_WARN_LOG(__VA_ARGS__)
#define ERROR_LOG(...)  NANO_NET_ERROR_LOG(__VA_ARGS__)

typedef struct packager_t{
    nano_net_packager_impl_handle_t impl_handle;
    nano_net_packager_api_t*        api;
}packager_t;

packager_handle_t packager_create( packager_desc_t* desc )
{
    packager_t* packager = MALLOC(sizeof(packager_t));
    if (!packager) {
        ERROR_LOG("Failed to allocate memory for packager");
        return NULL;
    }
    memset(packager, 0, sizeof(packager_t));

    // 根据desc->type选择具体的打包器实现
    switch (desc->type)
    {
        case NANO_NET_PORT_ATTR_PACK_PROTOCOL_DEFAULT:
            packager->api = get_default_packager_api();
            break;
        default:
            WARN_LOG("Unsupported packager type: %d", desc->type);
            goto err_recycle;
    }

    if (!packager->api) {
        ERROR_LOG("Packager API is NULL");
        goto err_recycle;
    }

    packager->impl_handle = packager->api->create(desc);
    if (!packager->impl_handle) {
        ERROR_LOG("Failed to create packager implementation");
        goto err_recycle;
    }

    return (packager_handle_t)packager;

err_recycle:
    ERROR_LOG("Failed to create packager(type=%d)", desc->type);
    //@todo...
    return NULL;
}

void packager_destroy( packager_handle_t packager )
{
    if (!packager) {
        return;
    }
    if (packager->api && packager->impl_handle) {
        packager->api->destroy(packager->impl_handle);
    }
    FREE(packager);
}

void packager_reset( packager_handle_t packager )
{
    if( packager == NULL )
    {
        return;
    }

    //假设每个打包器实现都有一个reset函数
    if( packager->api && packager->impl_handle && packager->api->reset )
    {
        packager->api->reset( packager->impl_handle );
    }
}

void packager_register_unpack_cb( packager_handle_t packager,
                                        void* user_ctx ,
                                        void (*unpack_cb)(void* user_ctx, msg_package_t* pkg) )
{
    if( packager == NULL || unpack_cb == NULL )
    {
        return;
    }

    packager->api->register_unpack_cb( packager->impl_handle, user_ctx, unpack_cb );
}

uint8_t* packager_pack( packager_handle_t packager, msg_package_t* pkgs , uint8_t pkgs_cnt,  uint32_t* out_size )
{
    return packager->api->pack( packager->impl_handle, pkgs, pkgs_cnt, out_size );
}

void packager_unpack( packager_handle_t packager, uint8_t* raw_data, uint16_t size )
{
    packager->api->unpack( packager->impl_handle, raw_data, size );
}
