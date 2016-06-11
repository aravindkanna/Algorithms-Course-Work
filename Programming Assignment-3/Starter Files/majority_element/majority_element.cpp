#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using namespace std;

int get_majority_element(vector<int> &a, int left, int right) {
  //cout << left << "   " << right << endl;
    if(left > right){
      return 0;
    }
    else if(left == right){
      return 1;
    }
    else{
      int maj_element = a[left];
      int cur_element = 0;
      int count = 0;
      for(int i = left;i <= right;i++){
        cur_element = a[i];
        if(cur_element == maj_element){
          count++;
        }
        else{
          count--;
        }

        if(count == 0){
          maj_element = cur_element;
          count = 1;
        }
        //cout << maj_element << endl;
      }

      count = 0;
      for(int i = left;i <= right;i++){
        if(a[i] == maj_element){
          count++;
        }
      }
      if(count > (right - left + 1)/2){
        return 1;
      }
      return 0;
    }
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << get_majority_element(a, 0, n - 1) << '\n';
}
