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

    	//���� ���
    	if (curY < 0 || curY > H + 1 || curX < 0 || curX > W + 1)	continue;

        //�̹� �湮�� �����̰ų�, ���̰ų�, ��� ���� ���
		if (visited[curY][curX] || bluePrint[curY][curX] == '*' || ('A' <= bluePrint[curY][curX] && bluePrint[curY][curX] <= 'Z'))	continue;
		
        visited[curY][curX] = true; //�湮 ǥ��

        //����
        if (bluePrint[curY][curX] == '$'){
        	document++;
			bluePrint[curY][curX] = '.';
        }

                 //���� ã���� ���

                 if ('a' <= bluePrint[curY][curX] && bluePrint[curY][curX] <= 'z')

                 {

                         char door = (char)toupper(bluePrint[curY][curX]);

                         bluePrint[curY][curX] = '.';

 

                         //�̹� �ִ� ���迡 ���ؼ��� ó������ �ʴ´�

                         if (key[(int)door - 65] == false)

                         {

                                 key[(int)door - 65] = true;

                                 //��� ���� ����

                                 for (int y = 1; y <= H; y++)

                                          for (int x = 1; x <= W; x++)

                                                  if (bluePrint[y][x] == door)

                                                          bluePrint[y][x] = '.';

                                 //��� ���� �������Ƿ� ��� ��θ� �ٽ� Ȯ��

                                 memset(visited, false, sizeof(visited));

                                 while (!q.empty())

                                          q.pop();

                                 q.push(make_pair(curY, curX));

                                 continue;

                         }

                 }

                 //������������ �ϴ� ������

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

        //�׵θ��� �� ĭ����
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

                     key[(int)alphabet[j] - 97] = true; //���� ����

                     //���� ����д�

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
