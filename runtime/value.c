#include "value.h"
#include "string.h"
#include <stdint.h>
#include <stdlib.h>

Array array_new(void)
{
    ArrayBody* body = malloc(sizeof(ArrayBody));
    *body = (ArrayBody) {
        .size = 0,
        .capacity = 0,
    };
    return (Array) { body };
}

void array_reserve(Array* array, size_t size)
{
    if (array->body->capacity - array->body->size < size) {
        if (array->body->capacity == 0) {
            array->body->capacity = 8;
        }
        while (array->body->capacity - array->body->size < size) {
            array->body->capacity *= 2;
        }
        array->body = realloc(
            array->body,
            sizeof(ArrayBody) + sizeof(Value*) * array->body->capacity
        );
    }
}

void array_push_one(Array* array, Value* value)
{
    array_reserve(array, 1);
    array->body->data[array->body->size] = value;
    array->body->size += 1;
}

void array_push_many(Array* array, Value** value, size_t amount)
{
    array_reserve(array, amount);
    for (size_t i = 0; i < amount; ++i) {
        array->body->data[array->body->size + i] = value[i];
    }
    array->body->size += amount;
}

Value* array_pop(Array* array)
{
    if (array->body->size == 0) {
        return NULL;
    }
    array->body->size -= 1;
    return array->body->data[array->body->size];
}

Value** array_at(Array* array, int64_t index)
{
    if (index < 0) {
        return array_at(array, array->body->size + index);
    }
    if (index >= (int64_t)array->body->size) {
        return NULL;
    }
    return &array->body->data[index];
}

Object object_new(void)
{
    ObjectBody* body = malloc(sizeof(ObjectBody));
    *body = (ObjectBody) {
        .size = 0,
        .capacity = 0,
        .entries = NULL,
        .keys = NULL,
    };
    return (Object) { body };
}

void object_destroy(Object* object)
{
    if ((*object)->entries) {
        free((*object)->entries);
    }
    if ((*object)->keys) {
        for (size_t i = 0; i < (*object)->size; ++i) {
            string_destroy(&(*object)->keys[i]);
        }
    }
    free((*object));
}

void object_reserve(Object* object, size_t size)
{
    if ((*object)->capacity - (*object)->size < size) {
        if ((*object)->capacity == 0) {
            (*object)->capacity = 4;
        }
        while ((*object)->capacity - (*object)->size < size) {
            (*object)->capacity *= 2;
        }
        (*object)->entries = realloc(
            (*object)->entries, sizeof(ObjectEntry) * (*object)->capacity
        );
        (*object)->keys
            = realloc((*object)->keys, sizeof(String) * (*object)->capacity);
    }
}

void object_set(Object* object, const String* key, Value* value)
{
    uint64_t hash = string_hash(key);
}

Value* object_at(const Object* object, const String* key);

bool object_contains(const Object* object, const String* key);
