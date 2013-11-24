## LTSVLogger

## Sample
```
#include "ltsv_logger.h"

int main(){
  LTSVLogger ltsv_logger;
  ltsv_logger.set("status", "in progresss").set("progress", (float)0.5).set("method", __func__);
  ltsv_logger.info();

  ltsv_logger.set("line", __LINE__).set("message", "broken data");
  ltsv_logger.critical();

  LTSVLogger ltsv_logger_formatted(true,"%Y/%m/%d %H-%M-%S");
  ltsv_logger_formatted.set("status", "in progresss").set("progress", (float)0.5).set("method", __func__);
  ltsv_logger_formatted.info();
}
```
The output is ...
```
time:2013-11-24 19:15:19,000    level:info      status:in progresss     progress:0.5    method:main
time:2013-11-24 19:15:19,000    level:critical  line:14 message:broken data
time:2013/11/24 19-15-19        level:info      status:in progresss     progress:0.5    method:main
```
