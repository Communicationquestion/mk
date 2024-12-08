#include <basewindows/abmodel.h>
#include <wbg/global.h>
MyListModel::MyListModel(QObject *parent) : QAbstractListModel(parent) {}

MyListModel *MyListModel::getInstance() {
  static MyListModel *obj = new MyListModel;
  return obj;
}

Q_INVOKABLE void MyListModel::init_data() {
  for (size_t i = 0; i < myenv->size(); i++) {
    m_data.append(
        MyData(myenv->at(i).name, myenv->at(i).user, myenv->at(i).passwd));
  }

  this->layoutChanged();
}

QVariant MyListModel::headerData(int section, Qt::Orientation orientation,
                                 int role) const {
  return QVariant();
  // FIXME: Implement me!
}

int MyListModel::rowCount(const QModelIndex &parent) const {
  // For list models only the root node (an invalid parent) should return the
  // list's size. For all other (valid) parents, rowCount() should return 0 so
  // that it does not become a tree model.
  if (parent.isValid())
    return 0;

  return m_data.count();
  // FIXME: Implement me!
}

QVariant MyListModel::data(const QModelIndex &index, int role) const {
  if (!index.isValid())
    return QVariant();
  if (role == MyRoleName::Name) {
    return m_data[index.row()].name;
  } else if (role == MyRoleName::User) {
    return m_data[index.row()].user;
  } else if (role == MyRoleName::Passwd) {
    return m_data[index.row()].passwd;
  }

  // FIXME: Implement me!
  return QVariant();
}

QHash<int, QByteArray> MyListModel::roleNames() const {
  QHash<int, QByteArray> roles;
  roles.insert(MyRoleName::Name, "name");
  roles.insert(MyRoleName::User, "user");
  roles.insert(MyRoleName::Passwd, "passwd");
  return roles;
}
