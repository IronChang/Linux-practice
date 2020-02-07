class Bonus {
public:
	int getMost(vector<vector<int> > board) {
		for (int i = 1; i<6; i++){
			board[0][i] += board[0][i - 1];//�ȳ�ʼ����һ��
			board[i][0] += board[i - 1][0];//�ȳ�ʼ����һ��
		}
		for (int i = 1; i<6; i++){
			for (int j = 1; j<6; j++){//�ڶ��еڶ��п�ʼ�����ϵ��´����ҽ�������ۼ�
				board[i][j] += board[i - 1][j]>board[i][j - 1] ? board[i - 1][j] : board[i][j - 1];
			}
		}
		return board[5][5];//����߷���õ�����ֵ
	}
};

int main()
{
	vector<vector<int>> vv(6);
	for(int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			vv[i].push_back(j);
		}
	}

	Bonus b;
	cout<<b.getMost(vv)<<endl;
	system("pause");
	return 0;
}
