// [�Է�]
//3    T
//3    (N(2 �� N �� 1,000,000))
//10 7 6   �� ���� �ŸŰ��� 10,000�����̴�
//3
//3 5 9
//5
//1 1 3 1 2

// [���]
//#1 0
//#2 10
//#3 5

#include <stdio.h> 
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//  �䷱������... 
//	vector<pair<int, string> > v;
//	v.push_back(pair<int, string>(90, "���ѿ�"));

int main(){
	int T;
	scanf("%d", &T);
	vector<int> vecs[T];    // �׽�Ʈ ���̽��� �ŸŰ� list 
	vector<int> vecs2[T];   // �� �ε����� �ִ����Ͱ� list 
	for(int i = 0 ; i < T ; ++i){
		int N;
		scanf("%d", &N);
		for(int j = 0 ; j < N ; ++j){
			int tmp;
			scanf("%d", &tmp);	
			vecs[i].push_back(tmp);
		}		
	}
	
	for(int i = 0 ; i < T ; ++i){  // �� �׽�Ʈ�� ����
		vecs2[i].push_back(0);
		for(int j = 0 ; j < vecs[i].size() ; ++j) {
			int tmpsum = 0; 
			for(int k = 0 ; k < j ; ++k){  // �ڽź��� ���� �ε��� �����鼭..
				
				if( vecs[i][k] < vecs[i][j] ){   // �� ���� �ŸŰ��� ���϶��� �߰��ؾ� �Ѵ�. 
					tmpsum += abs(vecs[i][k] - vecs[i][j]);
				}	
			}
			vecs2[i].push_back(tmpsum);
		}
	}
	
	for(int i = 0 ; i < T ; ++i){
		int tmpBest = 0;
		for(int j = 0 ; j < vecs2[i].size() ; ++j){
			if(tmpBest < vecs2[i][j]) tmpBest = vecs2[i][j];
		}
		cout << "#" << (i+1) << " " << tmpBest << endl;
	}
	
}



// ********************* ���⼭���ʹ� ���ͳ� ��ó ************ ���� �����ϰ� Ǯ����.... ����... ************** 
//#include <iostream>
//using namespace std;
//int num[1000002] = {0,};
//int main(){
//    int T;
//    cin>>T;
//    
//    for(int i = 0; i<T; i++){
//
//        int N;
//        long long ans = 0;
//        
//        cin>>N;
//        for(int j = 0; j<N; j++){
//            cin>>num[j];
//        }
//        
//        int max_budget = num[N-1];
//        
//        for(int j = N-1; j>=0; j--){
//            if(max_budget >= num[j]){
//                ans = ans + (max_budget-num[j]);
//            }
//            else{
//                max_budget = num[j];
//            }
//        }
//        cout<<"#"<<i+1<<" "<<ans<<"\n";
//        for(int j = 0; j<N; j++){
//            num[j] = 0;
//        }
//        
//    }
//    return 0;
//}

