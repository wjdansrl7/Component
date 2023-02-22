#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(string str, char delimiter);

int main()
{
    string test = "This is string.";
    vector<string> result = split(test, ' ');
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
}

// std::getline(string)
// istream& getline(istream& is, string& str);
// istream& getline(istream& is, string& str, char delim);
// 인자
// is: 입력스트림 오브젝트 ex) cin
// str: 입력받은 문자열을 저장할 string 객체
// delim: 제한자로 이 문자에 도달 시 추출이 중단됨.(이 문자는 스트림에서 사라지게 된다.)

vector<string> split(string input, char delimiter)
{
    vector<string> answer;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter))
    {
        answer.push_back(temp);
    }

    return answer;
}