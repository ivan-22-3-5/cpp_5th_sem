#include <iostream>

#define LOG(status, message) cout << status << ": " << message << endl;

#define SUMUP(startingPoint, upTo)      \
    ({                                  \
        int result = startingPoint;     \
        for (int i = 1; i <= upTo; i++) \
            result += i;                \
        result;                         \
    })

#define FIBONACCI(n) ({ \
    if (n == 0) 0;      \
    int previouspreviousNumber, previousNumber = 0, currentNumber = 1;  \
    for (int i = 1; i < n; i++) {                                       \
        previouspreviousNumber = previousNumber;                        \
        previousNumber = currentNumber;                                 \
        currentNumber = previouspreviousNumber + previousNumber;        \
    }                                                                   \
    currentNumber;                                                      \
})

#define DO_SECRET_OPERATION(firstNumber, secondNumber)({    \
    firstNumber SECRET_OPERATION secondNumber;       \
})
using namespace std;

#define SECRET_OPERATION +

int main() {
    LOG("INFO", "Program started");
    cout << SUMUP(0, 5) << endl;
    cout << FIBONACCI(3) << endl;
    cout << DO_SECRET_OPERATION(10, 20) << endl;
    return 0;
}
