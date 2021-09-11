#include <stdio.h>
#include <stdlib.h>

void Insertion_sort(int a[], int n) {
    int temp, j;
    for(int i = 1; i < n ; i++) {
        j = i-1;
        temp = a[i];
        while(a[j] > temp && j > -1) {
            a[j+1] = a[j];
            j--;   
        }
        a[j+1] = temp;
    }
}

void Selection_sort(int a[], int n) {
    int min = 0, temp;
    for (int i = 0; i < n ; i++) {
        min = i;
        for (int j = i+1; j < n; j++) {
            if(a[j] < a[min]) {
                min = j;
            }
        }
        temp = a[min];
        a[min] = a[i];
        a[i] = temp;
    }
}

void Bubble_sort(int a[], int n) {
    int flag = 0;
    for (int i = 0; i< n-1; i++) {
        flag = 0;

        for (int j = 0; j < (n - i - 1); j++ ) {

            if (a[j] > a[j+1]) {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                flag++; 
            }

        }

        if (flag == 0) break;
    }
}


void Merge_sort(int p[], int l, int u) {
    if(l<u) {
        int m = (l+u)/2;
        Merge_sort(p, l, m);
        Merge_sort(p, m+1, u);

        int k = 0, i = l, j = m+1;
        int *temp = (int*)malloc(sizeof(int)*(u-l+1));

        while(i <=m && j <= u) {

            if(p[i]>p[j])   temp[k++] = p[j++];
            else    temp[k++] = p[i++];
        }

        while(i <= m)   temp[k++] = p[i++];
        while(j <= u)   temp[k++] = p[j++];
        
        i = 0;
        while(1) {
            p[i + l] = temp[i++];

            if(i==k)    break;
        }
        free(temp);

    }
    
}

int partition(int p[], int start, int end) {
    int l = start;
    int u = end;
    int pv = start;
    int temp;

    while(1) {
        while(p[l] <= p[pv] && l < end) l++;
        while(p[u] > p[pv]) u--;

        if(u > l) {
            temp = p[u];
            p[u] = p[l];
            p[l] = temp;
        } else  break;
    }

    temp = p[pv];
    p[pv] = p[u];
    p[u] = temp;

    return u;
    
}

void Quick_sort(int *p, int l, int u) {
    if (l < u) {
        int pos = partition(p, l, u);
        Quick_sort(p, l, pos-1);
        Quick_sort(p, pos+1, u);
    }
}

void max_heapify(int a[], int i, int n) {

    int rchild = 2*i+2, lchild = 2*i+1, max = i;

    if(lchild < n && a[lchild] > a[max])    max = lchild;
    if(rchild < n && a[rchild] > a[max])    max = rchild;

    if(max != i) {
        int temp = a[max];
        a[max] = a[i];
        a[i] = temp;
        max_heapify(a, max, n);
    }

}


void Heap_sort(int a[], int n) {
  
    for(int i = n/2 - 1; i >= 0 ; i--)      max_heapify(a, i, n);

    n--;
    while(n > 0) {
        int temp = a[0];
        a[0] = a[n];
        a[n] = temp;
        max_heapify(a, 0 , n--);
    }

}