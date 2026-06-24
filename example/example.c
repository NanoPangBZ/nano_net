#include "nano_net.h"

int main(void)
{
    nano_net_msg_t msg;

    DEFINE_NANO_NET_MSG_ID_DATA( NANO_NET_MSG_ID_PING , data );
    data.timestamp = 123456789;

    LOAD_NANO_NET_MSG_ID_ACK_DATA( NANO_NET_MSG_ID_PING , &data , ack_data );

    msg.msg_id = NANO_NET_MSG_ID_PING;
    msg.data = (uint8_t*)&data;
    msg.data_len = sizeof(data);
    msg.is_ack = 1;
    msg.need_ack = 0;



    return 0;
}
