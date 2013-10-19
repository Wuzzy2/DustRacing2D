// This file is part of Dust Racing 2D.
// Copyright (C) 2013 Jussi Lind <jussi.lind@iki.fi>
//
// Dust Racing 2D is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// Dust Racing 2D is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Dust Racing 2D. If not, see <http://www.gnu.org/licenses/>.

#ifndef OPENALSOURCE_HPP
#define OPENALSOURCE_HPP

#include <Data>
#include <Source>

#include <AL/al.h>
#include <AL/alc.h>

#include <QMutex>

#include <string>

class OpenALSource : public STFH::Source
{
public:

    //! Constructor.
    OpenALSource(STFH::DataPtr data);

    //! Destructor.
    virtual ~OpenALSource();

    //! \reimp
    virtual void setData(STFH::DataPtr data) throw ();

    //! \reimp
    //! This is thread-safe.
    virtual void play(bool loop = false);

    //! \reimp
    //! This is thread-safe.
    virtual void stop();

    //! \reimp
    //! This is thread-safe.
    virtual void setVolume(float volume);

    //! \reimp
    //! This is thread-safe.
    virtual void setPitch(float pitch);

private:

    ALuint m_handle;
    QMutex m_mutex;
};

#endif // OPENALSOURCE_HPP
