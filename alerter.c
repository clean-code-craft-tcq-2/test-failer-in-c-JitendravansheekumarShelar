#include <stdio.h>
#include <assert.h>

#define SW_TEST_ENVIRONMENT 0
#define SW_PROD_ENVIRONMENT 1

#define SW_ENVIRONMENT SW_TEST_ENVIRONMENT

int alertFailureCount = 0;

int networkAlertStub(float celcius) {
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
    if(celcius < 500)
        return 200;
    else
        return 500;
}

void testalertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlertStub(celcius);
    static int countCheck = 0;
    if(celcius < 500)
        assert (returnCode == 500);
    else
    {
        assert (returnCode == 200);
        countCheck += 1;
    }
        
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 1;
    }
}

void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 1;
    }
}

int main() {
    #if (SW_ENVIRONMENT == SW_TEST_ENVIRONMENT)
    testalertInCelcius(1050);
    #else
    alertInCelcius(1050);
    #endif
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
