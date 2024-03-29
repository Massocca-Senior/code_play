/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: data.proto */

#ifndef PROTOBUF_C_data_2eproto__INCLUDED
#define PROTOBUF_C_data_2eproto__INCLUDED

#include <protobuf-c/protobuf-c.h>

PROTOBUF_C__BEGIN_DECLS

#if PROTOBUF_C_VERSION_NUMBER < 1000000
# error This file was generated by a newer version of protoc-c which is incompatible with your libprotobuf-c headers. Please update your headers.
#elif 1003003 < PROTOBUF_C_MIN_COMPILER_VERSION
# error This file was generated by an older version of protoc-c which is incompatible with your libprotobuf-c headers. Please regenerate this file with a newer version of protoc-c.
#endif


typedef struct _Msg Msg;


/* --- enums --- */

typedef enum _MessageType {
  MESSAGE_TYPE__MSG_REQ = 0,
  MESSAGE_TYPE__MSG_REP = 1
    PROTOBUF_C__FORCE_ENUM_TO_BE_INT_SIZE(MESSAGE_TYPE)
} MessageType;

/* --- messages --- */

struct  _Msg
{
  ProtobufCMessage base;
  MessageType type;
  uint32_t seq;
  uint32_t data_type;
  ProtobufCBinaryData data;
};
#define MSG__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&msg__descriptor) \
    , MESSAGE_TYPE__MSG_REQ, 0, 0, {0,NULL} }


/* Msg methods */
void   msg__init
                     (Msg         *message);
size_t msg__get_packed_size
                     (const Msg   *message);
size_t msg__pack
                     (const Msg   *message,
                      uint8_t             *out);
size_t msg__pack_to_buffer
                     (const Msg   *message,
                      ProtobufCBuffer     *buffer);
Msg *
       msg__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   msg__free_unpacked
                     (Msg *message,
                      ProtobufCAllocator *allocator);
/* --- per-message closures --- */

typedef void (*Msg_Closure)
                 (const Msg *message,
                  void *closure_data);

/* --- services --- */


/* --- descriptors --- */

extern const ProtobufCEnumDescriptor    message_type__descriptor;
extern const ProtobufCMessageDescriptor msg__descriptor;

PROTOBUF_C__END_DECLS


#endif  /* PROTOBUF_C_data_2eproto__INCLUDED */
