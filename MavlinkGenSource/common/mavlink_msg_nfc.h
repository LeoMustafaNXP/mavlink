#pragma once
// MESSAGE NFC PACKING

#define MAVLINK_MSG_ID_NFC 335

MAVPACKED(
typedef struct __mavlink_nfc_t {
 uint8_t nfc_id[8]; /*<  NFC ID from Tag.*/
 uint8_t data_id; /*<  Data ID*/
 uint8_t data_len; /*<  Data LEN*/
 uint8_t data_nr; /*<  Data NR*/
 uint8_t data[200]; /*<  Data on NFC Tag.*/
}) mavlink_nfc_t;

#define MAVLINK_MSG_ID_NFC_LEN 211
#define MAVLINK_MSG_ID_NFC_MIN_LEN 211
#define MAVLINK_MSG_ID_335_LEN 211
#define MAVLINK_MSG_ID_335_MIN_LEN 211

#define MAVLINK_MSG_ID_NFC_CRC 107
#define MAVLINK_MSG_ID_335_CRC 107

#define MAVLINK_MSG_NFC_FIELD_NFC_ID_LEN 8
#define MAVLINK_MSG_NFC_FIELD_DATA_LEN 200

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_NFC { \
    335, \
    "NFC", \
    5, \
    {  { "nfc_id", NULL, MAVLINK_TYPE_UINT8_T, 8, 0, offsetof(mavlink_nfc_t, nfc_id) }, \
         { "data_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_nfc_t, data_id) }, \
         { "data_len", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_nfc_t, data_len) }, \
         { "data_nr", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_nfc_t, data_nr) }, \
         { "data", NULL, MAVLINK_TYPE_UINT8_T, 200, 11, offsetof(mavlink_nfc_t, data) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_NFC { \
    "NFC", \
    5, \
    {  { "nfc_id", NULL, MAVLINK_TYPE_UINT8_T, 8, 0, offsetof(mavlink_nfc_t, nfc_id) }, \
         { "data_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_nfc_t, data_id) }, \
         { "data_len", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_nfc_t, data_len) }, \
         { "data_nr", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_nfc_t, data_nr) }, \
         { "data", NULL, MAVLINK_TYPE_UINT8_T, 200, 11, offsetof(mavlink_nfc_t, data) }, \
         } \
}
#endif

