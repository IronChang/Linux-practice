int sum = 0,min = arr[0];
		int i, j;
		for(int i = 0; i < length; i++){
			sum += arr[i];
			min = arr[i] < min ? arr[i] : min;
		}
		std::vector<int> dp(sum + 1, 0);
		for(i = 0; i < length; i++){
			for(j = sum; j >= arr[i]; j--){
				if (dp[j] < dp[j - arr[i]] + arr[i])
				//��ÿ�����ؼ��㵱ǰ����ܷ�������
					dp[j] = dp[j - arr[i]]+ arr[i];
						//���±������ܹ���������ֵ
				else
					dp [j] = dp[j];
			}
		}
		//��󵱳���Ϊnʱ�������������Ϊn����Ϊ����󲻿����
		for (i = min; i <= sum; i++){
			if (i != dp[i])
			return i;
		}
		return sum + 1;

