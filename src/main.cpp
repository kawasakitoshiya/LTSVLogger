#include <iostream>
#include "ltsv_logger.hpp"

using namespace std;
int main(){
  LTSVLogger ltsv;
  ltsv.set("number_of_lines", 3);
  ltsv.set("progress", (float)0.5);
  ltsv.set("method", "run");

  ltsv.info();
  ltsv.info();

}
