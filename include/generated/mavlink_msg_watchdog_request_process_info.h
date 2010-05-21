// MESSAGE WATCHDOG_REQUEST_PROCESS_INFO PACKING

#define MAVLINK_MSG_ID_WATCHDOG_REQUEST_PROCESS_INFO 163

typedef struct __mavlink_watchdog_request_process_info_t 
{
	uint8_t target_system_id; ///< Target system ID
	uint16_t watchdog_id; ///< Watchdog ID
	uint16_t process_id; ///< Process ID

} mavlink_watchdog_request_process_info_t;



/**
 * @brief Send a watchdog_request_process_info message
 *
 * @param target_system_id Target system ID
 * @param watchdog_id Watchdog ID
 * @param process_id Process ID
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_watchdog_request_process_info_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, uint8_t target_system_id, uint16_t watchdog_id, uint16_t process_id)
{
	msg->msgid = MAVLINK_MSG_ID_WATCHDOG_REQUEST_PROCESS_INFO;
	uint16_t i = 0;

	i += put_uint8_t_by_index(target_system_id, i, msg->payload); //Target system ID
	i += put_uint16_t_by_index(watchdog_id, i, msg->payload); //Watchdog ID
	i += put_uint16_t_by_index(process_id, i, msg->payload); //Process ID

	return mavlink_finalize_message(msg, system_id, component_id, i);
}

static inline uint16_t mavlink_msg_watchdog_request_process_info_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_watchdog_request_process_info_t* watchdog_request_process_info)
{
	return mavlink_msg_watchdog_request_process_info_pack(system_id, component_id, msg, watchdog_request_process_info->target_system_id, watchdog_request_process_info->watchdog_id, watchdog_request_process_info->process_id);
}

#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_watchdog_request_process_info_send(mavlink_channel_t chan, uint8_t target_system_id, uint16_t watchdog_id, uint16_t process_id)
{
	mavlink_message_t msg;
	mavlink_msg_watchdog_request_process_info_pack(mavlink_system.sysid, mavlink_system.compid, &msg, target_system_id, watchdog_id, process_id);
	mavlink_send_uart(chan, &msg);
}

#endif
// MESSAGE WATCHDOG_REQUEST_PROCESS_INFO UNPACKING

/**
 * @brief Get field target_system_id from watchdog_request_process_info message
 *
 * @return Target system ID
 */
static inline uint8_t mavlink_msg_watchdog_request_process_info_get_target_system_id(const mavlink_message_t* msg)
{
	return (uint8_t)(msg->payload)[0];
}

/**
 * @brief Get field watchdog_id from watchdog_request_process_info message
 *
 * @return Watchdog ID
 */
static inline uint16_t mavlink_msg_watchdog_request_process_info_get_watchdog_id(const mavlink_message_t* msg)
{
	generic_16bit r;
	r.b[1] = (msg->payload+sizeof(uint8_t))[0];
	r.b[0] = (msg->payload+sizeof(uint8_t))[1];
	return (uint16_t)r.s;
}

/**
 * @brief Get field process_id from watchdog_request_process_info message
 *
 * @return Process ID
 */
static inline uint16_t mavlink_msg_watchdog_request_process_info_get_process_id(const mavlink_message_t* msg)
{
	generic_16bit r;
	r.b[1] = (msg->payload+sizeof(uint8_t)+sizeof(uint16_t))[0];
	r.b[0] = (msg->payload+sizeof(uint8_t)+sizeof(uint16_t))[1];
	return (uint16_t)r.s;
}

static inline void mavlink_msg_watchdog_request_process_info_decode(const mavlink_message_t* msg, mavlink_watchdog_request_process_info_t* watchdog_request_process_info)
{
	watchdog_request_process_info->target_system_id = mavlink_msg_watchdog_request_process_info_get_target_system_id(msg);
	watchdog_request_process_info->watchdog_id = mavlink_msg_watchdog_request_process_info_get_watchdog_id(msg);
	watchdog_request_process_info->process_id = mavlink_msg_watchdog_request_process_info_get_process_id(msg);
}
