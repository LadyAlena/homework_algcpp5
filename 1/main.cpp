#include <iostream>
#include <vector>
#include <string>

// Функция для вывода элемента пирамиды
void print_element(int level, const std::string& position, int value) {
    std::cout << level << " " << position << "(" << value << ") " << value << std::endl;
}

// Функция для вычисления индекса левого потомка
int left_child(int parent_index) {
    return 2 * parent_index + 1;
}

// Функция для вычисления индекса правого потомка
int right_child(int parent_index) {
    return 2 * parent_index + 2;
}

// Функция для вывода пирамиды
void print_pyramid(const std::vector<int>& heap) {
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
}

int main() {
    // Примеры тестовых массивов
    std::vector<int> heap1 = {1, 3, 6, 5, 9, 8};
    std::vector<int> heap2 = {94, 67, 18, 44, 55, 12, 6, 42};
    std::vector<int> heap3 = {16, 11, 9, 10, 5, 6, 8, 1, 2, 4};

    // Вывод пирамид для каждого из массивов
    std::cout << "Исходный массив: ";
    for (int num : heap1) {
        std::cout << num << " ";
    }
    std::cout << std::endl << "Пирамида:" << std::endl;
    print_pyramid(heap1);
    std::cout << std::endl;

    std::cout << "Исходный массив: ";
    for (int num : heap2) {
        std::cout << num << " ";
    }
    std::cout << std::endl << "Пирамида:" << std::endl;
    print_pyramid(heap2);
    std::cout << std::endl;

    std::cout << "Исходный массив: ";
    for (int num : heap3) {
        std::cout << num << " ";
    }
    std::cout << std::endl << "Пирамида:" << std::endl;
    print_pyramid(heap3);
    std::cout << std::endl;

    return 0;
}