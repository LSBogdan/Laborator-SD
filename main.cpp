#include <iostream>
#include <chrono>
#include <algorithm>


using namespace std;
using namespace std::chrono;


int v[1000000], copie[1000000], a[1000000], ap[1000000];

void generare_test(int n, int minim, int maxim, int v[])
{
    for(int i = 1; i <= n; i++)
        v[i] = rand() % (maxim + 1 - minim) + minim;

}

void afisare(int n, int v[])
{
    for(int i = 1; i <= n; i++)
        cout<<v[i]<<" ";
    cout<<endl;
}

void Copiere(int n, int v[], int copie[])
{
    for(int i = 1; i <= n; i++)
        copie[i] = v[i];
}

void BubbleSort(int n, int v[])
{
    int ok = 1, i;
    while (ok == 1)
    {
        ok = 0;
        for (i = 1; i < n; i++)
            if (v[i] > v[i + 1])
            {
                swap(v[i], v[i + 1]);
                ok = 1;
            }
    }
}

void CountSort(int n, int maxim, int v[])
{
    int i, j, k = 0;

    for (i = 1; i <= n; i++)
        ap[v[i]] += 1;

    for (i = 0; i <= maxim; i++)
        if (ap[i])
            for (j = 1; j <= ap[i]; j++)
                v[++k] = i;
}

void InsertionSort(int n, int copie[])
{
    int i, j, k;
    for(i = 1; i <= n; i++)
    {
        k = copie[i];
        j = i;
        while(j > 0 && copie[j-1] > k)
        {
            copie[j] = copie[j-1];
            j--;
        }
        copie[j] = k;
    }
}

void MergeSort(int p, int u, int v[], int a[])
{
    if(p < u)
    {
        int m = (p + u) / 2;
        MergeSort(p, m, v, a);
        MergeSort(m+1, u, v, a);
        int i = p, j = m + 1, k = 0;
        while(i <= m && j <= u)
        {
            if(v[i] < v[j])
                a[++k]= v[i++];
            else
                a[++k] = v[j++];
        }
        while(i <= m)
            a[++k] = v[i++];
        while(j <= u)
            a[++k] = v[j++];
        for(int i = p, j = 1; i <= u; i++,j++)
            v[i] = a[j];

    }

}

void poz(int p, int u, int &k, int copie[])
{
    int x = copie[p], i = p;
    k = u + 1;
    do
    {
        do
        {
            i++;
        }
        while(copie[i] < x);
        do
        {
            k--;
        }
        while(copie[k] > x);
        if(i<k)
            swap(copie[i],copie[k]);
    }
    while(i < k);
    swap(copie[p],copie[k]);
}

void Quicksort(int p, int u, int v[])
{
    int m;
    if(p < u)
    {
        poz(p, u, m, v);
        Quicksort(p, m - 1, v);
        Quicksort(m + 1, u, v);
    }
}

int main()
{
    int t, n, maxim, i, j;
    cin >> t;
    for(i = 1; i <= t; i++)
    { cin >> n >> maxim;

     generare_test(n, 1, maxim, v);
     Copiere(n, v, copie);

     cout<<"Pentru testul "<<i<<" avem urmatoarele rezultate:"<<endl;

     cout << "BubbleSort:" << endl;
     auto start = high_resolution_clock::now();
     BubbleSort(n, copie);
     auto stop = high_resolution_clock::now();
     duration<double> secunde = stop - start;
     cout << "S-a terminat sortarea in " << secunde.count() << " secunde" << endl;
   
     Copiere(n, v, copie);
     cout<< "CountSort:" << endl;
     auto start = high_resolution_clock::now();
     CountSort(n, maxim, copie);
     auto stop = high_resolution_clock::now();
     duration<double> secunde = stop - start;
     cout << "S-a terminat sortarea in " << secunde.count() << " secunde" << endl;

     Copiere(n, v, copie);
     cout<<"InsertionSort:"<<endl;
     auto start = high_resolution_clock::now();
     InsertionSort(n, copie);
     auto stop = high_resolution_clock::now();
     duration<double> secunde = stop - start;
     cout << "S-a terminat sortarea in " << secunde.count() << " secunde" << endl;
  
     Copiere(n, v, copie);
     cout<<"MergeSort:"<<endl;
     auto start = high_resolution_clock::now();
     MergeSort(1, n, copie, a);
     auto stop = high_resolution_clock::now();
     duration<double> secunde = stop - start;
     cout << "S-a terminat sortarea in " << secunde.count() << " secunde" << endl;

     Copiere(n, v, copie);
     cout<<"QuickSort:"<<endl;
     auto start = high_resolution_clock::now();
     Quicksort(1, n, copie);
     auto stop = high_resolution_clock::now();
     duration<double> secunde = stop - start;
     cout << "S-a terminat sortarea in " << secunde.count() << " secunde" << endl;

     Copiere(n, v, copie);
     cout<<"Sort:"<<endl;
     auto start = high_resolution_clock::now();
     sort(copie + 1, copie + n + 1);
     auto stop = high_resolution_clock::now();
     duration<double> secunde = stop - start;
     cout << "S-a terminat sortarea in " << secunde.count() << " secunde" << endl;


    }



     return 0;
}
