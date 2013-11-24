## LTSVLogger

## Sample
```
#include "ltsv_logger.hpp"

int main(){

  LTSVLogger ltsv_logger;
  ltsv_logger.set("status", "in progresss").set("progress", (float)0.5).set("method", __func__);
  ltsv_logger.info();
}
>>time:2013-11-24 17:00:46,000    method:main     status:in progresss     progress:0.5

```
