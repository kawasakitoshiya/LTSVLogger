#include <iostream>
#include "ltsv_logger.hpp"

using namespace std;
int main(){
  LTSVLogger ltsv;
  ltsv.set("number_of_lines", 3).set("progress", (float)0.5).set("method", "run");
  ltsv.info();

}
