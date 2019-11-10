map<int, int> factorize(int n) {
    map<int, int> res;
    for(int i = 2; i * i<= n ; ++i) {
        while (n % i == 0) {
            n /= i;
            res[i]++;
        }
    }
    if (n > 1)
        res[n]++;
    return res;
}