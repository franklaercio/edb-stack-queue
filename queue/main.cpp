#include "queue.h"

#include <fstream>
#include <chrono>
#include <iostream>

using namespace std;

int main() {

  int instance[10] = {450, 900, 1800, 3600, 7200, 14400, 28800, 57600, 115200, 230400};

  fstream file;
  
  file.open("queue.csv", ios::out | ios::app);

  for(int i = 0; i < 10; i++){
      Queue queue = Queue(instance[i]);

      auto startEnqueue = chrono::steady_clock::now();

      for(int j = 0; j < instance[i]; j++) {
        queue.enqueue(j);
      }

      auto endEnqueue = chrono::steady_clock::now();

      auto startDequeue = chrono::steady_clock::now();

      while(!queue.isEmpty()) {
        queue.dequeue();
      }

      auto endDequeue = chrono::steady_clock::now();

      file << instance[i] << ", " 
        << chrono::duration_cast<chrono::microseconds>(endEnqueue - startEnqueue).count() << ", "
        << chrono::duration_cast<chrono::microseconds>(endDequeue - startDequeue).count() << "\n";
  }

  cout << "Success! Runtime saved." << endl;

  file.close();

  return 0;
}
