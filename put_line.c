#include "put_line.h"

// The buffer and destination are both open.
// It is not the function's job to close the buffer.
// Destination should be in append mode.
int put_line(FILE* buffer, FILE* destination){
    rewind(buffer);

    int c;
    while ((c = fgetc(buffer)) != EOF) {
        if (fputc(c, destination) == EOF)
            return -1;
    }

    return ferror(buffer) ? -1 : 0;
}
