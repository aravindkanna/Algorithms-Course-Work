#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;



double get_optimal_value(int capacity, vector<int> &weights, vector<int> &values) {
  double value = 0.0;
  int n = weights.size();
  if(!n){
    return 0.0;
  }
  
  vector<float> density(n);
  for(int i=0;i<n;i++){
      density[i] = (float)values[i]/(float)weights[i];
  }
  int max_index = distance(density.begin(), max_element(density.begin(), density.end()));

  if(capacity > weights[max_index]){
      value = values[max_index];
      capacity = capacity - weights[max_index];
      density.erase(density.begin()+max_index);
      weights.erase(weights.begin()+max_index);
      values.erase(values.begin()+max_index);
      return value + get_optimal_value(capacity, weights, values);
  }
  else{
    return capacity*density[max_index];
  }
}

int main() {
  int n;
  int capacity;
  cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  cout.precision(10);
  cout << fixed;
  cout << setprecision(4) << optimal_value << endl;
  return 0;
}
