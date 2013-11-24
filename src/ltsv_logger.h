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
  enum {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    CRITICAL
  };

  LTSVLogger(bool print_time = true, std::string time_format = "%Y-%m-%d %H:%M:%S,000");
  // return this
  LTSVLogger &set(std::string key, std::string value);
  LTSVLogger &set(std::string key, int value);
  LTSVLogger &set(std::string key, float value);
  // set printing level
  void set_level(const int valid_level);

  // print
  void critical(std::string message = "");
  void error(std::string message = "");
  void warning(std::string message = "");
  void info(std::string message = "");
  void debug(std::string message = "");
private:
  std::vector<KeyValue> kvs_;
  KeyValue level_;
  int valid_level_;

  const std::string time_format_;
  bool print_time_;

  // time format is <2013-11-24 13:55:55,333>
  // cannnot get miliseconds
  void add_level(std::string level);
  void clear();
  void append_time(std::stringstream &ss);
  void append_ltsv(std::stringstream &ss);
  void print_log(std::string message);
};

#endif
