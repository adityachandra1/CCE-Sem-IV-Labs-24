#include <iostream>
using namespace std;

class Item{
    public:
    int weight;
    int cost;
    int position;
    double density;
};

void swap(Item *xp, Item *yp)
{
    Item temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(Item items[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)
        for (j = 0; j < n-i-1; j++)
            if (items[j].density < items[j+1].density)
            {
                swap(&items[j], &items[j+1]);
            }
}

int main()
{
    int n , c;
    cout << "Enter no of items and capacity" << endl;
    cin >> n >> c;

    Item items[n+1];
    int X[n+1] = {0};
    int total_cost = 0;

    cout << "Enter weights: " << endl;
    for(int i = 0; i < n; i++){
        cin >> items[i].weight;
    }

    cout << "Enter Cost: " << endl;
    for(int i = 0; i < n; i++){
        cin >> items[i].cost;
        items[i].density = (double)items[i].cost/items[i].weight;
        items[i].position = i;
    }
    cout << endl;

    bubbleSort(items, n);

    for(int i = 0; i < n && items[i].weight <= c; i++){
        X[items[i].position] = 1;
        c -= items[i].weight;
        total_cost += items[i].cost;
    }

    cout << "Selected Items: ";
    for(int i = 0; i < n; i++){
        cout << X[i] << " ";
    }
}
