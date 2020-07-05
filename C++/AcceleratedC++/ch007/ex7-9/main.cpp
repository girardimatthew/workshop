#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using std::string;          using std::domain_error;
using std::cin;             using std::vector;
using std::cout; 
using std::endl;

//#define MY_RAND_MAX 32767
//#define MY_RAND_MAX 2147483647
#define MY_RAND_MAX RAND_MAX


/********** DIFFICULT
 * The implementation of nrand in §7.44/135 will not work for arguments greater then RAND_MAX
 * Usually, this restriction is no proble, because RAND_MAX is often the largest possible
 * integer anyway. Nevertheless, there are implementations under which RAND_MAX is much smaller
 * than the largest possible integer. For example, it is not uncommon for RAND_MAX to be 
 * 32767 (2^15 -1) and the largest possible integer to be 2147483647 (2^31-1).
 * Reimplement nrand so that it works well for all values of n.
*/

int nrand(int n) {
    if (n <= 0 || n > RAND_MAX)
        throw domain_error("Argument to nrand id out of range");

    const int bucket_size = RAND_MAX / n;
    int r;

    do r = rand() / bucket_size;
    while (r >= n);
    
    return r;
}

int nrand_ver_001(int n, const int max = RAND_MAX) {
    if (n <= 0)
        throw domain_error("Argument to nrand is out of range");

    if (n <= max) {
        const int bucket_size = max / n;
        int r;

        do r = rand() / bucket_size;
        while (r >= n);

        return r;
    } else {
        const int buckets = n / max;
        const int remainder_rand = n % max == 0 ? 0 : nrand_ver_001(n % max);
        const int lost = n % max == 0 ? buckets : buckets + 1;

        return nrand_ver_001(max) * buckets + remainder_rand + nrand_ver_001(lost);
    }
}

int nrand_ver_002(int n) {
    if (n <= 0)
        throw domain_error("Argument to nrand is out of range");

    int r;

    if (n <= MY_RAND_MAX) {
        const int bucket_size = MY_RAND_MAX / n;

        do {
            int bucket = rand() / bucket_size;
            r = bucket;
        } while (r >= n);
    } else {
        const int bucket_size = ceil(n / MY_RAND_MAX);

        do {
            const int bucket = nrand_ver_002(MY_RAND_MAX);
            const int remainder = nrand_ver_002(bucket_size);
            r = (bucket - 1) * bucket_size + remainder;
        } while (r >= n);
    }
    return r;
}

int main(int argc, const char * argv[]) {
    srand(time(NULL));

    cout << endl;
    cout << "current RAND_MAX    >> " << RAND_MAX << endl;
    cout << "current MY_RAND_MAX >> " << MY_RAND_MAX << endl;
    cout << "*************** NRAND ****************" << endl;
    cout << nrand(300) << endl;
    cout << nrand(2000) << endl;
    cout << nrand(30000) << endl;
    cout << nrand(50000) << endl;
    cout << nrand(50000) << endl;
    cout << nrand(2147483647) << endl;
    
    // cout << nrand(2147483648) << endl;

    cout << "******* NRAND_VER_001 IMPROVED *******" << endl;
    cout << nrand_ver_001(100, 3) << endl;
    cout << nrand_ver_001(100, 32768) << endl;
    cout << nrand_ver_001(2000, 3) << endl;
    cout << nrand_ver_001(30000, 3) << endl;
    cout << nrand_ver_001(30000, 32768) << endl;
    cout << nrand_ver_001(2147483647, 32768) << endl;
    
    // cout << nrand_ver_001(2147483647, 2147483650) << endl;
    

    cout << "******* NRAND_VER_002 IMPROVED *******" << endl;
    int limit = 32768;
    cout << nrand_ver_002(300) << endl;
    cout << nrand_ver_002(2000) << endl;
    cout << nrand_ver_002(30000) << endl;
    cout << nrand_ver_002(limit) << endl;
    cout << nrand_ver_002(60000) << endl;
    cout << nrand_ver_002(2147483647) << endl;
    //cout << nrand_ver_002(2147483650) << endl;

    return 0;
}
