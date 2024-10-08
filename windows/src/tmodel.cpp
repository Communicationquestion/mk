#include<basewindows/tmodel.h>

Tmodel::Tmodel(QObject *parent)
    : QAbstractListModel(parent)
{}

QVariant Tmodel::headerData(int section, Qt::Orientation orientation, int role) const
{
    return QVariant();
    // FIXME: Implement me!
}

int Tmodel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;
    return 0;

    // FIXME: Implement me!
}

QVariant Tmodel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
 
    // FIXME: Implement me!
    return QVariant();
}

QHash<int, QByteArray> Tmodel::roleNames() const {

    return QHash<int, QByteArray>();
}
