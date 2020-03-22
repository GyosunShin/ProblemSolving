#include <string> 
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct Page{
	int idx;
	int basic, link;
	double score;
	
};

bool comp(Page& a, Page& b){
	if(a.score == b.score)	return a.idx < b.idx;
	else	return a.score > b.score;
	
}

int solution(string word, vector<string> pages){
	int wsize = word.size();
	map<string, int> pagehash; // (URL, INDEX)
	vector<Page> pagelist;
	
	//일단 전부 다 소문자로 변환한다.
	transform(word.begin(), word.end(), word.begin(), ::tolower);
	
	for(int i = 0 ; i < pages.size() ; ++i){
		string& s = pages[i];
		transform(s.begin(), s.end(), s.begin(), ::tolower);
		
		int mid = 0, posl = 0, posr;
		while(mid <= posl){
			posl = s.find("<meta", posl + 1);
			posr = s.find(">", posl)	;
			mid = s.rfind("https://", posr);
		}
		posr = s.find("\"", mid);
		string url = s.substr(mid, posr - mid);
		
		posl = s.find("<body>", posr);
		int basic = 0;
		for(int start = posl ; ;){
			start = s.find(word, start + 1);
			if(start == string::npos)	break;
			if(!isalpha(s[start - 1]) && !isalpha(s[start+wsize])){
				basic++;
				start += wsize;
			}
		}
		
		int link = 0;
		for(int start = posl ; ;){
			start = s.find("<a href", start + 1);
			if(start == string::npos)	break;
			link++;
		}
		
		pagehash[url]  = i;
		pagelist.push_back({i, basic, link, (double)basic});
		
	}  // 모든 페이지에 대한 점수들을 구하는 작업 끝남 일단! 
	
	
	for(int i = 0 ; i < pages.size() ; ++i){
		string& s = pages[i];
		for(int posl = 0, posr = 0 ; ;){
			posl = s.find("<a href", posr);
			if(posl == string::npos)	break;
			
			posl = s.find("https://", posl);
			posr = s.find("\"", posl);
			string linkurl = s.substr(posl, posr - posl);
			
			map<string, int>::iterator it = pagehash.find(linkurl);
			if(it != pagehash.end()){
				pagelist[it->second].score += (double)pagelist[i].basic / pagelist[i].link;
			}
		}
	}
	
	sort(pagelist.begin(), pagelist.end(), comp);
	return pagelist.begin()->idx;
}

