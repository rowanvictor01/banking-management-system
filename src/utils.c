#include <time.h>
#include <stdbool.h>
#include <stdio.h>

#include "utils.h"


void get_current_local_time(char* time_var, int size) {
    time_t raw_time;
    struct tm* local_time_info_s;

    // Get current calendar time in seconds
    time(&raw_time);

    // Break down time into components like hours and minutes and store into a struct
    local_time_info_s = localtime(&raw_time);

    // Format time into a custom string
    strftime(time_var, size, "%m-%d, %H:%M %Y", local_time_info_s);
}


bool check_input_overflow(char *input) {
    while (*input != '\0') {
        if (*input == '\n') {
            return false;
        }
        input++;
    }
    return true;
}


void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        ;
    }
}


void get_user_input(char* input_var, int size) {

    bool is_input_overflowing = false;
    char input_buf[size];

    if (fgets(input_buf, sizeof(input_buf), stdin) != NULL) {

        is_input_overflowing = check_input_overflow(input_buf);

        if (is_input_overflowing) {
            clear_input_buffer();
        }
        else {
            size_t len = strlen(input_buf);
            input_buf[len - 1] = '\0';
            len--;
        }

        strcpy(input_var, input_buf);

    }

}


