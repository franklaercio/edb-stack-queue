#include "stack.h"

#include <fstream>
#include <chrono>
#include <iostream>

using namespace std;

int main() {

  int instance[10] = {450, 900, 1800, 3600, 7200, 14400, 28800, 57600, 115200, 230400};

  fstream file;
  
  file.open("stack.csv", ios::out | ios::app);

  for(int i = 0; i < 10; i++){
      Stack stack = Stack(instance[i]);

      auto startPush = chrono::steady_clock::now();

      for(int j = 0; j < instance[i]; j++) {
        stack.push(j);
      }

      auto endPush = chrono::steady_clock::now();

      auto startPop = chrono::steady_clock::now();

      while(!stack.isEmpty()) {
        stack.pop();
      }

      auto endPop = chrono::steady_clock::now();

      file << instance[i] << ", " 
        << chrono::duration_cast<chrono::microseconds>(endPush - startPush).count() << ", "
        << chrono::duration_cast<chrono::microseconds>(endPop - startPop).count() << "\n";
  }

  cout << "Success! Runtime saved." << endl;

  file.close();

  return 0;
}

