#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "put_line.h"
#include "run_speedtest.h"
#include "check_install.h"

int main(){
    if (check_install(system("speedtest-cli --version")) < 0) return -1;

    FILE* csv;
    FILE* p;
    p = popen("speedtest-cli --csv-header", "r");

    if (!p) return 1;
    csv = fopen("speedtest_data.csv", "w");

    put_line(p, csv);

    fclose(csv);
    pclose(p);

    int i = 0;

    while (1){
        csv = fopen("speedtest_data.csv", "a");
        run_speedtest(csv);
        fclose(csv);
        i++;
        if (i >= 5) break;
        sleep(17280);
    }
    return 0;
}
