#pragma once
// MESSAGE HEARTBEATSIGN PACKING

#define MAVLINK_MSG_ID_HEARTBEATSIGN 336

MAVPACKED(
typedef struct __mavlink_heartbeatsign_t {
 uint32_t custom_mode; /*<  A bitfield for use for autopilot-specific flags*/
 uint16_t signlen; /*<  lenght of the signature*/
 uint8_t type; /*<  Type of the MAV (quadrotor, helicopter, etc., up to 15 types, defined in MAV_TYPE ENUM)*/
 uint8_t autopilot; /*<  Autopilot type / class. defined in MAV_AUTOPILOT ENUM*/
 uint8_t base_mode; /*<  System mode bitfield, as defined by MAV_MODE_FLAG enum*/
 uint8_t system_status; /*<  System status flag, as defined by MAV_STATE enum*/
 uint8_t mavlink_version; /*<  MAVLink version, not writable by user, gets added by protocol because of magic data type: uint8_t_mavlink_version*/
 uint8_t sign[64]; /*<  signature of the message*/
}) mavlink_heartbeatsign_t;

#define MAVLINK_MSG_ID_HEARTBEATSIGN_LEN 75
#define MAVLINK_MSG_ID_HEARTBEATSIGN_MIN_LEN 75
#define MAVLINK_MSG_ID_336_LEN 75
#define MAVLINK_MSG_ID_336_MIN_LEN 75

#define MAVLINK_MSG_ID_HEARTBEATSIGN_CRC 95
#define MAVLINK_MSG_ID_336_CRC 95

#define MAVLINK_MSG_HEARTBEATSIGN_FIELD_SIGN_LEN 64

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_HEARTBEATSIGN { \
    336, \
    "HEARTBEATSIGN", \
    8, \
    {  { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_heartbeatsign_t, type) }, \
         { "autopilot", NULL, MAVLINK_TYPE_UINT8_T, 0, 7, offsetof(mavlink_heartbeatsign_t, autopilot) }, \
         { "base_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_heartbeatsign_t, base_mode) }, \
         { "custom_mode", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_heartbeatsign_t, custom_mode) }, \
         { "system_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_heartbeatsign_t, system_status) }, \
         { "mavlink_version", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_heartbeatsign_t, mavlink_version) }, \
         { "signlen", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_heartbeatsign_t, signlen) }, \
         { "sign", NULL, MAVLINK_TYPE_UINT8_T, 64, 11, offsetof(mavlink_heartbeatsign_t, sign) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_HEARTBEATSIGN { \
    "HEARTBEATSIGN", \
    8, \
    {  { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_heartbeatsign_t, type) }, \
         { "autopilot", NULL, MAVLINK_TYPE_UINT8_T, 0, 7, offsetof(mavlink_heartbeatsign_t, autopilot) }, \
         { "base_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_heartbeatsign_t, base_mode) }, \
         { "custom_mode", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_heartbeatsign_t, custom_mode) }, \
         { "system_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_heartbeatsign_t, system_status) }, \
         { "mavlink_version", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_heartbeatsign_t, mavlink_version) }, \
         { "signlen", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_heartbeatsign_t, signlen) }, \
         { "sign", NULL, MAVLINK_TYPE_UINT8_T, 64, 11, offsetof(mavlink_heartbeatsign_t, sign) }, \
         } \
}
#endif

