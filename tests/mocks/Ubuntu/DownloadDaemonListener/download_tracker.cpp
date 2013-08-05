/*
 * Copyright (C) 2013 - Canonical Ltd.
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License, as
 * published by the  Free Software Foundation; either version 2.1 or 3.0
 * of the License.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranties of
 * MERCHANTABILITY, SATISFACTORY QUALITY or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the applicable version of the GNU Lesser General Public
 * License for more details.
 *
 * You should have received a copy of both the GNU Lesser General Public
 * License along with this program. If not, see <http://www.gnu.org/licenses/>
 *
 * Authored by: Diego Sarmentero <diego.sarmentero@canonical.com>
 */


#include "download_tracker.h"

DownloadTracker::DownloadTracker(QObject *parent) :
    QObject(parent)
{
}

bool DownloadTracker::isServiceReady()
{
    return active;
}

void DownloadTracker::setDbusPath(QString& path)
{
    if(path != ""){
        this->m_dbusPath = path;
        this->startService();
    }
}

void DownloadTracker::setService(QString& service)
{
    if(service != ""){
        this->m_service = service;
        this->startService();
    }
}

void DownloadTracker::startService()
{
    if(!this->m_service.isEmpty() && !this->m_dbusPath.isEmpty()) {
        this->active = true;
    }
}
