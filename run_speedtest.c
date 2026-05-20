#include "run_speedtest.h"
#include "put_line.h"

int run_speedtest(FILE* destination){
    FILE* p;
    p = popen("speedtest-cli --csv", "r");
    put_line(p, destination);
    pclose(p);
    return ferror(destination) ? -1 : 0;
}