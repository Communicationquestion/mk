#ifndef TMODEL_H
#define TMODEL_H
#include<qlist.h>
#include<qstring.h>

#include <QAbstractListModel>

class Tmodel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit Tmodel(QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section,
                        Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

private:
    QList<QString> a;
};

#endif // TMODEL_H
