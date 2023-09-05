#include "string.h"
#include <stdint.h>
#include <stdlib.h>

uint64_t fnv_hash(const char* data, size_t size)
{
    const uint64_t fnv_offset_basis = 0xcbf29ce484222325;
    const uint64_t fnv_prime = 0x100000001b3;

    uint64_t hash = fnv_offset_basis;
    for (size_t i = 0; i < size; ++i) {
        hash *= fnv_prime;
        hash ^= data[i];
    }
    return hash;
}

String string_new(void)
{
    StringBody* body = malloc(sizeof(StringBody));
    *body = (StringBody) {
        .size = 0,
        .capacity = 0,
    };
    return (String) { body };
}

void string_destroy(String* string) { free(string->body); }

void string_reserve(String* string, size_t size)
{
    if (string->body->capacity - string->body->size < size) {
        if (string->body->capacity == 0) {
            string->body->capacity = 8;
        }
        while (string->body->capacity - string->body->size < size) {
            string->body->capacity *= 2;
        }
        string->body = realloc(
            string->body,
            sizeof(StringBody) + sizeof(char) * string->body->capacity
        );
    }
}

void string_push_one(String* string, char value)
{
    string_reserve(string, 1);
    string->body->data[string->body->size] = value;
    string->body->size += 1;
}

void string_push_many(String* string, char* value, size_t amount)
{
    string_reserve(string, amount);
    for (size_t i = 0; i < amount; ++i) {
        string->body->data[string->body->size + i] = value[i];
    }
    string->body->size += amount;
}

StringPopResult string_pop(String* string)
{
    if (string->body->size == 0) {
        return (StringPopResult) { .ok = 0 };
    }
    string->body->size -= 1;
    return (StringPopResult) {
        .ok = 1,
        .value = string->body->data[string->body->size],
    };
}

char* string_at(const String* string, int64_t index)
{
    if (index < 0) {
        return string_at(string, string->body->size + index);
    }
    if (index >= (int64_t)string->body->size) {
        return ((void*)0);
    }
    return &string->body->data[index];
}

uint64_t string_hash(const String* string)
{
    return fnv_hash(string->body->data, string->body->size);
}
