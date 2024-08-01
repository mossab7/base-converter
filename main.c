#include "ft_convert_base.h"
#include "ft_convert_base2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define LETTER_HEIGHT 5
#define LETTER_WIDTH 5

const char* ascii_chars[43][LETTER_HEIGHT] = {
    {" *** ", "*   *", "*****", "*   *", "*   *"}, // A
    {"**** ", "*   *", "**** ", "*   *", "**** "}, // B
    {" ****", "*    ", "*    ", "*    ", " ****"}, // C
    {"**** ", "*   *", "*   *", "*   *", "**** "}, // D
    {"*****", "*    ", "***  ", "*    ", "*****"}, // E
    {"*****", "*    ", "***  ", "*    ", "*    "}, // F
    {" ****", "*    ", "* ***", "*   *", " ****"}, // G
    {"*   *", "*   *", "*****", "*   *", "*   *"}, // H
    {"*****", "  *  ", "  *  ", "  *  ", "*****"}, // I
    {"*****", "   * ", "   * ", "*  * ", " **  "}, // J
    {"*   *", "*  * ", "***  ", "*  * ", "*   *"}, // K
    {"*    ", "*    ", "*    ", "*    ", "*****"}, // L
    {"*   *", "** **", "* * *", "*   *", "*   *"}, // M
    {"*   *", "**  *", "* * *", "*  **", "*   *"}, // N
    {" *** ", "*   *", "*   *", "*   *", " *** "}, // O
    {"**** ", "*   *", "**** ", "*    ", "*    "}, // P
    {" *** ", "*   *", "*   *", "*  **", " ** *"}, // Q
    {"**** ", "*   *", "**** ", "*  * ", "*   *"}, // R
    {" ****", "*    ", " *** ", "    *", "**** "}, // S
    {"*****", "  *  ", "  *  ", "  *  ", "  *  "}, // T
    {"*   *", "*   *", "*   *", "*   *", " *** "}, // U
    {"*   *", "*   *", "*   *", " * * ", "  *  "}, // V
    {"*   *", "*   *", "* * *", "** **", "*   *"}, // W
    {"*   *", " * * ", "  *  ", " * * ", "*   *"}, // X
    {"*   *", " * * ", "  *  ", "  *  ", "  *  "}, // Y
    {"*****", "   * ", "  *  ", " *   ", "*****"}, // Z
    {" *** ", "*   *", "*   *", "*   *", " *** "}, // 0
    {"  *  ", " **  ", "  *  ", "  *  ", "*****"}, // 1
    {" *** ", "*   *", "  ** ", " *   ", "*****"}, // 2
    {" *** ", "*   *", "  ** ", "*   *", " *** "}, // 3
    {"  ** ", " * * ", "*  * ", "*****", "   * "}, // 4
    {"*****", "*    ", "**** ", "    *", "**** "}, // 5
    {" *** ", "*    ", "**** ", "*   *", " *** "}, // 6
    {"*****", "   * ", "  *  ", " *   ", "*    "}, // 7
    {" *** ", "*   *", " *** ", "*   *", " *** "}, // 8
    {" *** ", "*   *", " ****", "    *", " *** "}, // 9
    {"     ", "  *  ", "*****", "  *  ", "     "}, // +
    {"     ", "     ", "*****", "     ", "     "}, // -
    {"     ", "     ", "     ", "     ", "     "}  // Space
};

void print_ascii_art(const char* text) {
    size_t len = strlen(text);
    
    for (int row = 0; row < LETTER_HEIGHT; row++) {
        for (size_t i = 0; i < len; i++) {
            char c = toupper(text[i]);
            int index;
            if (c >= 'A' && c <= 'Z') {
                index = c - 'A';
            } else if (c >= '0' && c <= '9') {
                index = c - '0' + 26;
            } else if (c == '+') {
                index = 36;
            } else if (c == '-') {
                index = 37;
            } else {
                index = 38; // Space for any other character
            }
            printf("%s ", ascii_chars[index][row]);
        }
        printf("\n");
    }
}

void print_prompt(const char* message, const char *result) {
    printf("\n");
    printf("    *--------------------------*\n");
    printf("    |                          |\n");
    printf("    |  %-24s|\n", message);
    printf("    |                          |\n");
    printf("    *--------------------------*\n");
    if(strcmp(message,"result"))
      printf("    > %s",result);
    else if(strcmp(message,"conversion failed"))
      printf("    > %s",result);
    else
      printf("    > ");
}

  void print_banner() 
{
    printf("             @      @\n"
           "     / \\     { _____}      / \\\n"
           "   /  |  \\___/*******\\___/  |  \\\n"
           "  (   I  /   ~   '   ~   \\  I   )\n"
           "   \\  |  |   0       0   |  |  /\n"
           "     \\   |       A       |   /\n"
           "       \\__    _______    __/\n"
           "          \\_____________/\n"
           "    *-------*         *-------*\n"
           "   /  /---    convert     ---\\  \\\n"
           " /  /     (    from     )     \\  \\\n"
           "{  (     (   any base!   )     )  }\n"
           " \\  \\    |      to       |    /  /\n"
           "   \\  \\  |   any base!   |  /  /\n"
           "    **** |  cool right?  | ****\n"
           "   //|\\\\  \\_____________/  //|\\\\\n"
           "   *         '*** ***'         *\n"
           "  ***.       .*** ***.       .***\n"
           "  '*************' '*************'\n");
    printf("\n");
}

int is_base(char *base)
{
  if(!(*base == '\''))
    return 0;
  char *start = base + 1;
  while(*base)
    base++;
  if(!(*(base - 1) == '\''))
    return 0;
  return(atoi(start));
}

int main(void)
{
  print_banner();
  char nbr[100];
  char base_from[100];
  char base_to[100];
  const char *upper_base = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  const char *lower_base = "0123456789abcdefghijklmnopqrstuvwxyz";
  char *result;
  
while(1)
  {
    print_prompt("number (or 'quit') : ","");
    scanf("%99s", nbr);
    if(strcmp(nbr, "quit") == 0 || strcmp(nbr, "QUIT") == 0)
    {
      print_prompt("Exiting program...","Goodbye!");
      break;
    }
    print_prompt("base from: ","");
    scanf("%99s", base_from);
    int base_from_value = is_base(base_from);
    if(base_from_value >= 2)
    {
      if(isupper(*nbr) || isdigit(*nbr))
      {
        strncpy(base_from,upper_base,is_base(base_from));
        base_from[base_from_value] = '\0';
      }
      else
      { 
        strncpy(base_from,lower_base,is_base(base_from));
        base_from[base_from_value] = '\0';
      }
    }
    print_prompt("base to: ","");
    scanf("%99s", base_to);
    int base_to_value = is_base(base_to);
    if(base_to_value >= 2)
    {
      if(isupper(*nbr) || isdigit(*nbr))
      {
        strncpy(base_to,upper_base,is_base(base_to));
        base_to[base_to_value] = '\0';
      }
      else
      { 
        strncpy(base_to,lower_base,is_base(base_to));
        base_to[base_to_value] = '\0';
      }
    }
    result = ft_convert_base(nbr, base_from, base_to);
     if (result) 
      {
          print_prompt("result: ",result);
          printf("\n");
          print_ascii_art(result);
          free(result);
      }
    else 
      {
           print_prompt("conversion failed","try again 'base shouldn't contain doubles or be less then 2'");
      }
  } 
  return 0;
}



