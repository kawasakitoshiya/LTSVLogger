## LTSVLogger

## Sample
```
#include "ltsv_logger.hpp"

int main(){
  ltsv_logger.set("status", "in progresss").set("progress", (float)0.5).set("method", __func__);
  ltsv_logger.info();

  ltsv_logger.set("message", "broken data");
  ltsv_logger.critical();

  LTSVLogger ltsv_logger_formatted(true, "%Y/%m/%d %H-%M-%S");
  ltsv_logger_formatted.set("status", "in progresss").set("progress", (float)0.5).set("method", __func__);
  ltsv_logger_formatted.info();
}
```
The output is ...
```
time:2013-11-24 18:07:47,000    level:info      method:main     status:in progresss     progress:0.5
time:2013-11-24 18:07:47,000    level:critical  message:broken data
time:2013/11/24 18-07-47        level:info      method:main     status:in progresss     progress:0.5
```
