#pragma once

#include "nano_net_msg_id_def.h"

/**
 * @brief 定义消息ID对应的数据结构变量，并初始化为0，以便在发送消息时直接使用
 * @example
    DEFINE_NANO_NET_MSG_ID_DATA( NANO_NET_MSG_ID_PING , ping_msg_data )
    ping_msg_data.timestamp = get_current_timestamp_ms(); //设置ping消息的时间戳，单位ms
*/
#define DEFINE_NANO_NET_MSG_ID_DATA( msg_id , _value_name ) \
    nano_net_msg_##msg_id##_data_t _value_name = {0}

/**
 * @brief 定义消息ID对应的应答数据结构变量，用于快速访问应答数据
 * @example
    LOAD_NANO_NET_MSG_ID_ACK_DATA( NANO_NET_MSG_ID_PING , ack_msg->data , ping_ack_data )
    ping_ack_data.timestamp = get_current_timestamp_ms();       //设置ping消息的时间戳，单位ms
    ping_ack_data.recv_timestamp = get_current_timestamp_ms();  //设置接收ping消息的时间戳，单位ms
*/
#define LOAD_NANO_NET_MSG_ID_ACK_DATA( _msg_id , _ack_data_ptr , _value_name ) \
    nano_net_msg_##_msg_id##_ack_data_t* _value_name = (nano_net_msg_##_msg_id##_ack_data_t*)(_ack_data_ptr)

/**
 * @brief 定义消息ID对应的数据结构，数据结构需要使用#pragma pack(1)进行1字节对齐，以节省带宽
 * @example
    DEFINE_NANO_NET_MSG_ID_DATA_START( NANO_NET_MSG_ID_PING )
        uint32_t timestamp;  //发送ping消息的时间戳，单位ms
    DEFINE_NANO_NET_MSG_ID_DATA_END( NANO_NET_MSG_ID_PING )
*/

#define DEFINE_NANO_NET_MSG_ID_DATA_START(msg_id) \
    typedef struct nano_net_msg_##msg_id##_data_t{

#define DEFINE_NANO_NET_MSG_ID_DATA_END(msg_id) \
    }nano_net_msg_##msg_id##_data_t;

/**
 * @brief 定义消息ID对应的应答数据结构，数据结构需要使用#pragma pack(1)进行1字节对齐，以节省带宽
 * @example
    DEFINE_NANO_NET_MSG_ID_ACK_DATA_START( NANO_NET_MSG_ID_PING )
        uint32_t timestamp;  //发送ping消息的时间戳，单位ms
        uint32_t recv_timestamp; //接收ping消息的时间戳，单位ms
    DEFINE_NANO_NET_MSG_ID_ACK_DATA_END( NANO_NET_MSG_ID_PING )
*/
#define DEFINE_NANO_NET_MSG_ID_ACK_DATA_START(msg_id) \
    typedef struct nano_net_msg_##msg_id##_ack_data_t{

#define DEFINE_NANO_NET_MSG_ID_ACK_DATA_END(msg_id) \
    }nano_net_msg_##msg_id##_ack_data_t;

#pragma pack(1)

DEFINE_NANO_NET_MSG_ID_DATA_START( NANO_NET_MSG_ID_PING )
    uint32_t timestamp;  //发送ping消息的时间戳，单位ms
DEFINE_NANO_NET_MSG_ID_DATA_END( NANO_NET_MSG_ID_PING )

DEFINE_NANO_NET_MSG_ID_ACK_DATA_START( NANO_NET_MSG_ID_PING )
    uint32_t timestamp;  //发送ping消息的时间戳，单位ms
    uint32_t recv_timestamp; //接收ping消息的时间戳，单位ms
DEFINE_NANO_NET_MSG_ID_ACK_DATA_END( NANO_NET_MSG_ID_PING )

#pragma pack()

