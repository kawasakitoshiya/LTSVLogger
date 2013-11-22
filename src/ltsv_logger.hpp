#ifndef LTSV_LOGGER_H_
#define LTSV_LOGGER_H_

#include <map>

class LTSVLogger{
public:

  //return this
  LTSVLogger set(std::string key, std::string value);
  LTSVLogger set(std::string key, int value);
  LTSVLogger set(std::string key, float value);

  void info();

private:
  std::map<std::string, std::string> _string_values;
  std::map<std::string, int> _int_values;
  std::map<std::string, float> _float_values;
};

#endif
