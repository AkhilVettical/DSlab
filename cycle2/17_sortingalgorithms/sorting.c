#include <stdlib.h>
#include <stdio.h>
void swap(int *a, int *b)
{
int t;
t = *a;
*a = *b;
*b = t;
}
void heapify(int arr[], int n, int i)
{
int largest = i;
int l = 2 * i + 1;
int r = 2 * i + 2;
if (l < n && arr[l] > arr[largest])
largest = l;
if (r < n && arr[r] > arr[largest])
largest = r;
if (largest != i)
{
swap(&arr[i], &arr[largest]);
heapify(arr, n, largest);
}
}
void heapSort(int arr[], int n)
{
for (int i = n / 2 - 1; i >= 0; i--)
heapify(arr, n, i);
for (int i = n - 1; i > 0; i--)
{
swap(&arr[0], &arr[i]);
heapify(arr, i, 0);
}
}
int partition(int arr[], int b, int e)
{
int pivot = arr[e];
int index = b - 1;
for (int i = b; i < e; i++)
{
if (pivot >= arr[i])
{
swap(&arr[index + 1], &arr[i]);
index++;
}
}
swap(&arr[index + 1], &arr[e]);
return (index + 1);
}
void quick_sort(int arr[], int b, int e)
{
if (b < e)
{
int p = partition(arr, b, e);
quick_sort(arr, b, p - 1);
quick_sort(arr, p + 1, e);
}
}
void merge(int arr[], int l, int m, int r)
{
int i, j, k;
int n1 = m - l + 1;
int n2 = r - m;
int L[n1], R[n2];
for (i = 0; i < n1; i++)
L[i] = arr[l + i];
for (j = 0; j < n2; j++)
R[j] = arr[m + 1 + j];
i = 0;
j = 0;
k = l;
while (i < n1 && j < n2)
{
if (L[i] <= R[j])
{
arr[k] = L[i];
i++;
}
else
{
arr[k] = R[j];
j++;
}
k++;
}
while (i < n1)
{
arr[k] = L[i];
i++;
k++;
}
while (j < n2)
{
arr[k] = R[j];
j++;
k++;
}
}
void merge_sort(int A[], int b, int e)
{
if (b >= e)
return ;
int m = (b + e) / 2;
merge_sort(A, b, m);
merge_sort(A, m + 1, e);
merge(A, b, m, e);
}
void selection_sort(int A[], int n)
{
for (int i = 0; i < n; i++)
{
int min = A[i], pos = i;
for (int j = i + 1; j < n; j++)
{
if (A[j] < min)
{
min = A[j];
pos = j;
}
}
if (min != A[i])
{
int temp = A[i];
A[i] = A[pos];
A[pos] = temp;
}
}
}
void insertion_sort(int A[], int n)
{
int j, key;
for (int i = 1; i < n; i++)
{
int key = A[i];
int j = i - 1;
while (j >= 0 && A[j] > key)
{
A[j + 1] = A[j]; --j;
}
A[j + 1] = key;
}
}

int main()
{
FILE *fptr1, *fptr2;
char file1[100], c;
fptr1 = fopen("file.txt", "r");
if (fptr1 == NULL)
{
printf("Cannot open file %s \n", file1);
return (0);
}
int num[50], i = 0;
char x[5];
int k = 0;
while ((c = fgetc(fptr1)) != EOF)
{
if (c != '\n')
{
x[k] = c;
k++;
}
else
{
x[k] = '\0';
num[i] = atoi(x);
i++;
k = 0;
}
}
x[k] = '\0';
num[i] = atoi(x);
printf("\nContents:\n");
for (int j = 0; j <= i; j++)
{
printf("%d ", num[j]);
}
fclose(fptr1);
int choice;
printf("\n1.Insertion sort\n2.Selection sort\n3.Merge sort\n4.Quick sort\n5.Heap sort\n6.Exit\n");
do{
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
switch (choice)
{
case 1:
printf("After Insertion sort: ");
insertion_sort(num, i + 1);
break;
case 2:
printf("After Selection sort: ");
selection_sort(num, i + 1);
break;
case 3:
printf("After Merge sort: ");
merge_sort(num, 0, i);
break;
case 4:
printf("After Quick sort: ");
quick_sort(num, 0, i);
break;
case 5:
printf("After Heap sort: ");
heapSort(num, i + 1);
break;
case 6: return 0;
default:
printf("Invalid choice\n");
break;
}
for (int j = 0; j <= i; j++)
{
printf("%d ", num[j]);
}
}while(choice!=6);
}
