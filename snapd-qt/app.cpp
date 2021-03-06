/*
 * Copyright (C) 2016 Canonical Ltd.
 *
 * This library is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License as published by the Free
 * Software Foundation; either version 2 or version 3 of the License.
 * See http://www.gnu.org/copyleft/lgpl.html the full text of the license.
 */

#include <snapd-glib/snapd-glib.h>

#include "Snapd/app.h"

QSnapdApp::QSnapdApp (void *snapd_object, QObject *parent) : QSnapdWrappedObject (g_object_ref (snapd_object), g_object_unref, parent) {}

QString QSnapdApp::name () const
{
    return snapd_app_get_name (SNAPD_APP (wrapped_object));
}

QStringList QSnapdApp::aliases () const
{
    gchar **discharges = snapd_app_get_aliases (SNAPD_APP (wrapped_object));
    QStringList result;
    for (int i = 0; discharges[i] != NULL; i++)
        result.append (discharges[i]);
    return result;
}

QSnapdApp::QSnapdDaemonType QSnapdApp::daemonType () const
{
    switch (snapd_app_get_daemon_type (SNAPD_APP (wrapped_object)))
    {
    case SNAPD_DAEMON_TYPE_NONE:
        return DaemonNone;
    default:
    case SNAPD_DAEMON_TYPE_UNKNOWN:
        return DaemonUnknown;
    case SNAPD_DAEMON_TYPE_SIMPLE:
        return Simple;
    case SNAPD_DAEMON_TYPE_FORKING:
        return Forking;
    case SNAPD_DAEMON_TYPE_ONESHOT:
        return Oneshot;
    case SNAPD_DAEMON_TYPE_DBUS:
        return Dbus;
    case SNAPD_DAEMON_TYPE_NOTIFY:
        return Notify;
    }
}

QString QSnapdApp::desktopFile () const
{
    return snapd_app_get_desktop_file (SNAPD_APP (wrapped_object));
}
