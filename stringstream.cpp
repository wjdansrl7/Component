#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// stringstream은 주어진 문자열에서 필요한 자료형에 맞는 정보를 꺼낼 때 유용하게 사용

int main(int argc, char const *argv[])
{
    int num;
    string s;
    string str1 = "123 456", str2 = "hello world";
    stringstream stream1, stream2(str2);

    // 초기화
    stream1.str(str1);
    while (stream1 >> num)
    {
        cout << num << endl;
    }

    while (stream2 >> s)
    {
        cout << s << endl;
    }

    return 0;
}
