#include<iostream>
using namespace std; 

class Board {
public:
    bool checkWon(vector<vector<int> > board) {
        // write code here
        //�������жϵ�ǰ���ʤ�������������
        //���һ����ȫ��������ͬ��
        //���������ȫ��������ͬ��
        //����������Խ�ȫ������ͬ��
        //����ģ����Խ�ȫ������ȣ�
        int i = 0,j = 0,sum = 0;
        int row = board.size();
        //���1
        for(i = 0; i < board.size(); i++)
        {
            sum = 0;
            for(j = 0; j < board[i].size(); j++)
            {
                sum += board[i][j];
            }
            if(sum == row)
                return true;
        }
        
        //�����
        for(i = 0; i < board.size(); i++)
        {
            sum = 0;
            for(j = 0; j<board[i].size(); j++)
            {
                sum +=board[j][i];
            }
            if(sum == row)
                return true;
        }
        
        //�����
        sum = 0;
        for(i = 0; i < board.size(); i++)
        {
            sum += board[i][i];
        }
        if(sum == row)
        {
            return true;
        }
        
        //�����
        sum = 0;
        for(i = 0; i < board.size(); i++)
        {
            sum += board[i][row-i-1];
        }
        if(sum == row)
        {
            return true;
        }
        return false;
    }
};

int main()
{
	Board d;
	int n;
	cin>>n;
	vector<vector<int>> a(n.vector<int>(n));
	for(int i = 0; i < a.size(); i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin>>a[i][j];
		}
	}
	
	if(b.checkWon(a))
	{
		cout<<"win"<<endl;
	}
	else
	{
		cout<<"No"<<endl;
	}
	return 0;
}
