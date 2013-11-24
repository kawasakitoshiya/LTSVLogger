/*
 * Copyright 2013 kawasakitoshiya
*/

#ifndef LTSV_LOGGER_H_
#define LTSV_LOGGER_H_

#include <map>
#include <string>
#include <vector>

typedef struct KeyValue {
  std::string key;
  std::string value;
} KeyValue;


class LTSVLogger{
public:
  LTSVLogger(bool print_time = true, std::string time_format = "%Y-%m-%d %H:%M:%S,000");
  // return this
  LTSVLogger &set(std::string key, std::string value);
  LTSVLogger &set(std::string key, int value);
  LTSVLogger &set(std::string key, float value);
  // print
  void critical();
  void error();
  void warning();
  void info();
  void debug();
private:
  std::vector<KeyValue> kvs_;
  KeyValue level_;

  const std::string time_format_;
  bool print_time_;

  // time format is <2013-11-24 13:55:55,333>
  // cannnot get miliseconds
  void set_level(std::string level);
  void clear();
  void append_time(std::stringstream &ss);
  void append_ltsv(std::stringstream &ss);
  void print_log();
};

#endif
