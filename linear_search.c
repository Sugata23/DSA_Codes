#include<stdio.h>

int main() {
 
  int arr[20], size, key, i, index;
  printf("Number of elements in the list: ");
  scanf("%d", &size);

  printf("Enter elements of the list: ");
  
  for (i = 0; i < size; i++)
    scanf("%d", &arr[i]);

  printf("Enter the element to search ie. key element: ");
  scanf("%d", &key);

  
  for (index = 0; index < size; index++)
    if (arr[index] == key) 
      break; 

  if (index < size) 
    printf("Key element found at index %d", index); 
  else
    printf("Key element not found");

  return 0;
}
