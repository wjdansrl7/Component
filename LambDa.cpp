/*
lambda는 람다 표현식 또는 람다 함수, 익명 함수(anonymous function)로 불립니다.
성질은 함수 객체와 동일하다. 그 이름처럼 몸통은 있지만, 이름은 없는 함수
lambda는 함수 객체 클래스를 암시적으로 정의하고 함수 객체를 생성한다.
lambda로 생성된 함수 객체는 타입을 가지고 있긴 하지만 decltype이나 sizeof를
사용할 순 없습니다.

함수 객체 vs lambda
함수 포인터는 Callback 함수를 상황에 따라 다르게 하거나 Strategy 패턴을 구현할 때 주로 씁니다. 하지만
함수 포인터는 상태를 가질 수 없기 때문에 상태를 가져야하는 함수가 필요할 땐 함수 객체를 씁니다. 둘 다 장단점이 있다
함수 객체의 가장 큰 단점은 번거로움, 함수 객체를 정의할 땐 클래스나 구조체를 정의해야 한다. 코드도 길어지고 보기도 좋지 않음.

lambda는 함수 포인터와 함수 객체의 장점만 골라 가졌다고 볼 수 있다.
정의하기 위해서 클래스나 구조체를 정의할 필요가 없고 상태도 가질 수 있다.

*/

#include <array>
#include <algorithm>
#include <stdio.h>

// 함수 객체로 구현
struct SumFunctor : public std::unary_function<int, void>
{
    SumFunctor(int &number) : sum(number) {}

    void operator()(int &number)
    {
        sum += number;
    }

private:
    int &sum;
};

int main(int argc, char const *argv[])
{
    std::array<int, 5> numbers = {1, 2, 3, 4, 5};
    int sum = 0;

    std::for_each(numbers.begin(), numbers.end(), SumFunctor(sum));

    printf("%d", sum);

    sum = 0;

    // lambda로 구현
    std::for_each(numbers.begin(), numbers.end(), [&sum](int &number)
                  { sum += number; });

    printf("%d", sum);

    return 0;
}
