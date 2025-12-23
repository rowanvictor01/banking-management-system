/*
 * Create an array of function pointers and activate a function depending on
 * the current session
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "utils.h"
#include "menu.h"
#include "account.h"





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
