// arr1[] = {7, 1, 5, 2, 3, 6}
// arr2[] = {3, 8, 6, 20, 7}

// C++ program for the union of two arrays using Set
#include <bits/stdc++.h>
using namespace std;
void getUnion(int a[], int n, int b[], int m)
{

    // Defining set container s
    set<int> s;

    // Inserting array elements in s
    for (int i = 0; i < n; i++)
        s.insert(a[i]);

    for (int i = 0; i < m; i++)
        s.insert(b[i]);
    cout << "Number of elements after union operation: "
         << s.size() << endl;
    cout << "The union set of both arrays is :" << endl;
    for (auto itr = s.begin(); itr != s.end(); itr++)
        cout << *itr << " "; // s will contain only distinct
                             // elements from array a and b
}

// Driver Code
int main()
{
    int a[9] = {1, 2, 5, 6, 2, 3, 5, 7, 3};
    int b[10] = {2, 4, 5, 6, 8, 9, 4, 6, 5, 4};

    getUnion(a, 9, b, 10);
}

// contributed by Anirban Chand
