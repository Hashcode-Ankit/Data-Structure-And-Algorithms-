#include <iostream>
using namespace std;
void swap(int *a,int *b)
{
    int c=*a;
    *a=*b;
    *b=c;
}
int partition(int arr[],int l,int r)
{
    int pivot=arr[r];
    int p=l;
    for(int i=l;i<r;i++)
    {
        if(arr[i]<=pivot)
        {
            swap(&arr[i],&arr[p]);
            p++;
        }
    }
    swap(&arr[r],&arr[p]);
    return p;

}  
void quickSort(int arr[],int l,int r)
{
    if(l<r)
    {
        int p=partition(arr,l,r);
        quickSort(arr,l,p-1);
        quickSort(arr,p+1,r);
    }
}
 
void printArray(int arr[], int size)  
{  
    int i;  
    for (i = 0; i < size; i++)  
        cout << arr[i] << " ";  
    cout << endl;  
}  
int main()  
{  
    int arr[] = {10, 7, 8, 9, 1, 5};  
    int n = sizeof(arr) / sizeof(arr[0]);  
    quickSort(arr, 0, n - 1);  
    cout << "Sorted array: \n";  
    printArray(arr, n);  
    return 0;  
}  