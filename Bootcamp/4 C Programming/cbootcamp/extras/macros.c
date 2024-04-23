// C Bootcamp Demo Deliverable: Macros
// jbiggs fall 2016
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

// Use #define for constants, to avoid using magic numbers.
#define VAR 5

// Also use #define for functions... but be careful! See below.

// The C preprocessor uses direct substitution for macros, including
// macros disguised as functions.

// This means that before your code is *even compiled*, all macros are
// substituted for their text *in-place*, completely as-is. This can
// be very handy, but can also lead to disastrous and unpredictable
// consequences!

// Take this benign-looking macro, for instance. It has a horrible flaw. 
// (Find out what that flaw is by looking at the code, compiling,
// and running it.)
#define MAX_BAD1(a, b) a > b ? a : b
// This still isn't quite there -- again, look how it's used in main below.
#define MAX_BAD2(a, b) (a > b ? a : b)
// That's better!
#define MAX_GOOD(a, b) ((a) > (b) ? (a) : (b))

// This rule applies to expanding calculations as well. Suppose we have
// 12 widgets and 8 gadgets. Our total inventory is
#define TOTAL_INVENTORY 12 + 8
// If we want to double our inventory in the next month, what's wrong
// with calculating the target inventory this way?
// (hint: see what the program prints when it's run!)
#define TARGET_INVENTORY TOTAL_INVENTORY * 2

// #define can be really helpful when you have a bunch of print statements
// you might want to disable if you're debugging code, as long as you're
// comfortable with ifdef!
//
// Try commenting out the line below, recompiling, and seeing how your
// program's behavior changes.
// #define DEBUG
#ifdef DEBUG
// __VA_ARGS__ is a special macro variable denoting all of its arguments.
#define dbg_printf(...) do { printf(__VA_ARGS__); } while(0)
#else
// when DEBUG isn't defined, printf won't do anything!
#define dbg_printf(...)
#endif

int main(int argc, char** argv)
{
    if (1 == MAX_BAD1(1, 2))
        puts("Remember your parentheses!");
    if (2 == MAX_BAD2(1, 2))
        puts("This seems better, but...");
    if (2 == MAX_BAD2(2, MAX_BAD1(2, 3)))
        puts("Whoah!");
    if (3 == MAX_GOOD(2, MAX_BAD1(2, 3)))
        puts("Remember parentheses around macro arguments too.");
    if (TARGET_INVENTORY != (12 + 8) * 2)
        puts("This applies to constants defined as equations as well!");

    // Recompile this file with #define DEBUG (above) commented out, and see
    // if this is still printed out!
    dbg_printf("This is a debug print statement!\n");
    return 0;
}
