#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>


typedef enum {
  REGISTER = 0,
  LOGIN = 1,
  SIGNED_IN = 2
} Session;


void display_menu();
void create_account();
void clear_input_buffer();
Session login_or_register();
bool check_input_overflow(char*);


int main() {
  /*
  * Create an array of function pointers and activate a function depending on the current session
  */
  Session current_session = login_or_register();

  return 0;
}

void display_menu() {
}

void create_account() {
}

Session login_or_register() {
  printf("\nWelcome to the Banking Application!\n\nWould you like to login or register?\n>> ");

  char user_response[10];
  char input_buffer[10];
  Session chosen_session;
  bool has_valid_answer = false;
  bool is_input_overflowing = false;

  do {

    if(fgets(input_buffer, sizeof(input_buffer), stdin) != NULL) {

      is_input_overflowing = check_input_overflow(input_buffer);

      if(is_input_overflowing) {
        clear_input_buffer();
      }

      sscanf(input_buffer, "%s", user_response);
      strcpy(input_buffer, "");
      
      if(strcasecmp(user_response, "login") == 0) {
        chosen_session = LOGIN;
        has_valid_answer = true;
      }
      else if(strcasecmp(user_response, "register") == 0) {
        chosen_session = REGISTER;
        has_valid_answer = true;
      }
      else {
        printf("Invalid Input. Please enter with either [login] or [register] only\n>> ");
      }
    }

  } while(!has_valid_answer);

  return chosen_session;
}

void clear_input_buffer() {
  int c;
  while((c = getchar()) != '\n' && c != EOF) {
    ;
  }
}

bool check_input_overflow(char* input) {
  while(*input != '\0') {
    if(*input == '\n') {
      return false;
    }
    input++;
  }
  return true;
}
