/*
 * Create an array of function pointers and activate a function depending on
 * the current session
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <time.h>

typedef enum { REGISTER = 0, LOGIN = 1, SIGNED_IN = 2 } session_e;

void display_menu();
void create_account();
void clear_input_buffer();
session_e login_or_register();
bool check_input_overflow(char *);
void get_user_input(char*, int);
void get_current_local_time(char*, int);

int main() {
    // Seed random num generator using current time
    srand(time(NULL));

    session_e current_session = login_or_register();

    // call function depending on session
    switch(current_session) {
        case REGISTER:
                create_account();
                break;
        case LOGIN:
                // code
                break;
    }

    return 0;
}

void display_menu() {}

void create_account() {
    // Later write a function to avoid duplicating exising acc num
    long new_account_num = (rand() % 9999999) + 1000000;

    // Refactor later to dynamically allocate memory instead of setting an arbitrary size
    char user_name[99];
    float deposit;
    char deposit_buf[14];

    printf("\nEnter your full name\n>> ");
    get_user_input(user_name, sizeof(user_name));

    printf("Enter your initial deposit amount\n>> ");
    get_user_input(deposit_buf, sizeof(deposit_buf));
    sscanf(deposit_buf, "%f", &deposit);

    printf("\nName: %s\n", user_name);
    printf("Balance: %.3f\n", deposit);

    char acc_creation_time[80];
    get_current_local_time(acc_creation_time, sizeof(acc_creation_time));
    printf("Account Created @ %s\n", acc_creation_time);
}

session_e login_or_register() {
    printf("\nWelcome to the Banking Application!\n\nWould you like to login "
           "or register?\n>> ");

    char user_response[10];
    session_e chosen_session;
    bool has_valid_answer = false;

    do {

            get_user_input(user_response, sizeof(user_response));

            if (strcasecmp(user_response, "login") == 0) {
                chosen_session = LOGIN;
                has_valid_answer = true;
            } else if (strcasecmp(user_response, "register") == 0) {
                chosen_session = REGISTER;
                has_valid_answer = true;
            } else {
                printf("Invalid Input. Please enter with either [login] or "
                       "[register] only\n>> ");
            }

    } while (!has_valid_answer);

    return chosen_session;
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


void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        ;
    }
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
