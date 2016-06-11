#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using namespace std;

int min(int a, int b){
  if(a < b){
    return a;
  }
  return b;
}

void get_vector(vector<int> &vec, int n){
  vec[0] = 0;
  vec[1] = 0;
  for(int i = 2;i <= n;i++){
    vec[i] = vec[i-1] + 1;
    if(i % 2 == 0){
      vec[i] = min(vec[i / 2] + 1, vec[i]);
    }
    if(i % 3 == 0){
      vec[i] = min(vec[i / 3] + 1, vec[i]);
    }
  }
}

void print(vector<int> vec){
  for(int i = 0;i < vec.size();i++){
    cout << vec[i] << endl;
  }
}

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  vector<int> vec(n + 1);
  get_vector(vec, n);
  //print(vec);

  while(n >= 1){
    //sequence.push_back(n);
    if(n % 3 != 0 && n % 2 != 0){
      n--;
      sequence.push_back(n);
    }
    else{
      if(n % 3 != 0){
        if(vec[n - 1] < vec[n / 2]){
          sequence.push_back(n - 1);
          n--;
        }
        else{
          sequence.push_back(n / 2);
          n = n / 2;
        }
      }
      else if(n % 2 != 0){
        if(vec[n - 1] < vec[n / 3]){
          sequence.push_back(n - 1);
          n--;
        }
        else{
          sequence.push_back(n / 3);
          n = n / 3;
        }
      }
      else{
          if(vec[n - 1] < vec[n / 2]){
            if(vec[n - 1] < vec[n / 3]){
              sequence.push_back(n - 1);  
              n--;
            }
            else{
              sequence.push_back(n / 3);
              n = n / 3;
            }
          }
          else{
            if(vec[n / 2] < vec[n / 3]){
              sequence.push_back(n / 2);
              n = n / 2;
            }
            else{
              sequence.push_back(n / 3);
              n = n / 3;
            }
          }
      }
    }
  }

  /*while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
      if(n % 3 == 0){

      }
  }*/
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
