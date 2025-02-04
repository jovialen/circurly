#pragma once

#include <memory>

class Page {
public:
  virtual ~Page() = default;

  virtual std::shared_ptr<Page> process() = 0;
};
