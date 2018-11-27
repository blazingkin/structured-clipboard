#include "clip.h"

int main (int argc, char *argv[]){
    clip_options_t options = {'\0'};
    parse_options(argc, argv, &options);

    return 0;
}

void parse_options(int argc, char *argv[], clip_options_t *result) {
    int i;
    for (i = 0; i < argc; i++){
        if (strcasecmp(argv[i], "-o") == 0 || strcasecmp(argv[i], "--out") == 0) {
            result->is_input = true;
        }
    }
}