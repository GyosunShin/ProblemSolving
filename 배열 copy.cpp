#include <iostream>
#include<algorithm>

using namespace std;

int main()
{
	uint16_t src[16], dst[16];

	for (int i = 0; i < 16; i++)
	{
		src[i] = i * i;
	}

	copy(src, src + 16, dst);

	for (int i = 0; i < 16; i++)
		cout << i << " : " << dst[i] << endl;

//  2차원 배열 복사		
//	copy(&arr1[0][0], &arr1[0][0] + ARR_SIZE * ARR_SIZE, &arr2[0][0]);

	return 0;
}

