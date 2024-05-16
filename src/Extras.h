#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>

#https://github.com/cr-0w
#define okay(MSG, ...) printf("[+] "          MSG "\n", ##__VA_ARGS__)
#define info(MSG, ...) printf("[*] "          MSG "\n", ##__VA_ARGS__)
#define warn(MSG, ...) fprintf(stderr, "[-] " MSG "\n", ##__VA_ARGS__)
