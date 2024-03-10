// main.cpp
// программа калькулятор
// использование лямбда функция

#include <iostream>
#include <functional>


// шаблонный класс калькулятор
template<typename Type>
class Calculation{
public:

// метод вычисления заданной алгоритмом функции
// a, b - числа передаваемые в фукнцию
// alg - функция для вычислений
Type Calc(Type a, Type b,std::function<Type(Type &,Type &)> alg);

private:
};

template<typename Type>
Type Calculation<Type>::Calc(Type a, Type b, std::function<Type(Type &,Type &)>func){

    return func(a,b);
}


int main(){

    // объект для работы с целыми числами
    Calculation<int> intCalc;

    // объект для работы с вещественными числами
    Calculation<double> dblCalc;

    int result{};
    double resul{};

    // вычисляем сумму чисел используя лямбда функцию
    result = intCalc.Calc(5,4,[](int a,int b){return a + b;});

    // проверяем результат
    std::cout << "5 + 4 = " << result << std::endl;

    // вычисляем произведение чисел
    result = intCalc.Calc(2,3,[](int a, int b)->int {return a*b;});

    // проверяем рузультат
    std::cout << "2 * 3 = " << result << std::endl;

    // вычислим отношение вещественных чисел
    resul = dblCalc.Calc(3.2,2.0,[](double a,double b){return a/b;});

    // проверяем результат
    std::cout << "3.2/2.0 = " << resul << std::endl;
    
    return 0;
}