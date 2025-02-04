#pragma once

#include "page.hpp"

class HomePage : public Page {
public:
  virtual std::shared_ptr<Page> process() override;
};
