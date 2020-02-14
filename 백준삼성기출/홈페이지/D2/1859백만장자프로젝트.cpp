// [입력]
//3    T
//3    (N(2 ≤ N ≤ 1,000,000))
//10 7 6   각 날의 매매가는 10,000이하이다
//3
//3 5 9
//5
//1 1 3 1 2

// [출력]
//#1 0
//#2 10
//#3 5

#include <stdio.h> 
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//  요런식으로... 
//	vector<pair<int, string> > v;
//	v.push_back(pair<int, string>(90, "박한울"));

int main(){
	int T;
	scanf("%d", &T);
	vector<int> vecs[T];    // 테스트 케이스별 매매가 list 
	vector<int> vecs2[T];   // 각 인덱스별 최대이익값 list 
	for(int i = 0 ; i < T ; ++i){
		int N;
		scanf("%d", &N);
		for(int j = 0 ; j < N ; ++j){
			int tmp;
			scanf("%d", &tmp);	
			vecs[i].push_back(tmp);
		}		
	}
	
	for(int i = 0 ; i < T ; ++i){  // 각 테스트별 실행
		vecs2[i].push_back(0);
		for(int j = 0 ; j < vecs[i].size() ; ++j) {
			int tmpsum = 0; 
			for(int k = 0 ; k < j ; ++k){  // 자신보다 낮은 인덱스 훑으면서..
				
				if( vecs[i][k] < vecs[i][j] ){   // 더 낮은 매매가의 날일때만 추가해야 한다. 
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



// ********************* 여기서부터는 인터넷 출처 ************ 존나 간단하게 풀었네.... 에휴... ************** 
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

