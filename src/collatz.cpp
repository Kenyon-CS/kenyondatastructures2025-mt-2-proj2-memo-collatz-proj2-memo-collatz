#include "collatz.hpp"
#include <stdexcept>
#include <unordered_map>

// TODO: Replace the naive recursion below with a memoized version.
// Use a static std::unordered_map<unsigned long long,int> memo {{1ULL, 1}};
// Be careful: 3*n+1 may exceed 32-bit; use unsigned long long for intermediates.

static int collatz_naive(unsigned long long n) {
    if (n < 1ULL) throw std::invalid_argument("n must be >= 1");
    if (n == 1ULL) return 1;
    if ((n & 1ULL) == 0ULL) {
        return 1 + collatz_naive(n / 2ULL);
    } else {
        return 1 + collatz_naive(3ULL * n + 1ULL);
    }
}

int collatz_len(unsigned long long n) {
    // START TODO: implement memoized recursion (see README for hints).
    // Example sketch:
    // Create a static memo in the function (so we don;t have to pass it in)
    // static std::unordered_map<unsigned long long, int> memo{{1ULL, 1}};
    // See if it's in the memo, return if so
    // auto it = memo.find(n);
    // if (it != memo.end()) return it->second;
    // if n is even compute collatz_len(n/2) else collatz_len(3*n+1)
    // The next value is n + n
    // Put the value for n in the memo
    // return val;
    //
    // Remove the fallback line below once you implement memoization:
    return collatz_naive(n);
    // END TODO
}
