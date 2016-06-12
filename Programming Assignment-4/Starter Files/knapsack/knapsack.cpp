#include <iostream>
#include <vector>

using std::vector;
using namespace std;

int optimal_weight(int W, const vector<int> &w) {
  //write your code here

  vector<vector<int> > value(w.size() + 1,  vector<int> (W + 1));
  int number_of_weights = w.size();
  int knapsack_weight = W;
  for(int i = 0;i <= knapsack_weight;i++){
    value[0][i] = 0;
  }

  for(int i = 0;i <= number_of_weights;i++){
    value[i][0] = 0;
  }

  for(int i = 1;i <= number_of_weights;i++){
    for(int j = 1;j <= knapsack_weight;j++){
      value[i][j] = value[i - 1][j];
      int val = 0;
      if(w[i - 1] <= j){
        val = value[i - 1][j - w[i - 1]] + w[i - 1];
      }
      if(value[i][j] < val){
        value[i][j] = val;
      }
    }
  }

  return value[number_of_weights][knapsack_weight];


  int current_weight = 0;
  for (size_t i = 0; i < w.size(); ++i) {
    if (current_weight + w[i] <= W) {
      current_weight += w[i];
    }
  }
  return current_weight;
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
