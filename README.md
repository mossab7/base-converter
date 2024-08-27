# Base Converter

This project is a base converter program written in C. It converts numbers from one base to another.

## Features

- Convert numbers between various bases
- Robust error handling
- Clean and modular code

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
## Usage Instructions

### 1. Interactive Example:
#### You can run the program interactively to convert numbers between bases. Here's how it looks:
```plaintext
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
```
### 2. Quick Conversion Example:
#### Alternatively, you can perform a quick conversion with minimal input:
```plaintext
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

```
### 3. Exiting the program:
####  Type 'quit' (without quotes) when prompted for a number:

```

    *--------------------------*
    |                          |
    |  number (or 'quit') :    |
    |                          |
    *--------------------------*
    > quit

    *--------------------------*
    |                          |
    |  Exiting program...      |
    |                          |
    *--------------------------*
    > Goodbye!                                                                                
```
