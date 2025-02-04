#pragma once

#include "page.hpp"

enum class StartPageState {
  Init,
  New,
  Load,
};

class StartPage : public Page {
public:
  virtual void process() override;

  void init();
  void new_workspace();
  void load_workspace();

private:
  StartPageState m_state;
};
