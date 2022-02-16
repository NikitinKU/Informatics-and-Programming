/*����������� �������� ��������� ��������� � �������� ������ ������ � �������� ��������, ������������� �� ����������� / �������� �������.
    ������� ������ :
        ���� �� ����������, � ������� ���������� ������������� ����������.
        ����� ����������.
    �������� ������ :
        ��������������� ������ ���� ������ � ��������� �������.
        ����� ����������.
��������� ������ ������������� ������������ ����������� ������� ����� ���������� � �������� ����������� �������� ������.
��������� ������ ������������� ������ � ������������� ����������� ����������, ������� �������� :
����������� ����� ���� �� ��������� ��������;
����������� ������ ������ ����������;
����������� ��������� ���������������� ������ ������ � ��������� �������.
������ ������ ������� ���������� �������� ��������.������, ������� ������ ����� ����������� ������ ������� ����� ������������ ��������.
    ������ �����������:
        ������� 6. ���������� �������, ����� (quick sort), ���������� ��������
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> 
#include "C:\Git Hub\dirent-1.23.2\include\dirent.h"    // ��� ������ � ������������
#include <sys/stat.h>                           // ��� ������������ ������� �����

char filesName[255][255];
int filesSize[255];
int arrayCount = 0;

/// <summary>
/// �������, ������������ ������ �����
/// </summary>
/// <param name="file">������ ��� ������������� ���� �� �����</param>
/// <returns>������ �����</returns>
int getFileSize(const char* file) {
    struct stat st;
    int full_size = 0;

    if (stat(file, &st) == 0) {
        // ���� ��� �����
        if ((st.st_mode & S_IFMT) == S_IFDIR)
            return -1;
        // ���� ������� ����
        else if ((st.st_mode & S_IFMT) == S_IFREG)
            return st.st_size;
        // ���� ���-�� ���� (�����, FIFO (����������� �����) � ��.)
        else
            return -2;
    }
}

/// <summary>
/// �������, ���������� �������� ������ � ������� � �������� � ���������� ������������
/// </summary>
/// <param name="path">���� �� ��������</param>
void getSizesFromDir(char* path) {
    struct dirent* cur_file;
    DIR* dir;

    char full_file_path[200];

    // ��������� ������� ����������
    dir = opendir(path);

    // ���� ������� ������� ����������
    if (dir) {
        // ��������� ����� ������ ���������� � ���������� cur_file, ���� ����� �� ��������
        while ((cur_file = readdir(dir)) != NULL) {
            // ���������� ��������� ����� ./ � ../
            // ���� �������� ������, ������������ �� . ��� .. - ���������� ��
            if (strcmp(".", cur_file->d_name) && strcmp("..", cur_file->d_name)) {
                // �������� ���� � ����� ����������, ��������� ������ ����������� ����������,
                // ��������� ��� �������� (����� ��� �����)
                strcpy(full_file_path, strcat(strcat(strcpy(full_file_path, path), "/"), cur_file->d_name));
                // �������� ������ ��� -1, ���� ��� �� ����, � ��������� �����
                int cur_file_size = getFileSize(full_file_path);
                if (cur_file_size >= 0) {
                    // ��� ����� �������� ��� ��� � ������
                    printf("%s - %d B (%d kB)\n", cur_file->d_name, cur_file_size, cur_file_size / 1024);
                    filesSize[arrayCount] = cur_file_size;
                    strncpy(filesName[arrayCount], cur_file->d_name, 254);
                    filesName[arrayCount][254] = '\0';
                    arrayCount++;
                }

                else if (cur_file_size == -1)
                    // ��� ��������� ����� �������� ���������� ���������� �����
                    getSizesFromDir(full_file_path);
            }
        }
        // �� �������� ������� ����������
        closedir(dir);
    }
}

/// <summary>
/// �������, �������������� �������� �������
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
    // ��������� ���� (�� ���� scanf_s ��� ������)
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