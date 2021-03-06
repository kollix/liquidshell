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

#ifndef _DiskUsageApplet_H_
#define _DiskUsageApplet_H_

#include <DesktopApplet.hxx>
#include <DiskUsageAppletConfigureDialog.hxx>
#include <QTimer>
#include <QMap>
#include <QPointer>
class QProgressBar;
class QLabel;

class DiskUsageApplet : public DesktopApplet
{
  Q_OBJECT

  public:
    DiskUsageApplet(QWidget *parent, const QString &theId);

  private Q_SLOTS:
    void fill();
    void configure();

  private:
    QTimer timer;

    struct SizeInfo
    {
      QLabel *label;
      QProgressBar *progress;
      QLabel *sizeLabel;
      bool used;
    };

    QMap<QString, SizeInfo> partitionMap;
    QPointer<DiskUsageAppletConfigureDialog> dialog;
};

#endif
