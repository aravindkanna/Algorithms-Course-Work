//MaxPairwiseProduct
#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

long long int MaxPairwiseProduct(const vector<int>& numbers) {
  long long int result = 0;
  int size = numbers.size();
  int max_ind = -1, second_max_ind = -1;

  for(int i = 0;i < size;i++){
    if(numbers[i] > numbers[max_ind]){
      max_ind = i;
    }
  }

  for(int i = 0;i < size;i++){
    if(i != max_ind && numbers[i] > numbers[second_max_ind]){
      second_max_ind = i;
    }
  }

  return (long long )numbers[max_ind] * (long long )numbers[second_max_ind];
}

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    long long int result = MaxPairwiseProduct(numbers);
    cout << result << "\n";
    return 0;
}
