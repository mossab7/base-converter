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
                index = 38;
            }
            printf("%s ", ascii_chars[index][row]);
        }
        printf("\n");
    }
}

void print_prompt(const char* message) {
    printf("\n");
    printf("    *--------------------------*\n");
    printf("    |                          |\n");
    printf("    |  %-24s|\n", message);
    printf("    |                          |\n");
    printf("    *--------------------------*\n");
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

int main(void)
{
  print_banner();
  char nbr[100];
  char base_from[100];
  char base_to[100];
  char *result;
  
  print_prompt("number: ");
  scanf("%99s", nbr);
  print_prompt("base from: ");
  scanf("%99s", base_from);
  print_prompt("base to: ");
  scanf("%99s", base_to);
  result = ft_convert_base(nbr, base_from, base_to);
   if (result) {
        printf("\n");
        printf("    *--------------------------*\n");
        printf("    |                          |\n");
        printf("    |        RESULT IS:        |\n");
        printf("    |                          |\n");
        printf("    *--------------------------*\n");
        printf("\n");
        print_ascii_art(result);
        free(result);
    } else {
        printf("\n");
        printf("    *--------------------------*\n");
        printf("    |                          |\n");
        printf("    |    Conversion failed.    |\n");
        printf("    |                          |\n");
        printf("    *--------------------------*\n");
    }
  
  return 0;
}


