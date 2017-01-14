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

#include <QMPlay2OSD.hpp>

#include <QCryptographicHash>

void QMPlay2OSD::genChecksum()
{
	QCryptographicHash hash(QCryptographicHash::Md4);
	foreach (const Image &img, m_images)
		hash.addData(img.data);
	m_checksum = hash.result();
}

void QMPlay2OSD::clear(bool all)
{
	m_images.clear();
	m_text.clear();
	if (all)
		m_pts = m_duration = -1.0;
	m_needsRescale = m_started = false;
	m_checksum.clear();
}

void QMPlay2OSD::start()
{
	m_started = true;
	if (m_pts == -1.0)
		m_timer.start();
}
double QMPlay2OSD::leftDuration()
{
	if (!m_started || m_pts != -1.0)
		return 0.0;
	return m_duration - m_timer.elapsed() / 1000.0;
}
