#include "repository.h"

/* Returns if the header is valid */
bool verify_header(repository_t *repo) {
    int err = 0;
    if (repo->header == NULL) {
        repo->header = calloc(1, sizeof(file_repository_header_t));
        rewind(repo->info_file);
        err = fread(repo->header, sizeof(file_repository_header_t), 1, repo->info_file);
        if (err < 1) {
            return false;
        }
    }
    return strcmp(repo->header->magic, HEADER_MAGIC) == 0;
}

/* Creates a new empty file */
/* returns false if there was an error */
bool initialize_repo(repository_t *repository) {
    FILE *repo_file = repository->info_file;
    file_repository_header_t header = {'\0'};
    char *magic = HEADER_MAGIC;
    header.major = MAJOR_VERSION;
    header.minor = MINOR_VERSION;
    header.entry_count = 0;
    memcpy(&header.magic, magic, strlen(magic));
    if (fseek(repo_file, 0, SEEK_SET) < 0){
        perror("Could not seek to beginning of repository file");
        return false;
    }
    if (fwrite(&header, sizeof(file_repository_header_t), 1, repo_file) < 1) {
        return false;
    }
    return true;
}

char *get_repository_entry(repository_t *repo){
    if (!verify_header(repo)){
        fprintf(stderr, "File repository has invalid header\n");
    }
    return NULL;
}

void add_to_repository(repository_t *repo, char * data){
    if (!verify_header(repo)) {
        if (!initialize_repo(repo)) {
            fprintf(stderr, "Failed to initialize file repository\n");
            exit(1);
        }
    }
}

void add_to_repository_at_pos(repository_t *repo, int pos, char * data){
    if (!verify_header(repo)) {
        if (!initialize_repo(repo)) {
            fprintf(stderr, "Failed to initialize file repository\n");
        }
    }
}



size_t repository_size(repository_t *repo){
    return 0;
}
