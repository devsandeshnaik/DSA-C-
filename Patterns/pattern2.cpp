#include <iostream>
using namespace std;
/*===========
    *
    * *
    * * *
    * * * *
    * * * * *
============= */
void starPattern(int n) {
    for(int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

/*===========
    1
    1 2
    1 2 3
    1 2 3 4
    1 2 3 4 5
============= */
void numPattern(int n) {
    for(int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
}

/*===========
    1 2 3 4 5
    1 2 3 4
    1 2 3
    1 2
    1
============= */
void revNumPattern(int n) {
    for(int i = 0; i <= n; i++) {
        for (int j = 1; j <= n-i; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
}

/*===========
         1
       1 2 
     1 2 3
   1 2 3 4
 1 2 3 4 5    
============= */
void righAlignNumbers(int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n-i; j++) {
            cout << "  ";
        }

        for(int k= 1; k <= n-(n-i); k++ ) {
            cout << k << " ";
        }
        cout << endl;
    }
}

/*================
         1
       1 2 1
     1 2 3 2 1
   1 2 3 4 3 2 1
 1 2 3 4 5 4 3 2 1   
=================== */

void numTriangle() {

}
int  main() {
   
    // starPattern(7);
    // numPattern(7);
    // revNumPattern(7);
   righAlignNumbers(7);
}


