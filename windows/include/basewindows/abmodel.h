#pragma once
#include <QAbstractListModel>
#include <wbg/global.h>
class MyData {
public:

	MyData(QString a, QString b,QString c) :name(a), user(b),passwd(c){}
	QString name;
	QString user;
	QString passwd;
};

class MyListModel : public QAbstractListModel {
	Q_OBJECT

public:

	explicit MyListModel(QObject* parent = nullptr);
	static MyListModel* getInstance();
	Q_INVOKABLE void init_data();
	// Header:
	QVariant headerData(int section,
		Qt::Orientation orientation,
		int role = Qt::DisplayRole) const override;

	// Basic functionality:
	int rowCount(const QModelIndex& parent = QModelIndex()) const override;

	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
	QHash<int, QByteArray> roleNames() const override;


private:
	enum MyRoleName {
		Name = Qt::DisplayRole + 1,
		User,
		Passwd
	};
	
	QList<MyData> m_data{};
};





