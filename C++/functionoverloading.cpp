#include<iostream>
using namespace std;
 
void fun(int const *a)
{
  cout << "non-const fun() " << a;
}
 
void fun(int *a)
{
  cout << "const fun() " << a;
}
 
 int fun2(int a){
 	return a;
 }
int main()
{
	// const int a = 5;
 //  const int *ptr = &a;
 //  fun(ptr);
  cout<<(char)fun2(2)<<endl;
  return 0;
}