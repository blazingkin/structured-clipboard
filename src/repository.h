#ifndef CLIP_REPOSITORY_H_GUARD
#define CLIP_REPOSITORY_H_GUARD 1
#include <stdio.h>
#include <stdint.h>

typedef struct _data_repository {
    FILE * file_repository;
} repository_t;

char *get_repository_entry(repository_t *);

void add_to_repository(repository_t *);

void add_to_repository_at_pos(repository_t *repo, int pos);

size_t repository_size(repository_t *repo);

typedef struct _file_repository_header {
    uint64_t entries;
    /* Magic field is CLIPY!! */
    char magic[32];
    /* Major version number */
    uint16_t major;
    /* Minor version number */
    uint16_t minor;
} file_repository_header_t;

typedef struct _file_repository_entry_header {
    uint64_t bytes;
    /* Saved for future fields */
    char reserved[64];
} file_repository_entry_header_t;

#endif
