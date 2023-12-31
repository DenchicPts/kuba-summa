﻿#include <iostream>

using namespace std;

const int MAX_NUMBERS = 20;
int smallestLength = 100;


void showCombination(int comb[], int len) {

    cout << "Комбинация: ";
    for (int i = 0; i < len; ++i) {
        cout << comb[i];
        if (i < len - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

void findCubicSums(int N, int num, int sum,
    int comb[], int len, int smallestComb[]) {

    if (sum == N) {
        showCombination(comb, len);

        if (len < smallestLength) {
            smallestLength = len;
            for (int i = 0; i < len; ++i) {
                smallestComb[i] = comb[i];
            }
        }
        return;
    }

    for (int i = num; i <= N; ++i) {
        int cube = i * i * i;
        if (sum + cube > N) {
            return;
        }

        comb[len] = i;
        findCubicSums(N, i + 1, sum + cube, comb, len + 1,
             smallestComb);
    }
}

int main() {

	setlocale(LC_ALL, "Russian");
    int N;
    cout << "Введите натуральное число N: ";
    cin >> N;

    int comb[MAX_NUMBERS];
    int smallestComb[MAX_NUMBERS];

    cout << "Возможные варианты представления " << N
        << " в виде суммы кубов различных натуральных чисел:\n";
    findCubicSums(N, 1, 0, comb, 0, smallestComb);

    if (smallestLength == 100) {
        cout << "Нет комбинаций для числа " << N << ".\n";
    }
    else {
        cout << "Самая маленькая комбинация по количеству цифр: ";
        showCombination(smallestComb, smallestLength);
    }

    return 0;
}
