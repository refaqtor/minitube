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

#ifndef YTSTANDARDFEED_H
#define YTSTANDARDFEED_H

#include <QtNetwork>
#include "paginatedvideosource.h"

class YTStandardFeed : public PaginatedVideoSource {

    Q_OBJECT

public:
    YTStandardFeed(QObject *parent = 0);

    QString getFeedId() { return feedId; }
    void setFeedId(const QString &value) { feedId = value; }

    QString getRegionId() { return regionId; }
    void setRegionId(const QString &value) { regionId = value; }

    QString getCategory() { return category; }
    void setCategory(const QString &value) { category = value; }

    QString getLabel() { return label; }
    void setLabel(const QString &value) { label = value; }

    QString getTime() { return time; }
    void setTime(const QString &value) { time = value; }

    void loadVideos(int max, int startIndex);
    void abort();
    QString getName() { return label; }

private slots:
    void parseResults(QByteArray data);
    void requestError(const QString &message);

private:
    QString feedId;
    QString regionId;
    QString category;
    QString label;
    QString time;
    bool aborted;
};

#endif // YTSTANDARDFEED_H
