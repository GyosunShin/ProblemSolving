
//  기본점수 / 외부 링크 수 / 링크점수 / "매칭점수"

// OUTPUT 
// "매칭점수"가 가장 높은 웹페이지의 index를 구하라. 만약 그런 웹페이지가 여러 개라면 그중 번호가 가장 작은 것을 구하라.

// 검색어를 찾을 때, 대소문자 구분은 무시하고 찾는다.
// 단어는 알파벳을 제외한 다른 모든 문자로 구분한다.

#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

int answer;

vector<string> urls;
vector<pair<string, string>> links;	// (src, dst)
vector<int> scores;	// 기본점수
vector<int> external; // 외부링크 수 
 //  링크점수 = sum(기본점수 ÷외부 링크 수)
  // 매칭점수 = 기본점수 + 링크점수

vector<int> forme[20];
map<string, int> m;

string target;


bool alpha(char& input){
	if(('a' <= input && input <= 'z') || ('A' <= input && input <= 'Z'))	return true;
	return false;
}

int check(string& input){
	
	int sum = 0;
	
	for(int i = 0 ; i < input.size() ; ++i){
		string tmp = "";
		if(alpha(input[i])){
			
			while(true)	{
				if(!alpha(input[i]) || i >= input.size()){
					
					break;
				}
				tmp += input[i];
				
				++i;
				
			}
			
			if(strcasecmp(target.c_str(), tmp.c_str()) == 0)	++sum;
			
//			cout << "!! " << tmp << " !!" << endl;
			tmp.clear();
			--i;
		}
		
	}
	return sum;
}

void analy(string& input, int idx){
	
	vector<string> lines;
	string url;
	string link_url;
	int score = 0;
	int ex = 0;
	
	string tmp = "";
	// 일단 '\n' 단위로 잘라서 출력
	for(int i = 0 ;  i < input.size() ; ++i) {
		if(input[i] == '\n'){
			lines.push_back(tmp);
			tmp.clear();
			continue;
		}
		tmp += input[i];
	}
	lines.push_back(tmp);
	tmp.clear();
	
	for(int i = 0 ;  i < lines.size() ; ++i){
		int start_idx = 0;;
		for(int j = 0 ; j < lines[j].size() ; ++j){
			if(lines[i][j] != ' '){
				start_idx = j;
				break;
			}
		}
		
		string sstr = lines[i].substr(start_idx);
		
		for(int j = 0 ; j < sstr.size() ; ++j){
			string tmp = "";
			
			if(sstr[j] == '<'){
				++j;
				while(true){
					if(sstr[j] == '>'){
						++j;
						break;
					}
					tmp += sstr[j];
					++j;
				}
				
				if(tmp.size() > 23 && tmp.substr(0, 22+15+3) == "meta property=\"og:url\" content=\"https://"){
					url = tmp.substr(32);
					url.pop_back();	url.pop_back();	
					urls.push_back(url);
					m[url] = idx;
				}
				else if(tmp.size() > 8 && tmp.substr(0, 7+9) == "a href=\"https://"){
					++ex;
					link_url = tmp.substr(8);
					link_url.pop_back();	
					links.push_back({url, link_url});
				}
				
				tmp.clear();
			}
			else{
				while(true){
					if(sstr[j] == '<' || j >= sstr.size())	break;
					tmp += sstr[j];
					++j;
				}
				
				score += check(tmp);
				
				tmp.clear();
			}
			
			--j;
		}
		
	}
//	cout << "SCORE  :  " << score << endl;
	scores.push_back(score);	// 기본점수 
	external.push_back(ex);
	
}

bool comp(pair<double, int>& a, pair<double, int>& b){
	
	if(a.first == b.first)	return a.second < b.second;
	return a.first > b.first;
	
}


int solution(string word, vector<string> pages) {
	
	target = word;
	
	for(int i = 0 ; i < pages.size() ; ++i){		
		analy(pages[i], i);
	}
	
	for(int i = 0 ; i < links.size(); ++i){
		
		string src = links[i].first;	string dst = links[i].second;
		int src_idx = m[src];	
		
		map<string, int>::iterator it;
		it = m.find(dst);
		if(it == m.end()){
			continue;
		}
		int dst_idx = m[dst];
//		cout << "DST :  " << dst_idx << endl;
		
		forme[dst_idx].push_back(src_idx);
		
	}
	
	vector<pair<double, int>> ans;
	
	for(int i= 0 ; i < pages.size() ; ++i){
		
		// scores / externals
		double sum = 0;
		
		for(int j = 0 ; j < forme[i].size() ; ++j){
			sum +=	(double)scores[forme[i][j]] / (double)external[forme[i][j]];
		}
//		cout << "SUM : "<< sum << " / IDX : " << i << endl; 
		ans.push_back({sum + scores[i], i});
		
	}
	 
//	for(int i= 0 ; i < pages.size() ; ++i){
//		cout << "기본점수 :  " << scores[i] << "/ 외부링크수  :  " << external[i] << endl; 
//	}
	
	sort(ans.begin(), ans.end(), comp);
	
    return ans[0].second;
}





