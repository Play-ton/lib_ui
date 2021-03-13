// This file is part of Desktop App Toolkit,
// a set of libraries for developing nice desktop applications.
//
// For license and copyright information please follow this link:
// https://github.com/desktop-app/legal/blob/master/LEGAL
//
#pragma once

#include "ui/rp_widget.h"

namespace Ui {

class BoxContentDivider : public Ui::RpWidget {
 public:
  enum Offset {
    Top = 0b01,
    Bottom = 0b10,
    Both = Top | Bottom,
  };

  BoxContentDivider(QWidget *parent);
  BoxContentDivider(QWidget *parent, int height);

  void setOffset(Offset offset);

 protected:
  void paintEvent(QPaintEvent *e) override;

  int _originalHeight;
  Offset _offset;
};

}  // namespace Ui
