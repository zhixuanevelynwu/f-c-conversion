#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>

void print_usage() {
    printf("Usage: temp -c <temp> | temp -f <temp> \n");
    exit(2);
}

void print_farenheit(float temp) {
    float f = ((temp * 9) / 5) + 32;
    printf("%.2f centigrade is %.2f farenheit\n", temp, f);
}

void print_centigrade(float temp) {
    float c = ((temp - 32) * 5) / 9;
    printf("%.2f farenheit is %.2f centigrade\n", temp, c);
}

int main(int argc, char ** argv) {
    if (argc < 2) {
        print_usage();
    }
    int option;
    int cflag = 0, fflag = 0;
    // "cf" -c or -f as optional flafs
    // "c:f:" -c <arg> -f <arg> (-cf need to be followed by an argument)
    while ((option = getopt(argc, argv, "c:f:")) != -1) {
        switch (option) {
            case 'c':
                if (cflag) {
                    print_usage();
                } else {
                    cflag ++;
                    fflag ++;
                }
                print_farenheit(atof(optarg));
                break;
            case 'f':
                if (fflag) {
                    print_usage();
                } else {
                    cflag ++;
                    fflag ++;
                }
                print_centigrade(atof(optarg));
                break;
            default:
                printf("Error\n");
        }
    }
}
