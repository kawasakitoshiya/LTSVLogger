/*
 * Copyright 2013 kawasakitoshiya
*/

#include <iostream>
#include "ltsv_logger.h"

using namespace std;
int main(){
  LTSVLogger ltsv_logger_simple;
  ltsv_logger_simple.debug("very simple message");

  LTSVLogger ltsv_logger;
  ltsv_logger.set("status", "in progresss").set("progress", (float)0.5).set("method", __func__);
  ltsv_logger.info();

  ltsv_logger.set("line", __LINE__).set("message", "broken data");
  ltsv_logger.critical();

  LTSVLogger ltsv_logger_formatted(true,"%Y/%m/%d %H-%M-%S");
  ltsv_logger_formatted.set("status", "in progresss").set("progress", (float)0.5).set("method", __func__);
  ltsv_logger_formatted.info();
}
