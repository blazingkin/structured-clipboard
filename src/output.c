#include "output.h"

void handle_output(clip_options_t *options, repository_t * repository) {
    char *entry;
    entry = get_repository_entry(repository);
    printf("%s", entry);
}
