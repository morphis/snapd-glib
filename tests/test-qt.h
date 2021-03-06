/*
 * Copyright (C) 2017 Canonical Ltd.
 *
 * This library is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License as published by the Free
 * Software Foundation; either version 2 or version 3 of the License.
 * See http://www.gnu.org/copyleft/lgpl.html the full text of the license.
 */

#include <QtCore/QObject>
#include <Snapd/Client>
#include <glib-object.h>

class ProgressCounter: public QObject
{
    Q_OBJECT

public:
    int progressDone = 0;

public slots:
    void progress ()
    {
        progressDone++;
    }
};

class InstallProgressCounter: public QObject
{
    Q_OBJECT

public:
    InstallProgressCounter (QSnapdInstallRequest *request) : request (request) {}
    QSnapdInstallRequest *request;
    int progressDone = 0;
    QDateTime spawnTime;
    QDateTime readyTime;

public slots:
    void progress ();
};

class GetSystemInformationHandler: public QObject
{
    Q_OBJECT

public:
    GetSystemInformationHandler (GMainLoop *loop, QSnapdGetSystemInformationRequest *request) : loop (loop), request (request) {}
    GMainLoop *loop;
    QSnapdGetSystemInformationRequest *request;
    ~GetSystemInformationHandler ()
    {
        delete request;
    }

public slots:
    void onComplete ();
};

class ListHandler: public QObject
{
    Q_OBJECT

public:
    ListHandler (GMainLoop *loop, QSnapdListRequest *request) : loop (loop), request (request) {}
    GMainLoop *loop;
    QSnapdListRequest *request;
    ~ListHandler ()
    {
        delete request;
    }

public slots:
    void onComplete ();
};

class ListOneHandler: public QObject
{
    Q_OBJECT

public:
    ListOneHandler (GMainLoop *loop, QSnapdListOneRequest *request) : loop (loop), request (request) {}
    GMainLoop *loop;
    QSnapdListOneRequest *request;
    ~ListOneHandler ()
    {
        delete request;
    }

public slots:
    void onComplete ();
};

class GetIconHandler: public QObject
{
    Q_OBJECT

public:
    GetIconHandler (GMainLoop *loop, QSnapdGetIconRequest *request) : loop (loop), request (request) {}
    GMainLoop *loop;
    QSnapdGetIconRequest *request;
    ~GetIconHandler ()
    {
        delete request;
    }

public slots:
    void onComplete ();
};

class FindHandler: public QObject
{
    Q_OBJECT

public:
    FindHandler (GMainLoop *loop, QSnapdFindRequest *request) : loop (loop), request (request) {}
    GMainLoop *loop;
    QSnapdFindRequest *request;
    ~FindHandler ()
    {
        delete request;
    }

public slots:
    void onComplete ();
};
