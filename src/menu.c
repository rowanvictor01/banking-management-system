#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>

#include "menu.h"
#include "utils.h"
#include "account.h"



void display_menu() {}


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
