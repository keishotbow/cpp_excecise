#include "all.h"

enum class ReturnCode { SUCCESS, ERROR };

template <typename Function, typename... Args>
ReturnCode invoke(Function function, Args&&... args) {
    return function(args...);
}

int add(const int a, const int b) {
    return a + b;
}

void increment(int& ref) {
    ++ref;
}

ReturnCode returnSuccess() {
    return ReturnCode::SUCCESS;
}

ReturnCode returnError() {
    return ReturnCode::ERROR;
}

int main() {
    auto returnCode = invoke(returnSuccess);
    std::cout << static_cast<int32_t>(returnCode) << std::endl;
    returnCode = invoke(returnError);
    std::cout << static_cast<int32_t>(returnCode) << std::endl;

    return 0;
}