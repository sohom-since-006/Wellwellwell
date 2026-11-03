#include <iostream>
#include <string>

void searchRabinKarp(const std::string& pat, const std::string& txt, int q = 101) {
    int d = 256;
    int M = pat.size(), N = txt.size();
    int p = 0, t = 0, h = 1;

    for (int i = 0; i < M - 1; i++) h = (h * d) % q;
    for (int i = 0; i < M; i++) {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    for (int i = 0; i <= N - M; i++) {
        if (p == t) {
            bool match = true;
            for (int j = 0; j < M; j++) {
                if (txt[i + j] != pat[j]) { match = false; break; }
            }
            if (match) std::cout << "Pattern found at index " << i << "\n";
        }
        if (i < N - M) {
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;
            if (t < 0) t = (t + q);
        }
    }
}

int main() {
    std::string txt = "GEEKS FOR GEEKS";
    std::string pat = "GEEK";
    searchRabinKarp(pat, txt);
    return 0;
}
