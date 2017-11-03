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

#ifndef _DesktopApplet_H_
#define _DesktopApplet_H_

#include <QFrame>
#include <QDialogButtonBox>
#include <KWindowSystem>

class DesktopApplet : public QFrame
{
  Q_OBJECT

  public:
    DesktopApplet(QWidget *parent, const QString &theId);

    virtual void loadConfig();
    virtual void saveConfig();

    bool isConfiguring() const { return buttons->isVisible(); }

    const QString &getId() const { return id; }
    int isOnDesktop(int d) const { return (onDesktop == NET::OnAllDesktops) || (onDesktop == d); }

  signals:
    void geometryChanged();
    void removeThis(DesktopApplet *);

  protected:
    QString id;

  private slots:
    void startGeometryChange();
    void finishGeometryChange(QAbstractButton *clicked);
    void removeThisApplet();

  private:
    QDialogButtonBox *buttons = nullptr;
    QRect oldRect;
    int onDesktop = NET::OnAllDesktops;
};

#endif