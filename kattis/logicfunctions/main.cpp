#include <iostream>

void exclusive(bool x, bool y, bool& ans) {
    ans = x ^ y;
}

void implies(bool x, bool y, bool& ans) {
    ans = !(x && !y);
}

void equivalence(bool x, bool y, bool& ans) {
    ans = x == y;
}

void checkAns(bool val, bool expected) {
    if (val != expected) {
        std::cout << "FAIL - expected " << expected << std::endl;
        exit(1);
    }
}

int main(){
    bool ans;
    exclusive(true, true, ans);
    std::cout << "T xor T: " << ans << std::endl;
    checkAns(ans, false);

    implies(true, true, ans);
    std::cout << "T => T: " << ans << std::endl;
    checkAns(ans, true);

    equivalence(true, true, ans);
    std::cout << "T <=> T: " << ans << std::endl;
    checkAns(ans, true);

    std::cout << "OK!" << std::endl;
}
