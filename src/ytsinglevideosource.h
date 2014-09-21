/* $BEGIN_LICENSE

This file is part of Minitube.
Copyright 2009, Flavio Tordini <flavio.tordini@gmail.com>

Minitube is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Minitube is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Minitube.  If not, see <http://www.gnu.org/licenses/>.

$END_LICENSE */

#ifndef YTSINGLEVIDEOSOURCE_H
#define YTSINGLEVIDEOSOURCE_H

#include <QtNetwork>
#include "videosource.h"

class YTSingleVideoSource : public VideoSource {

    Q_OBJECT

public:
    YTSingleVideoSource(QObject *parent = 0);
    void loadVideos(int max, int skip);
    void abort();
    const QStringList & getSuggestions();
    QString getName();

    void setVideoId(QString videoId) { this->videoId = videoId; }

private slots:
    void parse(QByteArray data);
    void requestError(QNetworkReply *reply);

private:
    QString videoId;
    bool aborted;
    int skip;
    int max;
    QString name;
};

#endif // YTSINGLEVIDEOSOURCE_H