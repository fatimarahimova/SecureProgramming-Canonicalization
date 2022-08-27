#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void processFile(const char *path) {
    printf("Process file executes\n");
    char samplecommandtoexecute[100] = {"ls -la "};
    strcat(samplecommandtoexecute, path);
    int status = system(samplecommandtoexecute);
    return;
}

void main(int argc, char *argv[]) {
    const char *safepath = "/home";
    size_t spl = strlen(safepath);

    char *fn = argv[1];
    fn = realpath(fn, NULL);
    
    if (!strncmp(fn, safepath, spl)) {
        processFile(fn);
    }
    else {
        printf("Path specified is not valid!\n");
        return;
    }
    return;
}
