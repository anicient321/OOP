#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

bool isPowerOf2(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 16, 32};
    
    auto it = std::find_if(v.begin(), v.end(), [](int x) { return x % 2 != 0; });
    if (it != v.end()) {
        std::cout << "prvi neparni: " << *it << std::endl;
    }
    
    int count = std::count_if(v.begin(), v.end(), [](int x) { return x % 2 != 0; });
    std::cout << "broj neparnih: " << count << std::endl;
    
    int sum = std::accumulate(v.begin(), v.end(), 0, [](int acc, int x) {
        return x % 2 != 0 ? acc + x : acc;
    });
    double avg = static_cast<double>(sum) / count;
    std::cout << "prosjek neparnih: " << avg << std::endl;
    
    std::replace_if(v.begin(), v.end(), isPowerOf2, 2);
    
    std::vector<int> parni, neparni;
    for (int x : v) {
        if (x % 2 == 0) parni.push_back(x);
        else neparni.push_back(x);
    }
    std::sort(parni.begin(), parni.end());
    std::sort(neparni.begin(), neparni.end());
    
    std::cout << "parni: ";
    for (int x : parni) std::cout << x << " ";
    std::cout << "\nneparni: ";
    for (int x : neparni) std::cout << x << " ";
    std::cout << std::endl;
    
    return 0;
}
