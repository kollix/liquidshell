/*
  Copyright 2017 Martin Koller

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

#ifndef DESKTOP_WIDGET_H
#define DESKTOP_WIDGET_H

#include <QWidget>
#include <QPixmap>
#include <QVector>
class DesktopPanel;

class DesktopWidget : public QWidget
{
  Q_OBJECT

  public:
    DesktopWidget();

    struct Wallpaper
    {
      QString fileName, mode;
      QColor color;
      QPixmap pixmap;
    };

  protected:
    virtual void paintEvent(QPaintEvent *event);

  private slots:
    void loadSettings();
    void placePanel();
    void desktopChanged();
    void configureWallpaper();
    void configureDisplay();

  private:
    DesktopPanel *panel;

    QVector<Wallpaper> wallpapers;
    int currentDesktop = -1;
};

#endif
