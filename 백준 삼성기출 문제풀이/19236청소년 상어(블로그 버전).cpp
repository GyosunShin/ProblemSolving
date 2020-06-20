#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 4;

typedef struct
{
	int y, x;
}Dir;

Dir moveDir[9] = { {0, 0}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1} };

typedef struct
{
	int idx, dir;
	int y, x;
}Fish;

int result;
Fish shark;
Fish fishes[MAX * MAX + 1];
int fishTank[MAX][MAX];

void func(Fish fishes[MAX * MAX + 1], int fishTank[MAX][MAX], Fish shark, int total)
{
	result = max(result, total);

	// fish
	for (int i = 1; i <= MAX * MAX; i++)
	{
		int y = fishes[i].y;
		int x = fishes[i].x;
		int dir = fishes[i].dir;

		if (dir == 0)
		{
			continue;
		}

		int nextY = y + moveDir[dir].y;
		int nextX = x + moveDir[dir].x;

		int dirChangeCnt = 0;

		for (dirChangeCnt = 0; dirChangeCnt < 8; dirChangeCnt++)
		{
			nextY = y + moveDir[dir].y;
			nextX = x + moveDir[dir].x;

			if (nextY < 0 || nextY >= MAX || nextX < 0 || nextX >= MAX)
			{
				fishes[i].dir = (dir == 8) ? 1 : dir + 1;
				dir = fishes[i].dir;

				continue;
			}

			if (nextY == shark.y && nextX == shark.x)
			{
				fishes[i].dir = (dir == 8) ? 1 : dir + 1;
				dir = fishes[i].dir;

				continue;
			}

			break;
		}

		if (dirChangeCnt == 8)
		{
			continue;
		}

		int nextIdx = fishTank[nextY][nextX];

		if (nextIdx)
		{
			fishes[nextIdx].y = y;
			fishes[nextIdx].x = x;
			fishTank[y][x] = nextIdx;
		}
		else
		{
			fishTank[y][x] = 0;
		}

		fishes[i].y = nextY;
		fishes[i].x = nextX;
		fishTank[nextY][nextX] = i;
	}

	// shark
	int y = shark.y;
	int x = shark.x;
	int dir = shark.dir;

	for (int i = 1; i <= 3; i++)
	{
		Fish tempFishes[MAX * MAX + 1];

		for (int idx = 0; idx < MAX * MAX + 1; idx++)
		{
			tempFishes[idx] = fishes[idx];
		}

		int tempFishTank[MAX][MAX];

		for (int j = 0; j < MAX; j++)
		{
			for (int k = 0; k < MAX; k++)
			{
				tempFishTank[j][k] = fishTank[j][k];
			}
		}

		int nextY = y + moveDir[dir].y * i;
		int nextX = x + moveDir[dir].x * i;

		if (nextY < 0 || nextY >= MAX || nextX < 0 || nextX >= MAX)
		{
			continue;
		}

		if (tempFishTank[nextY][nextX] == 0)
		{
			continue;
		}

		shark.y = nextY;
		shark.x = nextX;

		int score = tempFishTank[nextY][nextX];
		tempFishTank[nextY][nextX] = 0;

		shark.dir = tempFishes[score].dir;
		tempFishes[score].dir = 0;

		func(tempFishes, tempFishTank, shark, total + score);
	}
}

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int y = 0; y < MAX; y++){
		for (int x = 0; x < MAX; x++){
			int idx, dir;
			cin >> idx >> dir;

			if (y == 0 && x == 0){
				shark = { idx, dir, y, x };
				continue;
			}

			fishes[idx] = { idx, dir, y, x };
			fishTank[y][x] = idx;
		}
	}

	func(fishes, fishTank, shark, shark.idx);

	cout << result << "\n";

	return 0;
}
