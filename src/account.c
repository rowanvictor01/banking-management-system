#include <stdio.h>

#include "account.h"
#include "utils.h"


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
