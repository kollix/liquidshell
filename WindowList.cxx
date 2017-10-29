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

#include <WindowList.hxx>

#include <QIcon>
#include <QMenu>

#include <KWindowSystem>

//--------------------------------------------------------------------------------

WindowList::WindowList(QWidget *parent)
  : QPushButton(parent)
{
  setIcon(QIcon::fromTheme("arrow-up"));
  setMaximumWidth(22);
  setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Expanding);

  setMenu(new QMenu(this));
  connect(menu(), &QMenu::aboutToShow, this, &WindowList::fillMenu);
}

//--------------------------------------------------------------------------------

void WindowList::fillMenu()
{
  menu()->clear();

  QList<WId> windows = KWindowSystem::windows();

  for (int i = 1; i <= KWindowSystem::numberOfDesktops(); i++)
  {
    menu()->addSection(KWindowSystem::desktopName(i).isEmpty() ?
                       QString::number(i) : KWindowSystem::desktopName(i));

    for (WId wid : windows)
    {
      KWindowInfo win(wid, NET::WMDesktop | NET::WMWindowType | NET::WMState | NET::WMName | NET::WMIcon);
      if ( win.valid(true) && win.isOnDesktop(i) &&
          (win.windowType(NET::DesktopMask) != NET::Desktop) &&
          (win.windowType(NET::DockMask) != NET::Dock) &&
           !(win.state() & NET::SkipTaskbar) )
      {
        menu()->addAction(KWindowSystem::icon(wid, 22, 22, true), win.name(),
                          [wid]() { KWindowSystem::forceActiveWindow(wid); });
      }
    }
  }
}

//--------------------------------------------------------------------------------
