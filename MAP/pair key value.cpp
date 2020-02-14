#include<iostream>
#include<map>
using namespace std;


int main()
{

   map<pair<int ,int> ,pair<int ,int> > m;
   
//   m.insert(make_pair(1,2), make_pair(3,4));
   m[make_pair(1,2)] = make_pair(3,4);
   
//   cout << m.size() << endl;
//   map<pair<int ,int> ,pair<int ,int> >::iterator it;
//   for(it = m.begin() ; it != m.end() ; ++it){
//   		cout << it->first.first << " / " << it->first.second << " : " << it->second.first << " / " << it->second.second << endl;
//   }
   
   cout << m[{1,2}].first << " / " << m[{1,2}].second;
   
//   cout << m[{1, 2}];
   
}
