#include <iostream>
using namespace std;

class Thing {
  int x;
  int* y ;
public:
  // Constructor
  Thing(int a, int b) {
    x=a ;
    y= new int;
    *y= b ;
    cout<<"In the constructor, We Construct\n" ;
  }
  //Destructor
  ~Thing() { delete y ;}
};
void what(Thing ob) {

  cout<<"In what(), it sounds strange"<<endl ;

}

Thing why() {

  Thing o(10, 9) ;

  cout<<"In why(), we return  an instance of Thing"<<endl ;

  return(o) ;

}



int main() {

  Thing a(2,5), b(10,12), c(6,9);

  Thing d = a ;

  Thing e = Thing(b) ;

  Thing f(c) ;



  what(a) ;

  Thing g = why() ;

}
