#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

long long MaxPairwiseProduct_Fast(const vector<int>& vec_nums )
{
    int s = vec_nums.size();
    int max_index_1 = -1;
    int max_index_2 = -1;

    for (int i = 0; i < s ; ++i)
    {
        if ( (max_index_1 == -1) || (vec_nums[i] >= vec_nums[max_index_1] ) )
        {
            max_index_1 = i;
        }
    }


    for (int i = 0; i < s ; ++i)
    {
        if (i == max_index_1)
            continue;

        if ( (max_index_2 == -1) || (vec_nums[i] >= vec_nums[max_index_2]))
        {
            max_index_2 = i;
        }
    }
    //cout << " Max indexes " << max_index_1 << " , " << max_index_2 << std::endl;

    long long result = ( (long long) (vec_nums[max_index_1])  * vec_nums[max_index_2]);
    return result;
}


int MaxPairwiseProduct_Brute_Force(const vector<int>& numbers) {
  int result = 0;
  int n = numbers.size();
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (numbers[i] * numbers[j] > result) {
        result = numbers[i] * numbers[j];
      }
    }
  }
  return result;
}

int main() {
    int n;
    //cout << " How many numbers ? " << std::endl;
    cin >> n;
    //cout << " Enter numbers ! " << std::endl;

    vector<int> vec_numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec_numbers[i];
    }

    long long result = MaxPairwiseProduct_Fast(vec_numbers);
    cout << result << "\n";
    return 0;
}
