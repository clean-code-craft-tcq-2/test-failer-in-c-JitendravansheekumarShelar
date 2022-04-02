#include <stdio.h>
#include <assert.h>

#define Max_CountInEachColorTable 5U
#define SW_TEST_ENVIRONMENT 0
#define SW_PROD_ENVIRONMENT 1

#define SW_ENVIRONMENT SW_TEST_ENVIRONMENT


void testprintOnConsole(int pairNumber , const char* majorColor , const char* minorColor)
{
    const char* testMajorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* testMinorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    
    assert( testMajorColor[pairNumber / Max_CountInEachColorTable] == majorColor);
    assert( testMinorColor[pairNumber % Max_CountInEachColorTable] == minorColor);
}

int testprintColorMap() {

    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            testprintOnConsole(i * 5 + j, majorColor[i], minorColor[j]);
        }
    }
    assert((i * j) == 25);
    return i * j;
}

void printOnConsole(int pairNumber , const char* majorColor , const char* minorColor)
{
    printf("%d \t| \t%s \t| \t%s\n", pairNumber , majorColor, minorColor);
}

int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            printOnConsole(i * 5 + j, majorColor[i], minorColor[j]);
        }
    }
    return i * j;
}

int main() {
    
    #if (SW_ENVIRONMENT == SW_TEST_ENVIRONMENT)
    int (*fp_printColorMap)(void) = &testprintColorMap;
    #else
    int (*fp_printColorMap)(void) = &printColorMap;
    #endif
    
    int result = fp_printColorMap();
    printf("The %d-Pair Color code is printed succesfully\n",result);
    printf("All is well (maybe!)\n");
    return 0;
}
