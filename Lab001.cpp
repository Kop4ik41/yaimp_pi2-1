#include <iostream>
#include <algorithm>

// Шаблонная функция для вычисления медианы
template<typename T>
T median(T arr[], int size) {
    // Проверка на пустой массив
    if (size <= 0) {
        throw std::invalid_argument("Массив не может быть пустым");
    }
    
    // Создаем копию массива для сортировки
    T* sortedArr = new T[size];
    for (int i = 0; i < size; i++) {
        sortedArr[i] = arr[i];
    }
    
    // Сортируем массив
    std::sort(sortedArr, sortedArr + size);
    
    T result;
    
    // Вычисляем медиану в зависимости от четности размера
    if (size % 2 == 0) {
        // Для четного количества - среднее двух центральных элементов
        result = (sortedArr[size/2 - 1] + sortedArr[size/2]) / 2;
    } else {
        // Для нечетного количества - центральный элемент
        result = sortedArr[size/2];
    }
    
    delete[] sortedArr;
    return result;
}

// Перегрузка для целых чисел (чтобы избежать целочисленного деления)
template<>
double median<int>(int arr[], int size) {
    if (size <= 0) {
        throw std::invalid_argument("Массив не может быть пустым");
    }
    
    int* sortedArr = new int[size];
    for (int i = 0; i < size; i++) {
        sortedArr[i] = arr[i];
    }
    
    std::sort(sortedArr, sortedArr + size);
    
    double result;
    if (size % 2 == 0) {
        result = (sortedArr[size/2 - 1] + sortedArr[size/2]) / 2.0;
    } else {
        result = sortedArr[size/2];
    }
    
    delete[] sortedArr;
    return result;
}

// Пример использования
int main() {
    // Тестирование с разными типами данных
    
    // Массив целых чисел (нечетный размер)
    int intArr1[] = {5, 2, 8, 1, 9};
    int size1 = sizeof(intArr1) / sizeof(intArr1[0]);
    std::cout << "Медиана [5, 2, 8, 1, 9]: " << median(intArr1, size1) << std::endl;
    
    // Массив целых чисел (четный размер)
    int intArr2[] = {4, 1, 3, 2};
    int size2 = sizeof(intArr2) / sizeof(intArr2[0]);
    std::cout << "Медиана [4, 1, 3, 2]: " << median(intArr2, size2) << std::endl;
    
    // Массив double
    double doubleArr[] = {1.5, 2.7, 3.1, 4.8, 5.2, 6.0};
    int size3 = sizeof(doubleArr) / sizeof(doubleArr[0]);
    std::cout << "Медиана [1.5, 2.7, 3.1, 4.8, 5.2, 6.0]: " << median(doubleArr, size3) << std::endl;
    
    // Массив float
    float floatArr[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
    int size4 = sizeof(floatArr) / sizeof(floatArr[0]);
    std::cout << "Медиана [1.1, 2.2, 3.3, 4.4, 5.5]: " << median(floatArr, size4) << std::endl;
    
    return 0;
}
