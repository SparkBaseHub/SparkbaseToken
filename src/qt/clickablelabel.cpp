// Copyright (c) 2011-2013 The Bitcoin developers
// Copyright (c) 2017-2019 The SparkBase developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "clickablelabel.h"

#include <QLabel>

ClickableLabel::ClickableLabel(QWidget* parent) : QLabel(parent){

}

ClickableLabel::~ClickableLabel() {}

void ClickableLabel::mousePressEvent(QMouseEvent* event) {
    emit clicked();
}
