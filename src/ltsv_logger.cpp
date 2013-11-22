#include "ltsv_logger.hpp"
#include <iostream>
#include <sstream>

LTSVLogger LTSVLogger::set(std::string key, std::string value)
{
  _string_values[key] = value;
  return *this;
};

LTSVLogger LTSVLogger::set(std::string key, int value)
{
  _int_values[key] = value;
  return *this;
};

LTSVLogger LTSVLogger::set(std::string key, float value)
{
  _float_values[key] = value;
  return *this;
};

void LTSVLogger::info(){

  std::stringstream ss;

  std::map<std::string, std::string>::iterator it_str = _string_values.begin();
  while( it_str != _string_values.end() )
    {
      ss << (*it_str).first << ":" << (*it_str).second << "\t";
      ++it_str;
    }

  std::map<std::string, int>::iterator it_int = _int_values.begin();
  while( it_int != _int_values.end() )
    {
      ss << (*it_int).first << ":" << (*it_int).second << "\t";
      ++it_int;
    }

  std::map<std::string, float>::iterator it_float = _float_values.begin();
  while( it_float != _float_values.end() )
    {
      ss << (*it_float).first << ":" << (*it_float).second << "\t";
      ++it_float;
    }
  std::cout << ss.str() << std::endl;

  _string_values.clear();
  _int_values.clear();
  _float_values.clear();

};


