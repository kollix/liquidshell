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

#include <DeviceNotifier.hxx>
#include <DeviceList.hxx>

#include <Solid/DeviceNotifier>

#include <QIcon>
#include <QMouseEvent>
#include <QDebug>

#include <KLocalizedString>

//--------------------------------------------------------------------------------

DeviceNotifier::DeviceNotifier(QWidget *parent)
  : SysTrayItem(parent)
{
  setPixmap(QIcon::fromTheme("device-notifier").pixmap(size()));
  setToolTip(i18n("Device Notifier"));

  deviceList = new DeviceList(this);
  deviceList->setWindowTitle(i18n("Device List"));

  if ( deviceList->isEmpty() )
    hide();

  connect(deviceList, &DeviceList::deviceWasAdded, this, &DeviceNotifier::showDetailsList);
  connect(deviceList, &DeviceList::deviceWasRemoved, this, &DeviceNotifier::checkDeviceList);
}

//--------------------------------------------------------------------------------

QWidget *DeviceNotifier::getDetailsList()
{
  deviceList->adjustSize();
  deviceList->resize(deviceList->size().expandedTo(QSize(300, 100)));
  setVisible(!deviceList->isEmpty());
  return deviceList;
}

//--------------------------------------------------------------------------------

void DeviceNotifier::checkDeviceList()
{
  if ( deviceList->isEmpty() )
  {
    deviceList->hide();
    hide();
  }
  else if ( deviceList->isVisible() )
    showDetailsList();  // reposition
}

//--------------------------------------------------------------------------------
