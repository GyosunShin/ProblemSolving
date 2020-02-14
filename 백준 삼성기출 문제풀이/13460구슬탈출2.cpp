#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
 
struct INFO {
    int ry, rx, by, bx, count;
};
 
INFO start;
char map[10][11];
 
int bfs() {
	// 상, 하, 좌, 우 
    const int dy[] = { -1, 1, 0, 0 };
    const int dx[] = { 0, 0, -1, 1 };
 
    int visited[10][10][10][10] = { 0, };
    queue<INFO> q;
    q.push(start);
    visited[start.ry][start.rx][start.by][start.bx] = 1;
     
    int ret = -1;
    while (!q.empty()) {
    	//##########################
        INFO cur = q.front();   q.pop();
        //##########################
        if (cur.count > 10)  break;
        
        // 원하는 목표인 RED구슬만 구멍에! 
        // 탈출조건!!!! 
        if (map[cur.ry][cur.rx] == 'O' && map[cur.by][cur.bx] != 'O') {
            ret = cur.count;
            break;
        }
 
        for (int dir = 0; dir < 4; ++dir) {

            int next_ry = cur.ry;
            int next_rx = cur.rx;
            int next_by = cur.by;
            int next_bx = cur.bx;
            cout << "RED1 : (" << next_ry << ", " << next_rx << endl;
 			cout << "BLUE1 : (" << next_by << ", " << next_bx << endl;
 
 			// RED구슬 벽다다르기 전까지 한방향으로 계속 
            while (1) {
                if (map[next_ry][next_rx] != '#' && map[next_ry][next_rx] != 'O') {
                    next_ry += dy[dir], next_rx += dx[dir];
                }
                else { 
                    if (map[next_ry][next_rx] == '#') {  // 벽에 부딪히면 빠꾸 해준다. 
                        next_ry -= dy[dir], next_rx -= dx[dir];
                    }
                    // 구멍에 다다랐으면 빠꾸 안하고.. 
                    break;
                }
            }
 
 			// BLUE구슬 벽다다르기 전까지 한방향으로 계속
            while (1) {
                if (map[next_by][next_bx] != '#' && map[next_by][next_bx] != 'O') {
                	cout << "마라도나 " << endl;
                    next_by += dy[dir], next_bx += dx[dir];
                }
                else {  // BLUE가 이전단계에서 '구멍'에 다다르면 여기서 걸려브리겠네~~! 
                    if (map[next_by][next_bx] == '#') {
                        next_by -= dy[dir], next_bx -= dx[dir];
                    }
                    // BLUE가 구멍이면 if문 못 거치므로 아예 움직이질 못해버리네 
                    break;
                }
            }
            cout << "RED : (" << next_ry << ", " << next_rx << endl;
 			cout << "BLUE : (" << next_by << ", " << next_bx << endl;
 			
 			// RED랑 BLUE구슬이 같은지점에 위치하게 된 경우 
            if (next_ry == next_by && next_rx == next_bx) {
                if (map[next_ry][next_rx] != 'O') {  // 그 지점이 구멍이 아닐경우 
                    int red_dist = abs(next_ry - cur.ry) + abs(next_rx - cur.rx);
                    int blue_dist = abs(next_by - cur.by) + abs(next_bx - cur.bx);
                    // 지금까지 더 많이 걸어온놈을 빠꾸시켜! 
                    if (red_dist > blue_dist) {
                        next_ry -= dy[dir], next_rx -= dx[dir];
                    }
                    else {
                        next_by -= dy[dir], next_bx -= dx[dir];
                    } 
                }
            }
 
 
 			// 그니까 이미 방문한 좌표이면 queue에 집어넣지 않는다 
 			// 이 말인 즉슨 이미 방문한곳이 아닐 경우에만  
            if (visited[next_ry][next_rx][next_by][next_bx] == 0) {
                visited[next_ry][next_rx][next_by][next_bx] = 1;
                //##########################
                INFO next;
                next.ry = next_ry;
                next.rx = next_rx;
                next.by = next_by;
                next.bx = next_bx;
                //##########################
                next.count = cur.count + 1;
                //##########################
                q.push(next);
            }
        }  // End of For(4가지 방향별 결과 모두 시도)
    } // End of While(!q.empty())
    
    return ret;
}
 
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", map[i]);
    }
 
    for (int y = 0; y < n; ++y) {
        for (int x = 0; x < m; ++x) {
            if (map[y][x] == 'R') {
                start.ry = y, start.rx = x;
            }
            if (map[y][x] == 'B') {
                start.by = y, start.bx = x;
            }
        }
    }
    start.count = 0;
 
    int ret = bfs();
    printf("%d\n", ret);
 
    return 0;
}


