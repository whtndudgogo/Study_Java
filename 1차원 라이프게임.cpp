#include <iostream>
using namespace std;

int life_game(int n, int k);

int main()
{
	//���� ���� 
	int t;   // t : ���� Ƚ�� 
	int n, k; // n : �迭 ũŰ, k : �ð� ���� 
	
	cin >> t;
	for(int i = 0; i < t; i ++)
	{
		cin >> n >> k;
		life_game(n, k); // �׽�Ʈ ���� 
	}
	return 0;
}

int life_game(int n, int k)
{
	int arr[n]; //�� �迭 ����
	int pre_num = 0; //���� ����� �ݿ��ϱ� �� ���� ���
	int sum_sides = 0; // �̿� ���� ���׸��� �� �� 
	//�� �迭 �Է� 
	for(int i = 0; i < n; i++) cin >> arr[i];
	 
	
	//�ð� ���- k
	for(int j = 0; j < k; j++)
	{
//		cout << j+1 << "��° ���� ����============================" << endl;
		for(int s = 0; s < n; s++)
		{
			// �̿��ϴ� ���׸��� �� �� ���ϱ� 
			if(s == 0 || s == n-1) //���� ���� ���� ������ �� üũ
			{
				if ( s == 0 ) sum_sides = arr[1];
				if ( s == n-1 ) sum_sides = pre_num;
			}
			else sum_sides = pre_num + arr[s+1];
			
//			cout << "�̿� �� : " << sum_sides << endl;
			
			pre_num = arr[s]; // ���� ���� ���� s-1
			
			//�̿��� �տ� ���� ���� ���� - (0,1,2) : -1 | (3) : 0 | (4,5,6,7) : +1 | (7����ũ��) : -1 
			if (sum_sides < 3) 
			{
				if(arr[s] != 0) 
				{
					arr[s] -= 1;
//					cout << "���ҽ��� "; 
				}
			}
			else if (sum_sides == 3) arr[s] = arr[s];
			else if (sum_sides >= 4 && sum_sides <= 7)
			{	
				if (arr[s] != 9 ) {
					arr[s] += 1;
//					cout << "�������� ";
				}
			}  
			else if (sum_sides > 7) {
				if(arr[s] != 0) {
					arr[s] -= 1;
//					cout << "���ҽ��� "; 
				}
					
			}
			
			
//			cout << "��ȯ �� : " << pre_num << " �� " << arr[s] << endl;
		}
//		cout << j+1 << "��° ���� ��############################" << endl; 
	} 
	
	//���
	for(int i = 0; i < n; i++) cout << arr[i] << " ";
	cout << endl; 
}
