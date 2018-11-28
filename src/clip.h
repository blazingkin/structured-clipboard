#ifndef CLIP_H_GUARD
#define CLIP_H_GUARD 1

#include <stdbool.h>
#include <strings.h>
#include <stdio.h>

#define MAJOR_VERSION 0
#define MINOR_VERSION 1

typedef struct _options {
    bool is_input;
    char *repository_filename;
} clip_options_t;

void parse_options(int , char **, clip_options_t *);
int execute_command(clip_options_t *);
FILE * get_repository_file(clip_options_t *);

#include "repository.h"
#include "input.h"
#include "output.h"

#endif
