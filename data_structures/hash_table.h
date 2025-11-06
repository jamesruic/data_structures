#pragma once

#include <stdbool.h>
#include <string.h>

//hash table: Name -> age
#define HASH_TABLE_SIZE 7
#define NAME_SIZE 64

typedef struct {
    char key[NAME_SIZE]; // person's name
    int value; // age of person
    bool used;
} HashEntry;

typedef struct {
    HashEntry table[HASH_TABLE_SIZE];
} HashMap;

void initHash(HashMap* map) {
    if (!map) return;

    for (int i = 0; i < HASH_TABLE_SIZE; ++i) {
        memset(map->table[i].key, 0, NAME_SIZE);
        map->table[i].value = 0;
        map->table[i].used = false;
    }
}

int keyHash(char* key) {
    //djb2 hash
    unsigned int hash = 5381;
    
    while (*key) {
        hash = ((hash << 5) + hash) + *key;
        key++;
    }
    return hash % HASH_TABLE_SIZE;
}

void insertHash(HashMap* map, char* key, int value) {
    if (!map) return;

    int index = keyHash(key);
    HashEntry* entry = NULL;
    for (int i = 0; i < HASH_TABLE_SIZE; ++i) {
        int probe = (index + i) % HASH_TABLE_SIZE;
        entry = &map->table[probe];
        if (!entry->used) {
            // set new entry
            
            //strncpy(entry->key, key, NAME_SIZE);
            //entry->key[NAME_SIZE - 1] = '\0';

            strncpy_s(entry->key, NAME_SIZE, key, NAME_SIZE - 1);

            entry->value = value;
            entry->used = true;
            return;
        }
        else if (0 == strncmp(key, entry->key, NAME_SIZE)) {
            //same key: replace new value
            entry->value = value;
            return;
        }
    }
}

//return value(age), if no return -1
bool getHash(HashMap* map, char* key, int* out) {
    if (!map) return false;

    int index = keyHash(key);
    for (int i = 0; i < HASH_TABLE_SIZE; ++i) {
        int probe = (index + i) % HASH_TABLE_SIZE;
        if (map->table[probe].used && 0 == strncmp(key, map->table[probe].key, NAME_SIZE)) {
            *out = map->table[probe].value;
            return true;
        }
    }
    *out = -1;
    return false;
}

bool removeHash(HashMap* map, char* key) {
    if (!map) return false;

    int index = keyHash(key);
    HashEntry* entry = NULL;
    for (int i = 0; i < HASH_TABLE_SIZE; ++i) {
        entry = &map->table[(index + i) % HASH_TABLE_SIZE];
        if (entry->used && 0 == strncmp(key, entry->key, NAME_SIZE)) {
            //remove hash entry
            memset(entry->key, 0, NAME_SIZE);
            entry->value = 0;
            entry->used = false;
            return true;
        }
    }
    return false;
}

bool existHash(HashMap* map, char* key) {
    if (!map) return false;

    int index = keyHash(key);
    for (int i = 0; i < HASH_TABLE_SIZE; ++i) {
        int probe = (index + i) % HASH_TABLE_SIZE;
        if (map->table[probe].used && 0 == strncmp(key, map->table[probe].key, NAME_SIZE))
            return true;
    }
    return false;
}

void printHash(HashMap* map) {
    if (!map) return;
    HashEntry *entry = NULL;
    printf("========== Print Hash ==========\n");
    for (int i = 0; i < HASH_TABLE_SIZE; ++i) {
        entry = &map->table[i];
        printf("map[%d], \"%s\", age: %d\n", i, (entry->used) ? entry->key : "", (entry->used) ? entry->value : 0);
    }
    printf("================================\n");
}