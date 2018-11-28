#include "repository.h"

/* Returns if the header is valid */
bool verify_header(repository_t *repo) {
    int err = 0;
    if (repo->header == NULL) {
        repo->header = calloc(1, sizeof(file_repository_header_t));
        err = fread(repo->header, sizeof(file_repository_header_t), 1, repo->file_repository);
        if (err < sizeof(file_repository_header_t)) {
            return false;
        }
    }
    return true;
}

/* Creates a new empty file */
/* returns false if there was an error */
bool initialize_file(FILE *repo_file) {
    file_repository_header_t header = {'\0'};
    char *magic = "CLIPY!!";
    header.major = MAJOR_VERSION;
    header.minor = MINOR_VERSION;
    header.entry_count = 0;
    memcpy(&header.magic, magic, strlen(magic));
    if (fwrite(&header, sizeof(file_repository_header_t), 1, repo_file) < sizeof(file_repository_header_t)) {
        return false;
    }
    return true;
}

char *get_repository_entry(repository_t *repo){
    if (!verify_header(repo)){
        fprintf(stderr, "File repository has invalid header");
    }
    return NULL;
}

void add_to_repository(repository_t *repo){
    if (!verify_header(repo)) {
        if (!initialize_file(repo->file_repository)) {
            fprintf(stderr, "Failed to initialize file repository\n");
            exit(1);
        }
    }

}

void add_to_repository_at_pos(repository_t *repo, int pos){
    if (!verify_header(repo)) {
        if (!initialize_file(repo->file_repository)) {
            fprintf(stderr, "Failed to initialize file repository\n");
        }
    }
}



size_t repository_size(repository_t *repo){
    return 0;
}
