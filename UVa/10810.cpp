#include <bits/stdc++.h>

using namespace std;
size_t merge(size_t arr[], size_t temp[], size_t left, size_t mid, size_t right)
{
  size_t i, j, k;
  size_t inv_count = 0;
 
  i = left;
  j = mid; 
  k = left;
  while ((i <= mid - 1) && (j <= right))
  {
    if (arr[i] <= arr[j])
    {
      temp[k++] = arr[i++];
    }
    else
    {
      temp[k++] = arr[j++];
      inv_count = inv_count + (mid - i);
    }
  }
 
  while (i <= mid - 1)
    temp[k++] = arr[i++];
 
  while (j <= right)
    temp[k++] = arr[j++];
 
  for (i = left; i <= right; i++)
    arr[i] = temp[i];
 
  return inv_count;
}

size_t _merge_sort(size_t arr[], size_t temp[], size_t left, size_t right)
{
  size_t mid, inv_count = 0;
  if (right > left)
  {
    mid = (right + left)/2;
    inv_count  = _merge_sort(arr, temp, left, mid);
    inv_count += _merge_sort(arr, temp, mid + 1, right);
    inv_count += merge(arr, temp, left, mid + 1, right);
  }
  return inv_count;
}
 
size_t merge_sort(size_t arr[], size_t array_size)
{
    size_t *temp = new size_t[array_size];
    return _merge_sort(arr, temp, 0, array_size - 1);
}
 
int main()
{
  unsigned int n;
  while(cin >> n and n != 0){
    size_t arr[n];
    for (size_t i = 0; i < n; ++i)
      cin >> arr[i];
    cout << merge_sort(arr, n) << "\n";
  }
  
  return 0;
}