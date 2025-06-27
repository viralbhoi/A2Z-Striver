//Stock Buy And Sell
// Problem Statement: You are given an array of prices where prices[i] is the price of a given stock on an ith day.

// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock. Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

#include <bits/stdc++.h>
using namespace std;

// O(n^2) space O(1)
int maxProfitBrute(vector<int> &prices)
{
    int maxProfit = 0;
    int n = prices.size();

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            maxProfit = max(maxProfit, prices[j] - prices[i]);
        }
    }

    return maxProfit;
}

// O(n) space O(1)
int maxProfitOptimal(vector<int> &prices)
{
    int maxProfit = 0;
    int minPrice = prices[0];

    for (int i = 1; i < prices.size(); i++)
    {
        int cost = prices[i] - minPrice;
        maxProfit = max(maxProfit, cost);
        minPrice = min(prices[i], minPrice);
    }
    return maxProfit;
}

int main(){
    int n;
    cin>>n;

    vector<int> v(n);

    for(auto &it:v){
        cin>>it;
    }

    cout<<maxProfitBrute(v)<<endl;
    cout<<maxProfitOptimal(v)<<endl;


}