/**
 * @brief Pack a heartbeatsign message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param type  Type of the MAV (quadrotor, helicopter, etc., up to 15 types, defined in MAV_TYPE ENUM)
 * @param autopilot  Autopilot type / class. defined in MAV_AUTOPILOT ENUM
 * @param base_mode  System mode bitfield, as defined by MAV_MODE_FLAG enum
 * @param custom_mode  A bitfield for use for autopilot-specific flags
 * @param system_status  System status flag, as defined by MAV_STATE enum
 * @param signlen  lenght of the signature
 * @param sign  signature of the message
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_heartbeatsign_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t type, uint8_t autopilot, uint8_t base_mode, uint32_t custom_mode, uint8_t system_status, uint16_t signlen, const uint8_t *sign)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_HEARTBEATSIGN_LEN];
    _mav_put_uint32_t(buf, 0, custom_mode);
    _mav_put_uint16_t(buf, 4, signlen);
    _mav_put_uint8_t(buf, 6, type);
    _mav_put_uint8_t(buf, 7, autopilot);
    _mav_put_uint8_t(buf, 8, base_mode);
    _mav_put_uint8_t(buf, 9, system_status);
    _mav_put_uint8_t(buf, 10, 3);
    _mav_put_uint8_t_array(buf, 11, sign, 64);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_HEARTBEATSIGN_LEN);
#else
    mavlink_heartbeatsign_t packet;
    packet.custom_mode = custom_mode;
    packet.signlen = signlen;
    packet.type = type;
    packet.autopilot = autopilot;
    packet.base_mode = base_mode;
    packet.system_status = system_status;
    packet.mavlink_version = 3;
    mav_array_memcpy(packet.sign, sign, sizeof(uint8_t)*64);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_HEARTBEATSIGN_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_HEARTBEATSIGN;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_HEARTBEATSIGN_MIN_LEN, MAVLINK_MSG_ID_HEARTBEATSIGN_LEN, MAVLINK_MSG_ID_HEARTBEATSIGN_CRC);
}

/**
 * @brief Pack a heartbeatsign message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param type  Type of the MAV (quadrotor, helicopter, etc., up to 15 types, defined in MAV_TYPE ENUM)
 * @param autopilot  Autopilot type / class. defined in MAV_AUTOPILOT ENUM
 * @param base_mode  System mode bitfield, as defined by MAV_MODE_FLAG enum
 * @param custom_mode  A bitfield for use for autopilot-specific flags
 * @param system_status  System status flag, as defined by MAV_STATE enum
 * @param signlen  lenght of the signature
 * @param sign  signature of the message
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_heartbeatsign_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t type,uint8_t autopilot,uint8_t base_mode,uint32_t custom_mode,uint8_t system_status,uint16_t signlen,const uint8_t *sign)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_HEARTBEATSIGN_LEN];
    _mav_put_uint32_t(buf, 0, custom_mode);
    _mav_put_uint16_t(buf, 4, signlen);
    _mav_put_uint8_t(buf, 6, type);
    _mav_put_uint8_t(buf, 7, autopilot);
    _mav_put_uint8_t(buf, 8, base_mode);
    _mav_put_uint8_t(buf, 9, system_status);
    _mav_put_uint8_t(buf, 10, 3);
    _mav_put_uint8_t_array(buf, 11, sign, 64);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_HEARTBEATSIGN_LEN);
#else
    mavlink_heartbeatsign_t packet;
    packet.custom_mode = custom_mode;
    packet.signlen = signlen;
    packet.type = type;
    packet.autopilot = autopilot;
    packet.base_mode = base_mode;
    packet.system_status = system_status;
    packet.mavlink_version = 3;
    mav_array_memcpy(packet.sign, sign, sizeof(uint8_t)*64);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_HEARTBEATSIGN_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_HEARTBEATSIGN;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_HEARTBEATSIGN_MIN_LEN, MAVLINK_MSG_ID_HEARTBEATSIGN_LEN, MAVLINK_MSG_ID_HEARTBEATSIGN_CRC);
}

/**
 * @brief Encode a heartbeatsign struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param heartbeatsign C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_heartbeatsign_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_heartbeatsign_t* heartbeatsign)
{
    return mavlink_msg_heartbeatsign_pack(system_id, component_id, msg, heartbeatsign->type, heartbeatsign->autopilot, heartbeatsign->base_mode, heartbeatsign->custom_mode, heartbeatsign->system_status, heartbeatsign->signlen, heartbeatsign->sign);
}

/**
 * @brief Encode a heartbeatsign struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param heartbeatsign C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_heartbeatsign_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_heartbeatsign_t* heartbeatsign)
{
    return mavlink_msg_heartbeatsign_pack_chan(system_id, component_id, chan, msg, heartbeatsign->type, heartbeatsign->autopilot, heartbeatsign->base_mode, heartbeatsign->custom_mode, heartbeatsign->system_status, heartbeatsign->signlen, heartbeatsign->sign);
}

/**
 * @brief Send a heartbeatsign message
 * @param chan MAVLink channel to send the message
 *
 * @param type  Type of the MAV (quadrotor, helicopter, etc., up to 15 types, defined in MAV_TYPE ENUM)
 * @param autopilot  Autopilot type / class. defined in MAV_AUTOPILOT ENUM
 * @param base_mode  System mode bitfield, as defined by MAV_MODE_FLAG enum
 * @param custom_mode  A bitfield for use for autopilot-specific flags
 * @param system_status  System status flag, as defined by MAV_STATE enum
 * @param signlen  lenght of the signature
 * @param sign  signature of the message
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_heartbeatsign_send(mavlink_channel_t chan, uint8_t type, uint8_t autopilot, uint8_t base_mode, uint32_t custom_mode, uint8_t system_status, uint16_t signlen, const uint8_t *sign)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_HEARTBEATSIGN_LEN];
    _mav_put_uint32_t(buf, 0, custom_mode);
    _mav_put_uint16_t(buf, 4, signlen);
    _mav_put_uint8_t(buf, 6, type);
    _mav_put_uint8_t(buf, 7, autopilot);
    _mav_put_uint8_t(buf, 8, base_mode);
    _mav_put_uint8_t(buf, 9, system_status);
    _mav_put_uint8_t(buf, 10, 3);
    _mav_put_uint8_t_array(buf, 11, sign, 64);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HEARTBEATSIGN, buf, MAVLINK_MSG_ID_HEARTBEATSIGN_MIN_LEN, MAVLINK_MSG_ID_HEARTBEATSIGN_LEN, MAVLINK_MSG_ID_HEARTBEATSIGN_CRC);
#else
    mavlink_heartbeatsign_t packet;
    packet.custom_mode = custom_mode;
    packet.signlen = signlen;
    packet.type = type;
    packet.autopilot = autopilot;
    packet.base_mode = base_mode;
    packet.system_status = system_status;
    packet.mavlink_version = 3;
    mav_array_memcpy(packet.sign, sign, sizeof(uint8_t)*64);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HEARTBEATSIGN, (const char *)&packet, MAVLINK_MSG_ID_HEARTBEATSIGN_MIN_LEN, MAVLINK_MSG_ID_HEARTBEATSIGN_LEN, MAVLINK_MSG_ID_HEARTBEATSIGN_CRC);
#endif
}

/**
 * @brief Send a heartbeatsign message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_heartbeatsign_send_struct(mavlink_channel_t chan, const mavlink_heartbeatsign_t* heartbeatsign)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_heartbeatsign_send(chan, heartbeatsign->type, heartbeatsign->autopilot, heartbeatsign->base_mode, heartbeatsign->custom_mode, heartbeatsign->system_status, heartbeatsign->signlen, heartbeatsign->sign);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HEARTBEATSIGN, (const char *)heartbeatsign, MAVLINK_MSG_ID_HEARTBEATSIGN_MIN_LEN, MAVLINK_MSG_ID_HEARTBEATSIGN_LEN, MAVLINK_MSG_ID_HEARTBEATSIGN_CRC);
#endif
}

#if MAVLINK_MSG_ID_HEARTBEATSIGN_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_heartbeatsign_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t type, uint8_t autopilot, uint8_t base_mode, uint32_t custom_mode, uint8_t system_status, uint16_t signlen, const uint8_t *sign)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, custom_mode);
    _mav_put_uint16_t(buf, 4, signlen);
    _mav_put_uint8_t(buf, 6, type);
    _mav_put_uint8_t(buf, 7, autopilot);
    _mav_put_uint8_t(buf, 8, base_mode);
    _mav_put_uint8_t(buf, 9, system_status);
    _mav_put_uint8_t(buf, 10, 3);
    _mav_put_uint8_t_array(buf, 11, sign, 64);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HEARTBEATSIGN, buf, MAVLINK_MSG_ID_HEARTBEATSIGN_MIN_LEN, MAVLINK_MSG_ID_HEARTBEATSIGN_LEN, MAVLINK_MSG_ID_HEARTBEATSIGN_CRC);
#else
    mavlink_heartbeatsign_t *packet = (mavlink_heartbeatsign_t *)msgbuf;
    packet->custom_mode = custom_mode;
    packet->signlen = signlen;
    packet->type = type;
    packet->autopilot = autopilot;
    packet->base_mode = base_mode;
    packet->system_status = system_status;
    packet->mavlink_version = 3;
    mav_array_memcpy(packet->sign, sign, sizeof(uint8_t)*64);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HEARTBEATSIGN, (const char *)packet, MAVLINK_MSG_ID_HEARTBEATSIGN_MIN_LEN, MAVLINK_MSG_ID_HEARTBEATSIGN_LEN, MAVLINK_MSG_ID_HEARTBEATSIGN_CRC);
#endif
}
#endif

#endif

// MESSAGE HEARTBEATSIGN UNPACKING


/**
 * @brief Get field type from heartbeatsign message
 *
 * @return  Type of the MAV (quadrotor, helicopter, etc., up to 15 types, defined in MAV_TYPE ENUM)
 */
