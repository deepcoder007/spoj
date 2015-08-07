#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
using namespace std;


struct st
{
  int a;
  int b;
};

int main()
{
  queue<st> q;
  q.push((st){ 1 ,2 } );
  q.push((st){ 10.23, 20 });

  q.pop();

  st tmp;
  tmp=q.front();
  cout<<"a : "<<tmp.a<<endl;
  cout<<"b : "<<tmp.b<<endl;
  return 0;
}

