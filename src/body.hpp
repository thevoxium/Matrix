#pragma once
#include <any>
#include <string>
#include <unordered_map>

struct Body {
  std::unordered_map<std::string, std::any> properties;

  template <typename T>
  void set_property(const std::string &name, const T &value) {
    properties[name] = value;
  }

  template <typename T> T get(const std::string &name) const {
    return std::any_cast<T>(properties.at(name));
  }

  bool has(const std::string &name) const {
    return properties.find(name) != properties.end();
  }
};
