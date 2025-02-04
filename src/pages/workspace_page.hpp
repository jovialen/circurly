#pragma once

#include <string>

#include "page.hpp"

class WorkspacePage : public Page {
public:
  WorkspacePage(const std::string &name);

  virtual void process() override;

private:
  std::string m_name;
};

