#include <stdio.h>
#include <stdlib.h>

/*
Every Program returns an exit code to the caller.
This value generally is used to indicate SUCCESS or FAILURE REASON.
Typically
0 - Success
1 - Error1
2 - Error2 ... so on
*/

//-----------------------------------------------------------------
//Case 1: Return a programmed value
#if 0
int main() {
    printf("Hellow World!!\n");
    return 2;
}
#endif

/*
$gcc void_main.c 
$./a.out
Hellow World!!
$echo $?
2
*/

//-----------------------------------------------------------------
//Case 2: No Return Value - Compiler assumes
#if 0 

int main() {
    printf("Hellow World!!\n");
}
#endif

/*
$gcc void_main.c 
$./a.out
Hellow World!!
$echo $?
0
*/


//-----------------------------------------------------------------
//Case 3: void return - with return statement
//
// void - means no return value
// Hence, compiler won't allow a return statement with value
#if 0
void main() {
    printf("Hellow World!!\n");
    return 2;
}
#endif 

/*
$gcc void_main.c 
void_main.c: In function ‘main’:
void_main.c:44:12: warning: ‘return’ with a value, in function returning void
   44 |     return 2;
      |            ^
void_main.c:42:6: note: declared here
   42 | void main() {
      |      ^~~~
*/


//-----------------------------------------------------------------
//Case 4: void with no return statement
//
#if 0
void main() {
    printf("Hellow World!!\n");
}
#endif

/*
$gcc void_main.c 
$./a.out
Hellow World!!
$echo $?
15
$./a.out
Hellow World!!
$echo $?
15
$gcc void_main.c 
$./a.out
Hellow World!!
$echo $?
15

RANDOM NUMBER is returned... no control
*/


//-----------------------------------------------------------------
//Case 5: void with exit()
//
//  Typically in programs we have a master loop and runs infinitely.
//  These don't exit the main by themselves.
//
//  exit() method is used to exit them on condition.
//  in the below example, when counter reaches 1000 the program exits...
//  
void main() {
    int counter=0;
    printf("Hellow World!!\n");
    while (1) {
        counter++;
        if (counter > 1000) {
            exit(5);
        }
    }
    printf("Main end !!");    
}

/*
$gcc void_main.c 
$./a.out
Hellow World!!
$echo $?
5

NOTE: "Main end!!" print was not present in the output
So. the program exits from the exit() function directly... instead of returning from main.
*/

/* SUMMARY

* when program does one operation and has success or failure to report .... "int" return is used for main
* when a program runs a master loop and does continous operation ... "void" return is used along with exit() function

*/
