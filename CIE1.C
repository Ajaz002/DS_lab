//Recursive binary search

#include<stdio.h>

int a[5]={20,25,30,41,55};

int search(int ele, int low, int high) {
    int mid=(high+low)/2;
    if(high>=low) {
        if(a[mid]==ele) {
            return mid;
        }
        else if(a[mid]>ele) {
            return search(ele,low,mid-1);
        }
        else {
            return search(ele,mid+1,high);
        }
    }
    else {
        return -1;
    }
}

int main() {
    int ele,flag;
    printf("Enter number\n");
    scanf("%d",&ele);
    flag=search(ele,0,4);
    if(flag==-1) {
        printf("Not found\n");
    }
    else {
        printf("Found at %d",flag+1);
    }
}