#ifndef CLIP_REPOSITORY_H_GUARD
#define CLIP_REPOSITORY_H_GUARD 1
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "clip.h"

/*
File Structure
====
FILE REPO HEADER
ENTRY HEADER 1
ENTRY HEADER 2
||||||||||||||
||||||||||||||
Entry 1
Entry 2
|||||||
|||||||

*/

typedef struct _file_repository_header {
    uint64_t entry_count;
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

typedef struct _data_repository {
    FILE * file_repository;
    file_repository_header_t *header;
} repository_t;

char *get_repository_entry(repository_t *);

void add_to_repository(repository_t *);

void add_to_repository_at_pos(repository_t *repo, int pos);

size_t repository_size(repository_t *repo);

#endif
