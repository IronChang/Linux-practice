#include <iostream>
#include<vector>
using namespace std;
int main(){
	int size;
	cin >> size;
	vector<int> nums(size);
	for(size_t i = 0; i < size; ++i)
		cin >> nums[i];
		
	int result = nums[0];
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < nums.size(); i++){
		// 计算到num[i]的子数组的最大和
		sum2 = sum1 >= 0 ? sum1+nums[i] : nums[i];
		if(sum2 > result)
			result = sum2;
		if(sum2 < 0)
			sum2 = 0;
		sum1 = sum2;
	}
	cout << result << endl;
	return 0;
}
