#ifndef CLIP_REPOSITORY_H_GUARD
#define CLIP_REPOSITORY_H_GUARD 1
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


/*
Info file
====
FILE REPO HEADER
ENTRY HEADER 1
ENTRY HEADER 2
||||||||||||||
||||||||||||||

*/

/*
Data File
===
Entry 1
Entry 2
|||
|||
|||

*/

#define HEADER_MAGIC ("CLIPPY!!")

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
    /* Tag given to clip entry */
    char tag[16];
    /* Saved for future fields */
    char reserved[48];
} file_repository_entry_header_t;

typedef struct _data_repository {
    FILE * info_file;
    FILE * data_file;
    file_repository_header_t *header;
} repository_t;

#include "clip.h"

char *get_repository_entry(repository_t *);

void add_to_repository(repository_t *, char *);

void add_to_repository_at_pos(repository_t *repo, int pos, char *);

size_t repository_size(repository_t *repo);

#endif
