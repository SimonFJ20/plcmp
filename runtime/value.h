#ifndef VALUE_H
#define VALUE_H

#include "string.h"
#include <stdbool.h>

typedef struct Value Value;

typedef struct {
    size_t size;
    size_t capacity;
    Value* data[];
} ArrayBody;

typedef struct {
    ArrayBody* body;
} Array;

Array array_new(void);
void array_reserve(Array* array, size_t size);
void array_push_one(Array* array, Value* value);
void array_push_many(Array* array, Value** value, size_t amount);
Value* array_pop(Array* array);
Value** array_at(Array* array, int64_t index);

typedef struct {
    uint64_t key_hash;
    Value* value;
} ObjectEntry;

typedef struct {
    size_t size;
    size_t capacity;
    ObjectEntry* entries;
    String* keys;
} ObjectBody;

typedef ObjectBody* Object;

Object object_new(void);
void object_destroy(Object* object);
void object_reserve(Object* object, size_t size);
void object_set(Object* object, const String* key, Value* value);
Value* object_at(const Object* object, const String* key);
bool object_contains(const Object* object, const String* key);

typedef enum {
    ValueType_I64,
    ValueType_F64,
    ValueType_String,
    ValueType_Pointer,
    ValueType_Array,
    ValueType_Object,
    ValueType_Function,
    ValueType_Builtin,
} ValueType;

struct Value {
    ValueType type;
    union {
        int64_t i64;
        double f64;
        String string;
        Value* pointer;
        Array array;
        Object object;
        uint64_t builtin;
    };
};

#endif
