#include <algorithm>
#include <vector>
#include <iostream>

int main() {
	int t; cin >> t;
	while(t--)
	{
		int n; // number of stores
    std::cin >> n;
    int trades; // total number of trades available
    std::cin >> trades;
    std::vector<std::pair<double, int>> profits(n);
    for(int i=0; i<n; ++i) {
        double price;
        int limit;
        std::cin >> price >> limit;
        profits[i] = {price, limit};
    }
    
    double total_profit = 0;
    while (trades > 0) {
        auto max_profit_store = std::max_element(profits.begin(), profits.end());
        int possible_trades = std::min(trades, max_profit_store->second);
        trades -= possible_trades;
        max_profit_store->second -= possible_trades;
        total_profit += possible_trades * max_profit_store->first;
    }

    std::cout << "Maximum possible profit: " << total_profit << std::endl;
	}
    
    return 0;
}
