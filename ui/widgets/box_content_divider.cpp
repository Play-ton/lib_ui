// This file is part of Desktop App Toolkit,
// a set of libraries for developing nice desktop applications.
//
// For license and copyright information please follow this link:
// https://github.com/desktop-app/legal/blob/master/LEGAL
//
#include "ui/widgets/box_content_divider.h"

#include "styles/style_layers.h"

#include <QtGui/QPainter>
#include <QtGui/QtEvents>

namespace Ui {

BoxContentDivider::BoxContentDivider(QWidget *parent) : BoxContentDivider(parent, st::boxDividerHeight) {
}

BoxContentDivider::BoxContentDivider(QWidget *parent, int height)
    : RpWidget(parent), _originalHeight(height), _offset(Offset::Both) {
  resize(width(), height);
}

void BoxContentDivider::setOffset(BoxContentDivider::Offset offset) {
  int height = _originalHeight;
  if ((offset & Offset::Top) == 0) {
    height -= st::boxDividerTop.height();
  }
  if ((offset & Offset::Bottom) == 0) {
    height -= st::boxDividerBottom.height();
  }
  _offset = offset;
  resize(width(), height);
}

void BoxContentDivider::paintEvent(QPaintEvent *e) {
  QPainter p(this);
  p.fillRect(e->rect(), st::boxDividerBg);

  if (_offset & Offset::Top) {
    const auto dividerFillTop = QRect(0, 0, width(), st::boxDividerTop.height());
    st::boxDividerTop.fill(p, dividerFillTop);
  }

  if (_offset & Offset::Bottom) {
    const auto dividerFillBottom =
        myrtlrect(0, height() - st::boxDividerBottom.height(), width(), st::boxDividerBottom.height());
    st::boxDividerBottom.fill(p, dividerFillBottom);
  }
}

}  // namespace Ui
