
#include <stdio.h>
#define MACRO_NAME(token1,token2)\
  token2 token1 ## token2 = 0
// Macro to create function prototypes with different names
#define FUNC_PROTOTYPE(prefix, type) \
    void prefix ## _ ## type ## _func(int value);

// Macro to implement the function with different names
#define FUNC_IMPLEMENTATION(prefix, type) \
    void prefix ## _ ## type ## _func(int value) { \
        printf("%s_%s_func called with value: %d\n", #prefix, #type, value); \
    }

// Define function prototypes for different types
FUNC_PROTOTYPE(my, int)
FUNC_PROTOTYPE(my, float)
FUNC_PROTOTYPE(my, char)

// Implement functions for different types
FUNC_IMPLEMENTATION(my, int)
FUNC_IMPLEMENTATION(my, float)
FUNC_IMPLEMENTATION(my, char)

// Macro to create and initialize variables with different names
#define VAR_DECLARE(prefix, type) \
    static int prefix ## _ ## type ## _value = 0;

// Declare variables for different types
VAR_DECLARE(my, int)
VAR_DECLARE(my, float)
VAR_DECLARE(my, char)

MACRO_NAME(var,int);
int main() {
    // Call different versions of the function
    my_int_func(10);
    my_float_func(20);
    my_char_func(30);
    printf("My var int:%d\n",varint);
    // Display the values of the variables
    printf("my_int_value = %d\n", my_int_value);
    printf("my_float_value = %d\n", my_float_value); // Note: For demonstration purposes
    printf("my_char_value = %d\n", my_char_value);   // Note: For demonstration purposes

    return 0;
}
