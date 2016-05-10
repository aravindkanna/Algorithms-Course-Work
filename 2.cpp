//MaxPairwiseProduct
#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

long long int MaxPairwiseProduct(const vector<int>& numbers) {
  long long int result = 0;
  int n = numbers.size();
  int max_ind=-1, min_ind=-1;
  for(int i=0;i<n;i++){
    if(max_ind==-1 || (numbers[i] > numbers[max_ind])){
      max_ind=i;
    }
  }
  for(int i=0;i<n;i++){
    if((i!=max_ind) && (min_ind==-1 || numbers[i] > numbers[min_ind]) ){
      min_ind=i;
    }
  }
  return numbers[max_ind]*numbers[min_ind];
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
