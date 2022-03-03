#include <QCoreApplication>
#include <iostream>
#include <EStackEmpty.h>
#include <EStackException.h>
#include <Stack.h>

int main()
{
    //QCoreApplication a(argc, argv);

    //return a.exec();

    //Тестим
    Stack<int> Stack;
    Stack.Push(2);
    Stack.Push(3);
    Stack.Push(4);
    Stack.Push(5);

    std::cout << Stack.Size() << std::endl;

    int d = Stack.Pop();

    std::cout << d << std::endl;
    std::cout << Stack.Size() << std::endl;

    return 1;
}
