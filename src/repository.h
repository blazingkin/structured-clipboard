#ifndef CLIP_REPOSITORY_H_GUARD
#define CLIP_REPOSITORY_H_GUARD 1
#include <stdio.h>

typedef struct _data_repository {
    FILE * file_repository;
} repository_t;

char *get_repository_entry(repository_t *);

void add_to_repository(repository_t *);

void add_to_repository_at_pos(repository_t *repo, int pos);

size_t repository_size(repository_t *repo);


#endif
