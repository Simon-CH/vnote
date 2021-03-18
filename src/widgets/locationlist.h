#ifndef LOCATIONLIST_H
#define LOCATIONLIST_H

#include <QFrame>
#include <QScopedPointer>
#include <QSharedPointer>

#include <core/location.h>

#include "navigationmodewrapper.h"

namespace vnotex
{
    class TitleBar;

    class LocationList : public QFrame
    {
        Q_OBJECT
    public:
        explicit LocationList(QWidget *p_parent = nullptr);

        NavigationModeWrapper<QTreeWidget, QTreeWidgetItem> *getNavigationModeWrapper();

        void clear();

        void addLocation(const Location &p_location, const QString &p_text, const QString &p_note);

    private:
        enum Columns
        {
            PathColumn = 0,
            LineColumn,
            TextColumn,
            NoteColumn
        };

        void setupUI();

        TitleBar *setupTitleBar(const QString &p_title, QWidget *p_parent = nullptr);

        QTreeWidget *m_tree = nullptr;

        QScopedPointer<NavigationModeWrapper<QTreeWidget, QTreeWidgetItem>> m_navigationWrapper;
    };
}

#endif // LOCATIONLIST_H
