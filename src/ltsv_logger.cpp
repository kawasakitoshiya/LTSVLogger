/*
 * Copyright 2013 kawasakitoshiya
*/

#include "ltsv_logger.h"
#include <iostream>
#include <sstream>
#include <ctime>

LTSVLogger::LTSVLogger(bool print_time, std::string time_format)
  : print_time_(print_time), time_format_(time_format) {
}

void LTSVLogger::set_level(const int valid_level) {
  valid_level_ = valid_level;
}

LTSVLogger &LTSVLogger::set(std::string key, std::string value) {
  KeyValue kv = {key, value};
  kvs_.push_back(kv);
  return *this;
}

LTSVLogger &LTSVLogger::set(std::string key, int value) {
  std::stringstream tmp;
  tmp << value;
  KeyValue kv = {key, tmp.str()};
  kvs_.push_back(kv);
  return *this;
}

LTSVLogger &LTSVLogger::set(std::string key, float value) {
  std::stringstream tmp;
  tmp << value;
  KeyValue kv = {key, tmp.str()};
  kvs_.push_back(kv);
  return *this;
}

void LTSVLogger::add_level(std::string level) {
  level_.key = "level";
  level_.value = level;
}

void LTSVLogger::critical(std::string message) {
  add_level("critical");
  if (valid_level_ > CRITICAL) {
    clear();
    return;
  }
  print_log(message);
}

void LTSVLogger::error(std::string message) {
  add_level("error");
  if (valid_level_ > ERROR) {
    clear();
    return;
  }
  print_log(message);
}

void LTSVLogger::warning(std::string message) {
  add_level("warning");
  if (valid_level_ > WARNING) {
    clear();
    return;
  }
  print_log(message);
}

void LTSVLogger::info(std::string message) {
  add_level("info");
  if (valid_level_ > INFO) {
    clear();
    return;
  }
  print_log(message);
}

void LTSVLogger::debug(std::string message) {
  add_level("debug");
  if (valid_level_ > DEBUG) {
    clear();
    return;
  }
  print_log(message);
}

void LTSVLogger::print_log(std::string message) {
  std::stringstream ss;
  if (print_time_)  append_time(ss);
  ss << level_.key << ":" << level_.value << "\t";
  if (message.length() != 0) {
  ss << "message" << ":" << message << "\t"; 
  }

  append_ltsv(ss);

  std::cout << ss.str() << std::endl;

  clear();
}

void LTSVLogger::clear() {
  kvs_.clear();
}

void LTSVLogger::append_time(std::stringstream &ss) {
  time_t t;
  struct tm tm;
  char str[81];
  time(&t);

  localtime_r(&t, &tm);
  strftime(str, sizeof(str), time_format_.c_str(), &tm);
  ss << "time" << ":" << str << "\t";
}

void LTSVLogger::append_ltsv(std::stringstream &ss) {
  std::vector<KeyValue>::iterator it;
  int len = kvs_.size();
  for (int i = 0; i < len; i++) {
    ss << kvs_[i].key << ":" << kvs_[i].value << "\t";
  }
}
