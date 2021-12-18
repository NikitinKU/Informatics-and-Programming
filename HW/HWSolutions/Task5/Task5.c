/*Разработать прототип файлового менеджера с функцией показа файлов в заданном каталоге, упорядоченных по возрастанию / убыванию размера.
    Входные данные :
        Путь до директории, в которой необходимо отсортировать содержимое.
        Метод сортировки.
    Выходные данные :
        Отсортированный список имен файлов с указанием размера.
        Время сортировки.
Программа должна предоставлять пользователю возможность сменить метод сортировки и повторно формировать выходные данные.
Программа должна реализовывать диалог с пользователем посредством интерфейса, который включает :
возможность ввода пути до заданного каталога;
возможность выбора метода сортировки;
возможность просмотра отсортированного списка файлов с указанием размера.
Полный список методов сортировки задается отдельно.Методы, которые должен будет реализовать каждый студент также определяются отдельно.
    Методы сортировкия:
        вариант 6. Сортировка выбором, Хаора (quick sort), сортировка слиянием
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> 
#include "C:\Git Hub\dirent-1.23.2\include\dirent.h"    // для работы с директориями
#include <sys/stat.h>                           // для установления размера файла

char filesName[255][255];
int filesSize[255];
int arrayCount = 0;

/// <summary>
/// функция, возвращающая размер файла
/// </summary>
/// <param name="file">полный или относительный путь до файла</param>
/// <returns>размер файла</returns>
int getFileSize(const char* file) {
    struct stat st;
    int full_size = 0;

    if (stat(file, &st) == 0) {
        // если это папка
        if ((st.st_mode & S_IFMT) == S_IFDIR)
            return -1;
        // если обычный файл
        else if ((st.st_mode & S_IFMT) == S_IFREG)
            return st.st_size;
        // если что-то иное (сокет, FIFO (именованный канал) и др.)
        else
            return -2;
    }
}

/// <summary>
/// функция, печатающая названия файлов и размеры в каталоге и внутренних подкаталогов
/// </summary>
/// <param name="path">путь до каталога</param>
void getSizesFromDir(char* path) {
    struct dirent* cur_file;
    DIR* dir;

    char full_file_path[200];

    // открываем рабочую директорию
    dir = opendir(path);

    // если удалось открыть директорию
    if (dir) {
        // считываем файлы внутри директории в переменную cur_file, пока файлы не кончатся
        while ((cur_file = readdir(dir)) != NULL) {
            // игнорируем системные папки ./ и ../
            // если попались записи, начинающиеся на . или .. - пропускаем их
            if (strcmp(".", cur_file->d_name) && strcmp("..", cur_file->d_name)) {
                // копируем путь в новую переменную, вставляем символ разделителя директории,
                // добавляем имя элемента (файла или папки)
                strcpy(full_file_path, strcat(strcat(strcpy(full_file_path, path), "/"), cur_file->d_name));
                // получаем размер или -1, если это не файл, а вложенная папка
                int cur_file_size = getFileSize(full_file_path);
                if (cur_file_size >= 0) {
                    // для файла печатаем его имя и размер
                    printf("%s - %d B (%d kB)\n", cur_file->d_name, cur_file_size, cur_file_size / 1024);
                    filesSize[arrayCount] = cur_file_size;
                    strncpy(filesName[arrayCount], cur_file->d_name, 254);
                    filesName[arrayCount][254] = '\0';
                    arrayCount++;
                }

                else if (cur_file_size == -1)
                    // для вложенной папки вызываем РЕКУРСИВНО написанный метод
                    getSizesFromDir(full_file_path);
            }
        }
        // не забываем закрыть директорию
        closedir(dir);
    }
}

/// <summary>
/// Функция, переставляющая элементы местами
/// </summary>
/// <param name="p1"></param>
/// <param name="p2"></param>
void swap(int* p1, int* p2) {
    int tmp = p1;
    p1 = p2;
    p2 = tmp;
}

void selection_sort(int* A, int size) {
    int minInd;
    for (int i = 0; i < size - 1; i++) {
        minInd = i;
        for (int j = i + 1; j < size; j++) {
            if (A[j] < A[minInd]) minInd = j;
        }
        swap(A[i], A[minInd]);
    }
}

void quick_sort(int* A, int low, int high) {
    if (low < high) {
        int left = low;
        int right = high;
        int middle = A[(left + right) / 2];
        do {
            while (A[left] < middle)
                left++;
            while (A[right] > middle)
                right--;
            if (left <= right) {
                swap(A[left], A[right]);
                left++;
                right--;
            }
        } while (left < right);
        quick_sort(A, low, high);
        quick_sort(A, left, right);
    }
}

void inputIndexArray(int* array, int size) {
    for (int j = 0; j < size; j++) {
        array[j] = j;
    }
}

void copyArray(int* array_1, int* array_2, int size) {
    for (int j = 0; j < size; j++) {
        array_1[j] = array_2[j];
    }
}

int main() {
    char path[200];
    int isWork = 1, sortVariant;
    // считываем путь (по сути scanf_s для строки)
    printf("Input path to dir: ");
    gets(path);
    getSizesFromDir(path);

    printf("\n: %d", arrayCount);

    int* allArrayIndex_1 = malloc(sizeof(int) * arrayCount);
    inputIndexArray(allArrayIndex_1, arrayCount);
    int* arrayCopy_1 = malloc(sizeof(int) * arrayCount);
    copyArray(arrayCopy_1, filesSize, arrayCount);

    int* allArrayIndex_2 = malloc(sizeof(int) * arrayCount);
    inputIndexArray(allArrayIndex_2, arrayCount);
    int* arrayCopy_2 = malloc(sizeof(int) * arrayCount);
    copyArray(arrayCopy_2, filesSize, arrayCount);

    int* allArrayIndex_3 = malloc(sizeof(int) * arrayCount);
    inputIndexArray(allArrayIndex_3, arrayCount);
    int* arrayCopy_3 = malloc(sizeof(int) * arrayCount);
    copyArray(arrayCopy_3, filesSize, arrayCount);

    while (isWork) {
        scanf_s("%d", sortVariant);

        switch (sortVariant) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 0:
            break;
        default:
            break;
        }
    }

    return 0;
}