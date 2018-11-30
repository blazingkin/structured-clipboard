#include "output.h"

void handle_output(clip_options_t *options, repository_t * repository) {
    char *entry;
    entry = get_repository_entry(repository);
    if (entry == NULL){
        fprintf(stderr, "Could not find clip entry\n");
        exit(1);
        return;
    }
    printf("%s", entry);
}
