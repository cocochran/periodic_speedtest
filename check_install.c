#include "check_install.h"
#include <stdio.h>
#include <stdio.h>

int check_install(int code) {
    if (code > 0) return 1;

    // Check if Chocolatey is installed
    code = system("where choco >nul 2>&1");
    if (code != 0) {
        printf("Installing Chocolatey...\n");
        code = system("powershell -Command \"Set-ExecutionPolicy Bypass -Scope Process -Force; [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072; iex ((New-Object System.Net.WebClient).DownloadString('https://community.chocolatey.org/install.ps1'))\"");
        if (code != 0) return -1;
    }

    // Install speedtest-cli
    printf("Installing speedtest...\n");
    return system("choco install speedtest-cli -y --no-progress");
}   