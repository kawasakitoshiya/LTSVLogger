## LTSVLogger

## Sample
```
#include "ltsv_logger.h"

int main(){
  //logging without setting detail
  LTSVLogger ltsv_logger_simple;
  ltsv_logger_simple.debug("very simple message");

  //logging with setting detail
  LTSVLogger ltsv_logger;
  ltsv_logger.set("status", "in progresss").set("progress", (float)0.5).set("method", __func__);
  ltsv_logger.info();

  //logging with critical level
  ltsv_logger.set("line", __LINE__);
  ltsv_logger.critical("broken data");

  //logging with another time format
  LTSVLogger ltsv_logger_formatted(true,"%Y/%m/%d %H-%M-%S");
  ltsv_logger_formatted.set("status", "in progresss").set("progress", (float)0.5).set("method", __func__);
  ltsv_logger_formatted.info();

  //set output level
  LTSVLogger ltsv_logger_set_level;
  ltsv_logger_set_level.set_level(LTSVLogger::INFO);
  ltsv_logger_set_level.debug("this log is not printed");
}
```
The output is ...
```
time:2013-11-24 19:47:00,000    level:debug     message:very simple message
time:2013-11-24 19:15:19,000    level:info      status:in progresss     progress:0.5    method:main
time:2013-11-24 19:15:19,000    level:critical  line:14 message:broken data
time:2013/11/24 19-15-19        level:info      status:in progresss     progress:0.5    method:main
// ltsv_logger_set_level does not output log
```
