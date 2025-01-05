/*Q1. Write a C program to read a 2D array (with most of the elements as 0s) and thenrepresent the same array as Sparse Metrics.

#include <stdio.h>

#define MAX 10 

struct SparseMatrix {
    int row;
    int col;
    int value;
};

void readMatrix(int matrix[MAX][MAX], int rows, int cols) {
    printf("Enter the elements of the matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

int createSparseMatrix(int matrix[MAX][MAX], struct SparseMatrix sparse[], int rows, int cols) {
    int k = 0; 

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) { 
                sparse[k].row = i;
                sparse[k].col = j;
                sparse[k].value = matrix[i][j];
                k++;
            }
        }
    }
    return k; 
}

void printSparseMatrix(struct SparseMatrix sparse[], int nonZeroCount) {
    printf("\nSparse Matrix Representation:\n");
    printf("Row\tCol\tValue\n");
    for (int i = 0; i < nonZeroCount; i++) {
        printf("%d\t%d\t%d\n", sparse[i].row, sparse[i].col, sparse[i].value);
    }
}

int main() {
    int rows, cols;
    int matrix[MAX][MAX];
    struct SparseMatrix sparse[MAX * MAX]; 

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    readMatrix(matrix, rows, cols);

    int nonZeroCount = createSparseMatrix(matrix, sparse, rows, cols);

    printSparseMatrix(sparse, nonZeroCount);

    return 0;
}*/

/*Q2. Write a C program to pass an array to a function using Call by Value, update the array
values in the function, print the array elements both in the function and in the calling
function.

#include<stdio.h>

void updateArray(int arr[],int n){
 int tempArr[n];

   for(int i=0;i<n ; i++){
      tempArr[i]=arr[i];
   }

  printf("Elements of array inside the function(after update) : ");
  for(int i=0;i<n;i++){
     tempArr[i]*=3;
     printf("%d\t",tempArr[i]);
 }
 printf("\n");

}

int main(){
   int arr[]={2,3,4,5,6};
   int n = sizeof(arr) / sizeof(arr[0]);

   printf("Original elements of array(before update) : ");
   for(int i=0 ; i<n ; i++){
      printf("%d\t",arr[i]);
   }

   printf("\n");

   updateArray(arr,n);

   printf("Original elements of array(after update) : ");
   for(int i=0 ; i<n ; i++){
      printf("%d\t",arr[i]);
   }
   printf("\n");

   return 0;

}*/

/*Q3. Write a C program to pass an array to a function using Call by Reference, update the array 
values in the function, print the array elements both in the function and in the calling function

#include <stdio.h>

#define SIZE 5

void updateArray(int arr[], int size) {
    printf("Inside updateArray function:\n");
    for (int i = 0; i < size; i++) {
        arr[i] += 10; 
        printf("arr[%d] = %d\n", i, arr[i]); 
    }
}

int main() {
    int arr[SIZE] = {1, 2, 3, 4, 5};

    printf("Original array in main:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    // Call updateArray and pass array by reference
    updateArray(arr, SIZE);

    // Print updated array in main
    printf("Updated array in main after calling updateArray:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    return 0;
}*/

/*Q4. Write a program that reads two 2D metrices from the console, verifies if metrics
multiplication is possible or not. Then multiplies the metrices and prints the 3rd metrics.*/

/*#include<stdio.h>
#define N 50
int main()
{
   int a[N][N],b[N][N],c[N][N],i,j,k,sum,m,n,p,q;

   printf("Enter the no. of rows and columns for 1st matrix:\n");
   scanf("%d %d",&m,&n);

   printf("Enter the 1st matrix:\n");
   for(i=0;i<m;i++)
   {
      for(j=0;j<n;j++){
         scanf("%d",&a[i][j]);
      }
   }
   
   printf("Enter the no. of rows and columns for 2nd matrix:\n");
   scanf("%d %d",&p,&q);

   printf("Enter the 2nd matrix:\n");
   for(i=0;i<p;i++)
   {
      for(j=0;j<q;j++){
         scanf("%d",&b[i][j]);
      }
   }

   printf("1st matrix is:\n");
   for(i=0;i<m;i++)
   {
      for(j=0;j<n;j++){
         printf("%d\t",a[i][j]);
      }
      printf("\n");
   }
   printf("2nd matrix is:\n");
   for(i=0;i<p;i++)
   {
      for(j=0;j<q;j++){
         printf("%d\t",b[i][j]);
      }
       printf("\n");
   }

   if(n!=p)
   {
      printf("Multiplication is not possible");
   }
   else{
      for(i=0;i<m;i++){
         for (j=0;j<q;j++)
         {  
            sum=0;
             for(k=0;k<n;k++)
             {
               sum=sum+(a[i][k]*b[k][j]);
             }
            c[i][j]=sum;

         }
      }
      printf("Multiplication is:\n");
      
      for(i=0;i<m;i++)
      {
        for(j=0;j<q;j++)
        {
          printf("%d\t",c[i][j]);
        }
        printf("\n");
     }

   }

}*/


//Q5. Write a program that reads a 2D metrics and checks if the metrics is a symmetric metrics or not.

/*#include <stdio.h>

#define MAX 10 

int isSymmetric(int matrix[MAX][MAX], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                return 0; 
            }
        }
    }
    return 1; 
}

int main() {
    int matrix[MAX][MAX];
    int size;

    printf("Enter the size of the matrix (n x n): ");
    scanf("%d", &size);

    
    if (size > MAX) {
        printf("Matrix size is too large.\n");
        return 1;
    }

    printf("Enter elements of the matrix (%d x %d):\n", size, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Matrix is :\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    if (isSymmetric(matrix, size)) {
        printf("\nThe matrix is symmetric.\n");
    } else {
        printf("\nThe matrix is not symmetric.\n");
    }

    return 0;
}*/

