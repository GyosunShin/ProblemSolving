#include <iostream>
#include <string>
#include <queue>
#include <cstring> //memset

using namespace std;


const int MAX = 100 + 2;

typedef struct{
    int y, x;
}Dir;
 
Dir moveDir[4] = { {1, 0}, {-1, 0} , {0, 1}, {0, -1} };

int H, W;
string bluePrint[MAX];
bool visited[MAX][MAX];
bool key[26];
int document;

void BFS(int y, int x){

    queue<pair<int, int>> q;
    q.push(make_pair(y, x));

    while (!q.empty()){

    	int curY = q.front().first;
        int curX = q.front().second;

        q.pop();

    	//범위 벗어남
    	if (curY < 0 || curY > H + 1 || curX < 0 || curX > W + 1)	continue;

        //이미 방문한 지점이거나, 벽이거나, 잠긴 문일 경우
		if (visited[curY][curX] || bluePrint[curY][curX] == '*' || ('A' <= bluePrint[curY][curX] && bluePrint[curY][curX] <= 'Z'))	continue;
		
        visited[curY][curX] = true; //방문 표시

        //문서
        if (bluePrint[curY][curX] == '$'){
        	document++;
			bluePrint[curY][curX] = '.';
        }

                 //열쇠 찾았을 경우

                 if ('a' <= bluePrint[curY][curX] && bluePrint[curY][curX] <= 'z')

                 {

                         char door = (char)toupper(bluePrint[curY][curX]);

                         bluePrint[curY][curX] = '.';

 

                         //이미 있던 열쇠에 대해서는 처리하지 않는다

                         if (key[(int)door - 65] == false)

                         {

                                 key[(int)door - 65] = true;

                                 //잠긴 문을 연다

                                 for (int y = 1; y <= H; y++)

                                          for (int x = 1; x <= W; x++)

                                                  if (bluePrint[y][x] == door)

                                                          bluePrint[y][x] = '.';

                                 //잠긴 문이 열렸으므로 모든 경로를 다시 확인

                                 memset(visited, false, sizeof(visited));

                                 while (!q.empty())

                                          q.pop();

                                 q.push(make_pair(curY, curX));

                                 continue;

                         }

                 }

                 //동서남북으로 일단 가본다

                 for (int i = 0; i < 4; i++)

                 {

                         int nextY = curY + moveDir[i].y;

                         int nextX = curX + moveDir[i].x;

 

                         q.push(make_pair(nextY, nextX));

                 }

        }

}

 

int main(void){
    int test_case;
    cin >> test_case;
    
    for (int i = 0; i < test_case; i++){

        memset(key, false, sizeof(key));

        for (int j = 0; j < MAX; j++)	bluePrint[j].clear();

        memset(visited, false, sizeof(visited));

        cin >> H >> W;

        //테두리를 빈 칸으로
        for (int j = 0; j < W + 2; j++)	bluePrint[0] += '.';

             for (int j = 1; j <= H; j++)

             {

                     string temp;

                     cin >> temp;

                     bluePrint[j] += '.';

                     bluePrint[j] += temp;

                     bluePrint[j] += '.';

             }

             for (int j = 0; j < W + 2; j++)

                     bluePrint[H + 1] += '.';



             string alphabet;

             cin >> alphabet;



             for (int j = 0; alphabet[j] != '0' && j < alphabet.length(); j++)

             {

                     key[(int)alphabet[j] - 97] = true; //열쇠 설정

                     //문을 열어둔다

                     for (int y = 1; y <= H; y++)

                             for (int x = 1; x <= W; x++)

                             {

                                      if (bluePrint[y][x] == (char)toupper(alphabet[j]))

                                              bluePrint[y][x] = '.';

                             }

             }



             document = 0;

             BFS(0, 0);

             cout << document << endl;

    }

    return 0;

}
