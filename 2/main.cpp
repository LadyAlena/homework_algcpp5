#include <iostream>
#include <vector>
#include <string>

// Функция для вывода элемента пирамиды
void print_element(int level, const std::string& position, int value) {
    std::cout << level << " " << position << "(" << value << ") " << value << std::endl;
}

// Функция для вычисления индекса левого потомка
bool left_child(int parent_index, int& child_index, const std::vector<int>& heap) {
    child_index = 2 * parent_index + 1;
    return child_index < heap.size();
}

// Функция для вычисления индекса правого потомка
bool right_child(int parent_index, int& child_index, const std::vector<int>& heap) {
    child_index = 2 * parent_index + 2;
    return child_index < heap.size();
}

// Функция для вычисления индекса родителя
bool parent(int child_index, int& parent_index) {
    if (child_index == 0) {
        return false;
    }
    parent_index = (child_index - 1) / 2;
    return true;
}

int main() {
    // Примеры тестовых массивов
    std::vector<int> heap1 = {1, 3, 6, 5, 9, 8};
    std::vector<int> heap2 = {94, 67, 18, 44, 55, 12, 6, 42};
    std::vector<int> heap3 = {16, 11, 9, 10, 5, 6, 8, 1, 2, 4};

    // Выбор пирамиды для работы
    std::vector<int> heap = heap1;

    // Вывод исходного массива и пирамиды
    std::cout << "Исходный массив: ";
    for (int num : heap) {
        std::cout << num << " ";
    }
    std::cout << std::endl << "Пирамида:" << std::endl;
    for (int i = 0; i < heap.size(); ++i) {
        int level = 0;
        std::string position = "root";
        
        if (i > 0) {
            int parent_index = (i - 1) / 2;
            level = 1;
            position = (i % 2 == 1) ? "left" : "right";
            position += "(" + std::to_string(heap[parent_index]) + ")";
        }
        
        print_element(level, position, heap[i]);
    }

    std::cout << std::endl;

    int current_index{};

    std::string input_user{};

    while(true) {
        std::cout << "Вы находитесь здесь: ";
        if (current_index == 0) {
            std::cout << "0 root " << heap[current_index] << std::endl;
        } else {
            int parent_index;
            if (parent(current_index, parent_index)) {
                std::string position = (current_index % 2 == 1) ? "left" : "right";
                position += "(" + std::to_string(heap[parent_index]) + ")";
                std::cout << "1 " << position << " " << heap[current_index] << std::endl;
            }
        }
        std::cout << "Введите команду: ";
        std::getline(std::cin, input_user);

        if(input_user == "up") {
            if (parent(current_index, current_index)) {
                std::cout << "Ок" << std::endl;
            } else {
                std::cout << "Ошибка! Отсутствует родитель" << std::endl;
            }
        }
        else if(input_user == "left") {
            int left_child_index{};
            if (left_child(current_index, left_child_index, heap)) {
                current_index = left_child_index;
                std::cout << "Ок" << std::endl;
            } else {
                std::cout << "Ошибка! Отсутствует левый потомок" << std::endl;
            }
        }
        else if(input_user == "right") {
            int right_child_index{};
            if (right_child(current_index, right_child_index, heap)) {
                current_index = right_child_index;
                std::cout << "Ок" << std::endl;
            } else {
                std::cout << "Ошибка! Отсутствует правый потомок" << std::endl;
            }
        }
        else if(input_user == "exit") {
            break;
        }
        else {
            std::cout << "Неверная команда. Возможно Вы имели в виду 'up', 'left', 'right' или 'exit'. Повторите попытку..." << std::endl;
        }
    };

    return 0;
}
