#include <iostream>
#include <math.h>
using namespace std;

void test(int num[],int size) {
  int left  = 0;
  int right = size - 1;
  int pos = size - 1;
  int num_new[size];
  while (left <= right) {
    cout<<num[left]<<" ,"<<num[right]<<endl;
    if (pow(num[left],2)>pow(num[right],2)) {
      num_new[pos--] = pow(num[left],2);
      left++;
    }
    else {
      num_new[pos--] = pow(num[right],2);
      right--;
    }
  }
  for (int i = 0; i < size; i++) {
    cout << num_new[i] << " ";
  }
  cout << endl;

}


int main(){

  int num[] = {-4,-1,0,3,10};
  test(num,5);

  int num2[] = {-7,-3,2,3,11};
  test(num2,5);

  return 0;
}