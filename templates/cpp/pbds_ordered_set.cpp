#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// ordered_set supports order_of_key and find_by_order
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ordered_set s;
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }
    
    // Order of key (0-indexed)
    cout << "Order of 5: " << s.order_of_key(5) << '\n';
    
    // Find by order (0-indexed)
    cout << "Element at order 2: " << *s.find_by_order(2) << '\n';
    
    // Operations
    s.insert(10);
    s.erase(5);
    cout << "Size: " << s.size() << '\n';
    
    return 0;
}
