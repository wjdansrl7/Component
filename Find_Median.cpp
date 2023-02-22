#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

/*
중앙값이란, 어떤 배열을 정렬했을 때 정 가운데에 위치하는 값을 말한다.
*/

// 정렬된 배열에서 중앙값 찾기
// 배열이 정렬되어 있다면 땡큐지만, 정렬되어 있지 않다면 정렬해야 하므로, 가장 먼저 정렬을 수행한다.

float median(vector<int> &arr)
{
    sort(arr.begin(), arr.end());

    if (arr.size() % 2 == 1)
    {
        return (float)arr[arr.size() / 2];
    }

    else
    {
        return ((float)arr[arr.size() / 2] + (float)arr[arr.size() / 2 + 1]) / 2.0f;
    }
}

// 데이터가 지속적으로 추가/삭제되고 있는 상황에서 중앙값을 찾으려면 위의 방법은 비효율
// 중앙값을 찾을 때마다 배열 전체에 대한 정렬을 계속 시도해야하므로

// 추가/삭제가 정렬과 함께 이루어지는 자료구조는 여러가지가 있지만, 중앙값을 찾는데에는 heap을 이용할 수 있다.

// MAX heap은 최대값에 바로 접근
// Min heap은 최소값에 바로 접근
