/*
  Copyright 2017 Martin Koller, kollix@aon.at

  This file is part of liquidshell.

  liquidshell is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  liquidshell is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with liquidshell.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _Network_H_
#define _Network_H_

// network management (status display, activate, switch, ...)

#include <SysTrayItem.hxx>
#include <NetworkList.hxx>
#include <QTimer>
#include <QPixmap>

class Network : public SysTrayItem
{
  Q_OBJECT

  public:
    Network(QWidget *parent);

  protected:
    QWidget *getDetailsList() override;

  private slots:
    void checkState();

  private:
    QTimer blinkTimer;
    bool blinkState = false;
    QPixmap origPixmap;
    QPointer<NetworkList> networkList;
};

#endif
