#include <iostream>
#include <sstream>
using namespace std;

// istringstream은 문자열을 여러 개의 문자열로 분리할 때 편리하다.

int main(int argc, char const *argv[])
{
    string str = "abc def gg 11";
    string s[4];
    istringstream stt(str);
    for (int i = 0; i < 4; i++)
    {
        stt >> s[i];
    }

    for (int i = 0; i < 4; i++)
    {
        cout << s[i];
    }

    return 0;
}
