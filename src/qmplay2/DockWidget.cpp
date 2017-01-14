/*
	QMPlay2 is a video and audio player.
	Copyright (C) 2010-2017  Błażej Szczygieł

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU Lesser General Public License as published
	by the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU Lesser General Public License for more details.

	You should have received a copy of the GNU Lesser General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <DockWidget.hpp>

#if QT_VERSION >= 0x050000 && QT_VERSION < 0x050600
void DockWidget::EmptyW::showEvent(QShowEvent *) //This should fix some issues on Qt5 (QTBUG-49445)
{
	QMetaObject::invokeMethod(this, "hide", Qt::QueuedConnection);
}
#endif

QSize DockWidget::EmptyW::sizeHint() const
{
	return QSize(0, 0);
}