/**
 * @brief Pack a nfc message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param nfc_id  NFC ID from Tag.
 * @param data_id  Data ID
 * @param data_len  Data LEN
 * @param data_nr  Data NR
 * @param data  Data on NFC Tag.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_nfc_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               const uint8_t *nfc_id, uint8_t data_id, uint8_t data_len, uint8_t data_nr, const uint8_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_NFC_LEN];
    _mav_put_uint8_t(buf, 8, data_id);
    _mav_put_uint8_t(buf, 9, data_len);
    _mav_put_uint8_t(buf, 10, data_nr);
    _mav_put_uint8_t_array(buf, 0, nfc_id, 8);
    _mav_put_uint8_t_array(buf, 11, data, 200);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_NFC_LEN);
#else
    mavlink_nfc_t packet;
    packet.data_id = data_id;
    packet.data_len = data_len;
    packet.data_nr = data_nr;
    mav_array_memcpy(packet.nfc_id, nfc_id, sizeof(uint8_t)*8);
    mav_array_memcpy(packet.data, data, sizeof(uint8_t)*200);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_NFC_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_NFC;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_NFC_MIN_LEN, MAVLINK_MSG_ID_NFC_LEN, MAVLINK_MSG_ID_NFC_CRC);
}

/**
 * @brief Pack a nfc message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param nfc_id  NFC ID from Tag.
 * @param data_id  Data ID
 * @param data_len  Data LEN
 * @param data_nr  Data NR
 * @param data  Data on NFC Tag.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_nfc_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   const uint8_t *nfc_id,uint8_t data_id,uint8_t data_len,uint8_t data_nr,const uint8_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_NFC_LEN];
    _mav_put_uint8_t(buf, 8, data_id);
    _mav_put_uint8_t(buf, 9, data_len);
    _mav_put_uint8_t(buf, 10, data_nr);
    _mav_put_uint8_t_array(buf, 0, nfc_id, 8);
    _mav_put_uint8_t_array(buf, 11, data, 200);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_NFC_LEN);
#else
    mavlink_nfc_t packet;
    packet.data_id = data_id;
    packet.data_len = data_len;
    packet.data_nr = data_nr;
    mav_array_memcpy(packet.nfc_id, nfc_id, sizeof(uint8_t)*8);
    mav_array_memcpy(packet.data, data, sizeof(uint8_t)*200);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_NFC_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_NFC;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_NFC_MIN_LEN, MAVLINK_MSG_ID_NFC_LEN, MAVLINK_MSG_ID_NFC_CRC);
}

/**
 * @brief Encode a nfc struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param nfc C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_nfc_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_nfc_t* nfc)
{
    return mavlink_msg_nfc_pack(system_id, component_id, msg, nfc->nfc_id, nfc->data_id, nfc->data_len, nfc->data_nr, nfc->data);
}

/**
 * @brief Encode a nfc struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param nfc C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_nfc_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_nfc_t* nfc)
{
    return mavlink_msg_nfc_pack_chan(system_id, component_id, chan, msg, nfc->nfc_id, nfc->data_id, nfc->data_len, nfc->data_nr, nfc->data);
}

/**
 * @brief Send a nfc message
 * @param chan MAVLink channel to send the message
 *
 * @param nfc_id  NFC ID from Tag.
 * @param data_id  Data ID
 * @param data_len  Data LEN
 * @param data_nr  Data NR
 * @param data  Data on NFC Tag.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_nfc_send(mavlink_channel_t chan, const uint8_t *nfc_id, uint8_t data_id, uint8_t data_len, uint8_t data_nr, const uint8_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_NFC_LEN];
    _mav_put_uint8_t(buf, 8, data_id);
    _mav_put_uint8_t(buf, 9, data_len);
    _mav_put_uint8_t(buf, 10, data_nr);
    _mav_put_uint8_t_array(buf, 0, nfc_id, 8);
    _mav_put_uint8_t_array(buf, 11, data, 200);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_NFC, buf, MAVLINK_MSG_ID_NFC_MIN_LEN, MAVLINK_MSG_ID_NFC_LEN, MAVLINK_MSG_ID_NFC_CRC);
#else
    mavlink_nfc_t packet;
    packet.data_id = data_id;
    packet.data_len = data_len;
    packet.data_nr = data_nr;
    mav_array_memcpy(packet.nfc_id, nfc_id, sizeof(uint8_t)*8);
    mav_array_memcpy(packet.data, data, sizeof(uint8_t)*200);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_NFC, (const char *)&packet, MAVLINK_MSG_ID_NFC_MIN_LEN, MAVLINK_MSG_ID_NFC_LEN, MAVLINK_MSG_ID_NFC_CRC);
#endif
}

/**
 * @brief Send a nfc message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_nfc_send_struct(mavlink_channel_t chan, const mavlink_nfc_t* nfc)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_nfc_send(chan, nfc->nfc_id, nfc->data_id, nfc->data_len, nfc->data_nr, nfc->data);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_NFC, (const char *)nfc, MAVLINK_MSG_ID_NFC_MIN_LEN, MAVLINK_MSG_ID_NFC_LEN, MAVLINK_MSG_ID_NFC_CRC);
#endif
}

#if MAVLINK_MSG_ID_NFC_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_nfc_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const uint8_t *nfc_id, uint8_t data_id, uint8_t data_len, uint8_t data_nr, const uint8_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 8, data_id);
    _mav_put_uint8_t(buf, 9, data_len);
    _mav_put_uint8_t(buf, 10, data_nr);
    _mav_put_uint8_t_array(buf, 0, nfc_id, 8);
    _mav_put_uint8_t_array(buf, 11, data, 200);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_NFC, buf, MAVLINK_MSG_ID_NFC_MIN_LEN, MAVLINK_MSG_ID_NFC_LEN, MAVLINK_MSG_ID_NFC_CRC);
#else
    mavlink_nfc_t *packet = (mavlink_nfc_t *)msgbuf;
    packet->data_id = data_id;
    packet->data_len = data_len;
    packet->data_nr = data_nr;
    mav_array_memcpy(packet->nfc_id, nfc_id, sizeof(uint8_t)*8);
    mav_array_memcpy(packet->data, data, sizeof(uint8_t)*200);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_NFC, (const char *)packet, MAVLINK_MSG_ID_NFC_MIN_LEN, MAVLINK_MSG_ID_NFC_LEN, MAVLINK_MSG_ID_NFC_CRC);
#endif
}
#endif

#endif

// MESSAGE NFC UNPACKING


/**
 * @brief Get field nfc_id from nfc message
 *
 * @return  NFC ID from Tag.
 */
static inline uint16_t mavlink_msg_nfc_get_nfc_id(const mavlink_message_t* msg, uint8_t *nfc_id)
{
    return _MAV_RETURN_uint8_t_array(msg, nfc_id, 8,  0);
}

/**
 * @brief Get field data_id from nfc message
 *
 * @return  Data ID
 */
static inline uint8_t mavlink_msg_nfc_get_data_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field data_len from nfc message
 *
 * @return  Data LEN
 */
static inline uint8_t mavlink_msg_nfc_get_data_len(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  9);
}

/**
 * @brief Get field data_nr from nfc message
 *
 * @return  Data NR
 */
static inline uint8_t mavlink_msg_nfc_get_data_nr(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  10);
}

/**
 * @brief Get field data from nfc message
 *
 * @return  Data on NFC Tag.
 */
static inline uint16_t mavlink_msg_nfc_get_data(const mavlink_message_t* msg, uint8_t *data)
{
    return _MAV_RETURN_uint8_t_array(msg, data, 200,  11);
}

/**
 * @brief Decode a nfc message into a struct
 *
 * @param msg The message to decode
 * @param nfc C-struct to decode the message contents into
 */
static inline void mavlink_msg_nfc_decode(const mavlink_message_t* msg, mavlink_nfc_t* nfc)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_nfc_get_nfc_id(msg, nfc->nfc_id);
    nfc->data_id = mavlink_msg_nfc_get_data_id(msg);
    nfc->data_len = mavlink_msg_nfc_get_data_len(msg);
    nfc->data_nr = mavlink_msg_nfc_get_data_nr(msg);
    mavlink_msg_nfc_get_data(msg, nfc->data);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_NFC_LEN? msg->len : MAVLINK_MSG_ID_NFC_LEN;
        memset(nfc, 0, MAVLINK_MSG_ID_NFC_LEN);
    memcpy(nfc, _MAV_PAYLOAD(msg), len);
#endif
}
