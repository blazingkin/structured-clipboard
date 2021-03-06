#include "clip.h"

int main (int argc, char *argv[]){
    clip_options_t options = {'\0'};
    parse_options(argc, argv, &options);
    return execute_command(&options);
}

int execute_command(clip_options_t *options){
    FILE * repository_file;
    repository_t repository = {'\0'};
    repository_file = get_repository_file(options);
    repository.info_file = repository_file;

    /* Check if some error occurred */
    if (repository_file == NULL){
        perror("Could not open repository file");
        return 1;
    }

    if (options->is_input) {
        handle_input(options, &repository);
    }else{
        handle_output(options, &repository);
    }

    fclose(repository_file);
    return 0;
}

void parse_options(int argc, char *argv[], clip_options_t *result) {
    int i;
    for (i = 0; i < argc; i++){
        if (strcasecmp(argv[i], "-") == 0 || strcasecmp(argv[i], "-i") == 0 || strcasecmp(argv[i], "--in") == 0) {
            result->is_input = true;
        }
    }
    /* Temporarily set the repository file to clip.dat */
    result->repository_filename = "clip.info";
}

FILE * get_repository_file(clip_options_t *options){
    char *mode;
    if (options->is_input) {
        /* If we are getting input from the user, then we will have to write to the repository */
        mode = "ab+";
    }else{
        /* If we are outputting, then we will need information from the repository */
        /* We may also have to modify it */
        mode = "arb+";
    }
    return fopen(options->repository_filename, mode);
}