/*6. Write a program to display n number of elements. Memory should be allocated 
dynamically using malloc ( ).

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    int *arr;

 printf("Enter the size of array : ");
 scanf("%d",&n);

 arr = (int*)malloc(n*sizeof(int));
 if(arr == NULL){
    printf("Memory allocation failed.");
    return 1;
 }

 printf("Enter %d elements : " , n);
 for(int i=0;i<n ; i++){
    scanf("%d",&arr[i]);
 }

 printf("The elements are : ");
 for (int i=0;i<n;i++){
    printf("%d\t",arr[i]);
 }
 printf("\n");

 free(arr);
 
 return 0;

}*/

/*7. Write a program to display n number of elements. Memory should be allocated
dynamically using calloc( ).*/

/*#include<stdio.h>
#include<stdlib.h>

int main(){
   int n;
   int *arr;

   printf("Enter the size of array : ");
   scanf("%d",&n);

   arr=(int*)calloc(n,sizeof(int));
   if(arr == NULL){
      printf("Memory allocation failed");
      return 1;
   }

   printf("Enter %d elements : ",n);
   for(int i=0 ; i<n ; i++){
       scanf("%d",&arr[i]);
   }
   printf("The elements are : ");
   for(int i=0 ; i<n ; i++){
      printf("%d\t",arr[i]);
   }

   printf("\n");

   free(arr);
  
  return 0;


}


/*Q8. Write a program to allocate memory using malloc ( ) and then reallocate the previously
allocated memory using realloc( ). Display the elements which have been taken after
reallocation.

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int initial_size, new_size;

    // Initial memory allocation
    printf("Enter the initial number of elements: ");
    scanf("%d", &initial_size);

    arr = (int *)malloc(initial_size * sizeof(int)); // Allocate memory
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Input initial elements
    printf("Enter %d elements:\n", initial_size);
    for (int i = 0; i < initial_size; i++) {
        scanf("%d", &arr[i]);
    }

    // Display initial elements
    printf("Initial elements:\n");
    for (int i = 0; i < initial_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Reallocate memory to a larger size
    printf("Enter the new size (larger than initial size): ");
    scanf("%d", &new_size);

    arr = (int *)realloc(arr, new_size * sizeof(int)); // Reallocate memory
    if (arr == NULL) {
        printf("Memory reallocation failed.\n");
        return 1;
    }

    // Input additional elements after reallocation
    printf("Enter %d more elements:\n", new_size - initial_size);
    for (int i = initial_size; i < new_size; i++) {
        scanf("%d", &arr[i]);
    }

    // Display all elements after reallocation
    printf("Elements after reallocation:\n");
    for (int i = 0; i < new_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free allocated memory
    free(arr);

    return 0;
}
*/
/*9. Write a program to allocate memory using calloc( ) and then reallocate the previously
allocated memory using realloc( ). Display the elements which have been taken after
reallocation.

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int initial_size, new_size;

    // Initial memory allocation with calloc
    printf("Enter the initial number of elements: ");
    scanf("%d", &initial_size);

    arr = (int *)calloc(initial_size, sizeof(int)); // Allocate memory and initialize to 0
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Display initialized elements (should be zeroes)
    printf("Initial elements (after calloc initialization):\n");
    for (int i = 0; i < initial_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Input initial elements from the user
    printf("Enter %d elements:\n", initial_size);
    for (int i = 0; i < initial_size; i++) {
        scanf("%d", &arr[i]);
    }

    // Display the elements after taking input
    printf("Elements after initial input:\n");
    for (int i = 0; i < initial_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Reallocate memory to a larger size
    printf("Enter the new size (larger than initial size): ");
    scanf("%d", &new_size);

    arr = (int *)realloc(arr, new_size * sizeof(int)); // Reallocate memory
    if (arr == NULL) {
        printf("Memory reallocation failed.\n");
        return 1;
    }

    // Initialize newly allocated elements to zero (if expanding array)
    for (int i = initial_size; i < new_size; i++) {
        arr[i] = 0;
    }

    // Input additional elements after reallocation
    printf("Enter %d more elements:\n", new_size - initial_size);
    for (int i = initial_size; i < new_size; i++) {
        scanf("%d", &arr[i]);
    }

    // Display all elements after reallocation
    printf("Elements after reallocation and additional input:\n");
    for (int i = 0; i < new_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free allocated memory
    free(arr);

    return 0;
}*/


//Q10.Write a C program to search an element in an Array using dynamic memory allocation.

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,searchElement,found=0;
    int *arr;

 printf("Enter the size of array : ");
 scanf("%d",&n);

 //Dynamic Memory Allocation
 
 arr= (int*)malloc(n*sizeof(int));
 if(arr==NULL){
    printf("Memory allocation failed");
    return 1;
 }

 printf("Enter %d elements : ",n);
   for(int i=0;i<n;i++){
      scanf("%d",&arr[i]);
   }

 printf("Enter the element to be searched : ");
 scanf("%d",&searchElement);

 for(int i=0;i<n;i++){
    if(arr[i]==searchElement){
        printf("Element %d is found at position %d",searchElement,i+1);
        found =1;
        break;
    }
 }
 if(!found){
    printf("Element %d is not found in the array.",searchElement);
 }
 free (arr);

 return 0;

}

