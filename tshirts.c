#include <stdio.h>
#include <assert.h>

#define SW_TEST_ENVIRONMENT 0
#define SW_PROD_ENVIRONMENT 1

#define SW_ENVIRONMENT SW_TEST_ENVIRONMENT

void testSelectSize(int cms, char testsizeName);
void selectSize(int cms , char testsizeName);

void testSelectSize(int cms, char testsizeName) {
    char sizeName = '\0';
    if(cms <= 38) {
        sizeName = 'S';
    } else if(cms > 38 && cms < 42) {
        sizeName = 'M';
    } else if(cms >= 42) {
        sizeName = 'L';
    }
    assert ( sizeName == testsizeName);
}

void selectSize(int cms , char testsizeName) {
    char sizeName = '\0';
    if(cms <= 38) {
        sizeName = 'S';
    } else if(cms > 38 && cms < 42) {
        sizeName = 'M';
    } else if(cms >= 42) {
        sizeName = 'L';
    }
    
}

int main() {
    #if (SW_ENVIRONMENT == SW_TEST_ENVIRONMENT)
    char (*fp_charSize)(int,char) = testSelectSize;
    #else
    char (*fp_charSize)(int,char) = selectSize;
    #endif

    fp_charSize(37,'S');
    fp_charSize(40,'M');
    fp_charSize(43,'L');
    fp_charSize(42,'L');
    fp_charSize(38,'S');
    
    printf("All is well (maybe!)\n");
    return 0;
}
