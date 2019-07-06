#include <iostream>
using namespace std;

int life_game(int n, int k);

int main()
{
	//변수 선언 
	int t;   // t : 실행 횟수 
	int n, k; // n : 배열 크키, k : 시간 단위 
	
	cin >> t;
	for(int i = 0; i < t; i ++)
	{
		cin >> n >> k;
		life_game(n, k); // 테스트 실행 
	}
	return 0;
}

int life_game(int n, int k)
{
	int arr[n]; //셀 배열 생성
	int pre_num = 0; //셀의 결과를 반영하기 전 값을 기억
	int sum_sides = 0; // 이웃 셀의 박테리아 수 합 
	//셀 배열 입력 
	for(int i = 0; i < n; i++) cin >> arr[i];
	 
	
	//시간 경과- k
	for(int j = 0; j < k; j++)
	{
//		cout << j+1 << "번째 수행 시작============================" << endl;
		for(int s = 0; s < n; s++)
		{
			// 이웃하는 박테리아 수 합 구하기 
			if(s == 0 || s == n-1) //가장 왼쪽 셀과 오른쪽 셀 체크
			{
				if ( s == 0 ) sum_sides = arr[1];
				if ( s == n-1 ) sum_sides = pre_num;
			}
			else sum_sides = pre_num + arr[s+1];
			
//			cout << "이웃 합 : " << sum_sides << endl;
			
			pre_num = arr[s]; // 이전 값을 갱신 s-1
			
			//이웃의 합에 따른 조건 수행 - (0,1,2) : -1 | (3) : 0 | (4,5,6,7) : +1 | (7보다크다) : -1 
			if (sum_sides < 3) 
			{
				if(arr[s] != 0) 
				{
					arr[s] -= 1;
//					cout << "감소실행 "; 
				}
			}
			else if (sum_sides == 3) arr[s] = arr[s];
			else if (sum_sides >= 4 && sum_sides <= 7)
			{	
				if (arr[s] != 9 ) {
					arr[s] += 1;
//					cout << "증가실행 ";
				}
			}  
			else if (sum_sides > 7) {
				if(arr[s] != 0) {
					arr[s] -= 1;
//					cout << "감소실행 "; 
				}
					
			}
			
			
//			cout << "변환 값 : " << pre_num << " → " << arr[s] << endl;
		}
//		cout << j+1 << "번째 수행 끝############################" << endl; 
	} 
	
	//출력
	for(int i = 0; i < n; i++) cout << arr[i] << " ";
	cout << endl; 
}