static inline uint8_t mavlink_msg_heartbeatsign_get_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  6);
}

/**
 * @brief Get field autopilot from heartbeatsign message
 *
 * @return  Autopilot type / class. defined in MAV_AUTOPILOT ENUM
 */
static inline uint8_t mavlink_msg_heartbeatsign_get_autopilot(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  7);
}

/**
 * @brief Get field base_mode from heartbeatsign message
 *
 * @return  System mode bitfield, as defined by MAV_MODE_FLAG enum
 */
static inline uint8_t mavlink_msg_heartbeatsign_get_base_mode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field custom_mode from heartbeatsign message
 *
 * @return  A bitfield for use for autopilot-specific flags
 */
static inline uint32_t mavlink_msg_heartbeatsign_get_custom_mode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field system_status from heartbeatsign message
 *
 * @return  System status flag, as defined by MAV_STATE enum
 */
static inline uint8_t mavlink_msg_heartbeatsign_get_system_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  9);
}

/**
 * @brief Get field mavlink_version from heartbeatsign message
 *
 * @return  MAVLink version, not writable by user, gets added by protocol because of magic data type: uint8_t_mavlink_version
 */
static inline uint8_t mavlink_msg_heartbeatsign_get_mavlink_version(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  10);
}

/**
 * @brief Get field signlen from heartbeatsign message
 *
 * @return  lenght of the signature
 */
