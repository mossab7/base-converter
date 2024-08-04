# Base Converter

This project is a base converter program written in C. It converts numbers from one base to another.

## Features

- Convert numbers between various bases
- Robust error handling
- Clean and modular code

## Files

- `main.c`: Contains the `main` function and program logic.
- `ft_convert_base.c` and `ft_convert_base.h`: Functions for base conversion.
- `ft_convert_base2.c` and `ft_convert_base2.h`: Additional conversion utilities.
- `Makefile`: Instructions to compile the project.

## Usage

1. Clone the repository:
   ```
   git clone https://github.com/mossab7/base-converter.git && cd base-converter
   ```

2. Compile the program:
   ```
   make
   ```

3. Run the program:
   ```
   ./base_converter
   ```
## Examples 

### you can do :
**```plaintext**
./base_converter
             @      @
     / \     { _____}      / \
   /  |  \___/*******\___/  |  \
  (   I  /   ~   '   ~   \  I   )
   \  |  |   0       0   |  |  /
     \   |       A       |   /
       \__    _______    __/
          \_____________/
    *-------*         *-------*
   /  /---    convert     ---\  \
 /  /     (    from     )     \  \
{  (     (   any base!   )     )  }
 \  \    |      to       |    /  /
   \  \  |   any base!   |  /  /
    **** |  cool right?  | ****
   //|\\  \_____________/  //|\\
   *         '*** ***'         *
  ***.       .*** ***.       .***
  '*************' '*************'


    *--------------------------*
    |                          |
    |  number (or 'quit') :    |
    |                          |
    *--------------------------*
    > 255 
    *--------------------------*
    |                          |
    |  base from:              |
    |                          |
    *--------------------------*
    > 0123456789 

    *--------------------------*
    |                          |
    |  base to:                |
    |                          |
    *--------------------------*
    > 0123456789abcdef

    *--------------------------*
    |                          |
    |  result:                 |
    |                          |
    *--------------------------*
    > ff
***** ***** 
*     *     
***   ***   
*     *     
*     *     
**```**
### or you can:
    *--------------------------*
    |                          |
    |  number (or 'quit') :    |
    |                          |
    *--------------------------*
    > 255
    *--------------------------*
    |                          |
    |  base from:              |
    |                          |
    *--------------------------*
    > '10'

    *--------------------------*
    |                          |
    |  base to:                |
    |                          |
    *--------------------------*
    > '16'

    *--------------------------*
    |                          |
    |  result:                 |
    |                          |
    *--------------------------*
    > ff
***** ***** 
*     *     
***   ***   
*     *     
*     *     

