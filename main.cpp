#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <chrono>


using namespace std;
using namespace std::chrono;
const int SIZE = 100000;

void QuickSort(int arry[], int arraySize);

int Partition(int arry[], int arraySize, int pivotIndex);

void MergeSort(int arry[], int start, int end);

void Merge(int arry[], int leftFirst, int leftLast, int rightFirst, int rightLast);

void BubbleSort(int arry[], int arraySize);

void ExChangeSort(int *array, int length);

void SelectionSort(int arry[], int arraySize);

void InsertionSort(int arry[], int arraySize);

void printArray(int arry[], int arraySize);

int main() {
    int arry[SIZE];
    srand(time(NULL));

    for (int x = 0; x < SIZE; ++x) {
        arry[x] = rand() + 1;
    }

    typedef high_resolution_clock Time;
    typedef milliseconds ms;
    typedef duration<float> fsec;
    auto t0 = Time::now();

    //MergeSort(arry, 0, SIZE - 1);
    //QuickSort(arry, SIZE);
    ExChangeSort(arry,SIZE);
    //InsertionSort(arry,SIZE);
    //SelectionSort(arry,SIZE);
    //BubbleSort(arry, SIZE);

    printArray(arry, SIZE);
    auto t1 = Time::now();
    fsec fs = t1 - t0;
    ms d = std::chrono::duration_cast<ms>(fs);
    cout << "Duration of Sorting in QuickSort \nfor " << SIZE << " random integers: \n" << fs.count() << " s\n";
    return 0;
}

void QuickSort(int arry[], int arraySize) {
    if (arraySize > 1) {
        int pivotIndex = rand() % (arraySize - 1);
        int newPiviotIndex = Partition(arry, arraySize, pivotIndex);
        QuickSort(arry, newPiviotIndex);
        QuickSort(arry + newPiviotIndex + 1, arraySize - newPiviotIndex - 1);
    }
}

int Partition(int arry[], int arraySize, int pivotIndex) {
    int pivotValue = arry[pivotIndex];
    arry[pivotIndex] = arry[arraySize - 1];
    arry[arraySize - 1] = pivotValue;
    int left = 0;
    int right = arraySize - 2;

    while (left < right) {
        while ((arry[left] < pivotValue) && (left < right)) {
            ++left;
        }
        while ((arry[right] >= pivotValue) && (left < right)) {
            --right;
        }
        if (left < right) {
            std::swap(arry[left], arry[right]);
            ++left;
            --right;
        }
    }
    if (left == right) {
        if (arry[left] < pivotValue) {
            ++left;
        }
    }
    arry[arraySize - 1] = arry[left];
    arry[left] = pivotValue;
    return left;
}


void MergeSort(int arry[], int start, int end) {
    if (start < end) {
        int midPt = (start + end) / 2;
        MergeSort(arry, start, midPt);
        MergeSort(arry, midPt + 1, end);
        Merge(arry, start, midPt, midPt + 1, end);
    }
}

void Merge(int arry[], int leftFirst, int leftLast, int rightFirst, int rightLast) {
    int *tempArray = new int[rightLast];
    int index = leftFirst;
    int saveFirst = leftFirst;

    while ((leftFirst <= leftLast) && (rightFirst <= rightLast)) {
        if (arry[leftFirst] < arry[rightFirst]) {
            tempArray[index] = arry[leftFirst];
            ++leftFirst;
        } else {
            tempArray[index] = arry[rightFirst];
            ++rightFirst;
        }
        ++index;
    }

    while (leftFirst <= leftLast) {
        tempArray[index] = arry[leftFirst];
        ++leftFirst;
        ++index;
    }
    while (rightFirst <= rightLast) {
        tempArray[index] = arry[rightFirst];
        ++rightFirst;
        ++index;
    }
    for (index = saveFirst; index <= rightLast; ++index) {
        arry[index] = tempArray[index];
    }
}


void ExChangeSort(int *array, int length) {
    int temp = 0;
    int i, j;
    for (i = 0; i < (length - 1); i++) {
        for (j = (i + 1); j < length; j++) {
            if (array[i] < array[j]) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}


void InsertionSort(int arry[], int arraySize) {
    int previousNumber = 0;
    int currentNumber = 0;


    for (int index = 1; index < arraySize; ++index) {
        currentNumber = arry[index];
        previousNumber = index - 1;

        while (previousNumber >= 0 && arry[previousNumber] > currentNumber) {
            arry[previousNumber + 1] = arry[previousNumber];
            previousNumber = previousNumber - 1;
        }
        arry[previousNumber + 1] = currentNumber;
    }
}


void SelectionSort(int arry[], int arraySize) {
    for (int currentNumber = 0; currentNumber < arraySize; ++currentNumber) {
        int index_of_min = currentNumber;

        for (int previousNumber = currentNumber + 1; previousNumber < SIZE; ++previousNumber) {
            if (arry[index_of_min] > arry[previousNumber]) {
                index_of_min = previousNumber;
            }
        }
        int temp = arry[currentNumber];
        arry[currentNumber] = arry[index_of_min];
        arry[index_of_min] = temp;
    }
}


void BubbleSort(int arry[], int arraySize) {
    bool sorted = false;

    do {
        sorted = true;
        for (int x = 0; x < arraySize - 1; ++x) {
            if (arry[x] > arry[x + 1]) {
                int temp = arry[x];
                arry[x] = arry[x + 1];
                arry[x + 1] = temp;
                sorted = false;
            }
        }// end of for loop
        --arraySize;
    } while (!sorted);
}

void printArray(int arry[], int arraySize) {
    for (int i = arraySize-200; i < arraySize; ++i) {
        cout << arry[i] << "\t";
    }
}