static inline uint16_t mavlink_msg_heartbeatsign_get_signlen(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  4);
}

/**
 * @brief Get field sign from heartbeatsign message
 *
 * @return  signature of the message
 */
static inline uint16_t mavlink_msg_heartbeatsign_get_sign(const mavlink_message_t* msg, uint8_t *sign)
{
    return _MAV_RETURN_uint8_t_array(msg, sign, 64,  11);
}

/**
 * @brief Decode a heartbeatsign message into a struct
 *
 * @param msg The message to decode
 * @param heartbeatsign C-struct to decode the message contents into
 */
static inline void mavlink_msg_heartbeatsign_decode(const mavlink_message_t* msg, mavlink_heartbeatsign_t* heartbeatsign)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    heartbeatsign->custom_mode = mavlink_msg_heartbeatsign_get_custom_mode(msg);
    heartbeatsign->signlen = mavlink_msg_heartbeatsign_get_signlen(msg);
    heartbeatsign->type = mavlink_msg_heartbeatsign_get_type(msg);
    heartbeatsign->autopilot = mavlink_msg_heartbeatsign_get_autopilot(msg);
    heartbeatsign->base_mode = mavlink_msg_heartbeatsign_get_base_mode(msg);
    heartbeatsign->system_status = mavlink_msg_heartbeatsign_get_system_status(msg);
    heartbeatsign->mavlink_version = mavlink_msg_heartbeatsign_get_mavlink_version(msg);
    mavlink_msg_heartbeatsign_get_sign(msg, heartbeatsign->sign);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_HEARTBEATSIGN_LEN? msg->len : MAVLINK_MSG_ID_HEARTBEATSIGN_LEN;
        memset(heartbeatsign, 0, MAVLINK_MSG_ID_HEARTBEATSIGN_LEN);
    memcpy(heartbeatsign, _MAV_PAYLOAD(msg), len);
#endif
}
