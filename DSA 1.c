//1. Write a C program to print an array.

/*#include<stdio.h>
int main(){
int i;
int arr[5]={85,78,95,88,79};
printf("Elements in array are : ");

for(i=0;i<5;i++)
{
printf("%d\t",arr[i]);
}
return 0;
}*/

//2.Write a C program to check whether a given string is Palindrome or not.

/*#include<stdio.h>
#include<string.h>

int main(){

char str1[50],str2[50];
printf("Enter the string : ");
gets(str1);

strcpy(str2,str1);  //copy str1 to str2
strrev(str2);       //reverse str2

if(strcmp(str1,str2)==0)
    printf("String is a pallindrome.");
else
    printf("String is not a pallindrome.");
}*/

/*3. Write a C program to convert temperature from degree 
Centigrade to Fahrenheit.*/

/*#include<stdio.h>

int main()
{
float celsius ,far;
printf("Enter the temperature : ");
scanf("%f",&celsius);

far = (celsius* 9.0/5.0) +32;
printf("Temperature in fahrenheit is %f",far); 
return 0;
}*/


//4. Write a C program to sort an array.

/*#include <stdio.h>

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};  // Array initialization
    int n = sizeof(arr) / sizeof(arr[0]);      // Calculate array length

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Bubble Sort algorithm
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}*/


/*5. Write a C program to print the largest and second largest 
element of the array.*/

/*#include <stdio.h>

void findLargestAndSecondLargest(int arr[], int n) {
    if (n < 2) {
        printf("Array must contain at least two elements.\n");
        return;
    }

    int largest = -2147483648; // Initialize to smallest possible integer
    int secondLargest = -2147483648;

    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }

    if (secondLargest == -2147483648) {
        printf("No second largest element found (all elements are the same).\n");
    } else {
        printf("Largest element: %d\n", largest);
        printf("Second largest element: %d\n", secondLargest);
    }
}

int main() {
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    if (n < 2) {
        printf("Array must have at least two elements.\n");
        return 0;
    }

    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    findLargestAndSecondLargest(arr, n);

    return 0;
}
*/


//6. Write a C program to display Fibonacci series.

/*#include<stdio.h>
int main(){
int n,first=0,second=1,next;

printf("Enter the number of terms : ");
scanf("%d",&n);

printf("Fibonacci series is: ");

for(int i=0;i<n;i++){
if(i<=1){
    next=i;
    }else{
    next = first + second;
    first = second;
    second = next;
   }
printf("%d\t",next);
}
printf("\n");
return 0;
}*/

//7. Write a C program to print reverse array.

/*#include<stdio.h>

void RevArray(int arr[]){
int temp;
for(int i=0;i<7/2;i++){
   temp=arr[i];
   arr[i]=arr[6-i];
   arr[6-i]=temp;
}
}
int main(){
int arr[]={78,56,99,84,83,79,90};

printf("Before reversing the array :\n ");
for(int i=0 ; i<7;i++){
   printf("The value of element %d is %d\n",i,arr[i]);
}

RevArray(arr);
printf("\nAfter reversing the array : \n");
for(int i=0 ; i<7;i++){
   printf("The value of element %d is %d\n",i,arr[i]);
}

}*/



//8. Write a C program to check the sum of all elements of an array.

/*#include<stdio.h>
int main()
{
   int arr[5],sum=0,i;
   printf("Enter the array elements : ");
   for(i=0;i<5;i++){
      scanf("%d",&arr[i]);
   }
 printf("Sum of the array elements are : ");
 for(i=0;i<5;i++)
 {
       sum+=arr[i];
  }
 printf("%d",sum);
 return 0;
}

//9. Write a C program to check duplicate number in an array.
#include<stdio.h>
int main(){
   int arr[7],i,hasDuplicate=0;
   printf("Enter the array elements : ");
   for(i=0;i<7;i++){
      scanf("%d",&arr[i]); 
 }
for (i=0;i<7;i++){
   for(int j=i+1;j<7 ;j++){
      if(arr[i] == arr[j]){
         printf("Duplicate found : %d" ,arr[i]);
         hasDuplicate=1;
         break;
      }
   }
   if(hasDuplicate){
      break;
   }
}
if(!hasDuplicate){
   printf("Duplicate not found");
}
 return 0;
}*/

//10.Write a C program to find the product of elements above the main diagonal.
/*
#include <stdio.h>

int main() {
    int arr[10][10], n, i, j;
    int product = 1;

    printf("Enter the size of the matrix: ");
    scanf("%d", &n);

    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            product *= arr[i][j];
        }
    }

    printf("\nProduct of elements above the main diagonal: %d\n", product);

    return 0;
}
*/