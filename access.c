#define NUM_CODES 32
#define CODE_LENGTH 5
#include <stdio.h>
#include <stdlib.h>
// given a 5-digit lab access code, prints all 32 equivalent 5-digit                                                                                                                                                                                                          
// lab access codes.                                                                                                                                                                                                                                                          
// Reminder: 1/2, 3/4, 5/6, 7/8, 9/0 are on the same buttons.                                                                                                                                                                                                                 

void print_all_access_codes_help(int *code, int size) {
  int complement;
  int* partial_array_pointer;
  int original_num;

  if(size > 0){
    partial_array_pointer = (int *) (code + 1);
    original_num = code[0];
    switch(original_num){
    case 1:
      complement = 2;
      break;
    case 2:
      complement = 1;
      break;
    case 3:
      complement = 4;
      break;
    case 4:
      complement = 3;
      break;
    case 5:
      complement = 6;
      break;
    case 6:
      complement = 5;
      break;
    case 7:
      complement = 8;
      break;
    case 8:
      complement = 7;
      break;
    case 9:
      complement = 0;
      break;
    case 0:
      complement = 9;
      break;
    default:
      break;
    }
    size--;
    printf("\n %d", original_num);
    print_all_access_codes_help(partial_array_pointer, size);
    printf("\n %d", complement);
    print_all_access_codes_help(partial_array_pointer, size);
  }
}

void print_all_access_codes(int *code){
  print_all_access_codes_help(code, CODE_LENGTH);
}

void main(int argc, char **argv){
  int i;
  int j;
  int* elem;;
  int* code;
  code = malloc(sizeof(int)* CODE_LENGTH);
  for(i = 0; i < CODE_LENGTH; i++){
    code[i] = i;
  }
  print_all_access_codes(code);
}
