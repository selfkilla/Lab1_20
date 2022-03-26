#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <functional>
#include <EStackEmpty.h>
#include <EStackException.h>

//Стек опишем как шаблонный класс на основе односвязного списка
template<class T>
class Stack {
private:
    struct NodeStack { //Узел описываем структурой
        const T item_;
        NodeStack *pointPrevious_; //Указатель на предыдущее звено стека
    };
    NodeStack *pointBottom_; // Указатель на последний элемент стека
    int size_ = 0;


public:
    ~Stack() {Clear();} //Деструктор
    
    void Clear() { // Удаление вслех узлов
        while(pointBottom_ != nullptr) { //Пока последний элемент не нулевой, то есть пока в стеке все ещё есть элементы
            NodeStack *tmp = pointBottom_;
            pointBottom_ = pointBottom_->pointPrevious_;
            delete tmp;
        }

    }

    void Push(const T &item) { //Кладем значение в стек
        NodeStack *node = new NodeStack{item, pointBottom_}; //Создаём новое звено

        if(node == nullptr) {
            throw EStackException("No memory!");
        }

        pointBottom_ = node; //Делаем новое звено последним
        size_++; //Увеличиваем размер стека
    }

    const T Pop() { //Извлекаем значение из стека
        if(pointBottom_ == nullptr) { //Если стек пустой, выбрасываем исключение
            throw EStackEmpty();
        }

        const T item = pointBottom_->item_; //Сохраняем значение
        NodeStack *tmp = pointBottom_;
        pointBottom_ = pointBottom_->pointPrevious_; //Конец стека теперь на предпоследнем элементе
        delete tmp; //Удаляем последнее звено
        size_--; //Уменьшаем размер стека
        return item; //Возвращаем новое значение
    }

    int Size() {
        return size_;
    }

};

#endif // STACK_H
