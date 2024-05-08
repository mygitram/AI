#include <iostream>
#include <vector>

using namespace std;

void greedySelectionSort(vector<int> &array)
{
    int n = array.size();
    vector<int> sorted;
    int minIndex = -1, flag = false, temp;
    // logic 1
    // for (int i = 0; i < n; i++)
    // {
    //     minIndex = i;
    //     flag = false;
    //     for (int j = i; j < n; j++)
    //     {
    //         if (array[minIndex] > array[j])
    //         {
    //             minIndex = j;
    //             flag = true;
    //         }
    //     }
    //     if (flag)
    //     {
    //         temp = array[minIndex];
    //         array[minIndex] = array[i];
    //         array[i] = temp;
    //     }
    // }

//another logic 2
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (array[i] > array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

int main()
{
    vector<int> array = {5, 2, 9, 1, 5, 6};

    cout<< "Original Array: ";
    for (int num : array)
    {
        cout << num << " ";
    }
    cout << endl;

    greedySelectionSort(array);

    cout << "Sorted Array (using Greedy Selection Sort): ";
    for (int num : array)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
