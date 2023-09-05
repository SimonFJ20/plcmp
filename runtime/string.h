#ifndef STRING_H
#define STRING_H

#include <stddef.h>
#include <stdint.h>

uint64_t fnv_hash(const char* data, size_t size);

typedef struct {
    size_t size;
    size_t capacity;
    char data[];
} StringBody;

typedef struct {
    StringBody* body;
} String;

typedef struct {
    _Bool ok;
    char value;
} StringPopResult;

String string_new(void);
void string_destroy(String* string);
void string_reserve(String* string, size_t size);
void string_push_one(String* string, char value);
void string_push_many(String* string, char* value, size_t amount);
StringPopResult string_pop(String* string);
char* string_at(const String* string, int64_t index);
uint64_t string_hash(const String* string);

#endif
